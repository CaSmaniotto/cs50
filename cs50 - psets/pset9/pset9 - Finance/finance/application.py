import os

# from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from flask_sqlalchemy import SQLAlchemy

# from flask_login import UserMixin, current_user

from models import User, Transaction
from config import app, database, bcrypt
from sqlalchemy import desc, distinct, func

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Criando database
with app.app_context():
    database.create_all()

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user = User.query.filter_by(id=session["user_id"]).first()

    transactions = (
        Transaction.query.filter_by(id_user=session["user_id"])
        .group_by(Transaction.symbol)
        .all()
    )

    balance = {}
    total_sum = 0.0

    for transaction in transactions:
        check = (
            database.session.query(func.sum(Transaction.shares))
            .filter(
                Transaction.id_user == session["user_id"],
                Transaction.symbol == transaction.symbol,
            )
            .scalar()
        )
        print(transaction, check)
        quote = lookup(transaction.symbol)
        check = check if check is not None else 0
        total_sum = total_sum + (quote["price"] * check)

        if check > 0:
            data = {
                "symbol": transaction.symbol,
                "shares": check,
                "price": quote["price"],
                "total": quote["price"] * check,
            }
            balance[transaction.symbol] = data

    return render_template(
        "portfolio.html", user=user, balance=balance, total_sum=total_sum
    )


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").lower()
        shares = request.form.get("shares")
        quote = lookup(symbol.strip())

        user = User.query.filter_by(id=session["user_id"]).first()
        if user.cash > (float(shares) * quote["price"]):
            transaction = Transaction(
                symbol=symbol,
                shares=shares,
                price=quote["price"],
                id_user=session["user_id"],
            )
            user.cash = user.cash - (float(shares) * quote["price"])

            database.session.add(user)
            database.session.add(transaction)
            database.session.commit()

            flash("bought!")

            return redirect("/")
        else:
            return apology("exceed the balance")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    transactions = (
        Transaction.query.filter_by(id_user=session["user_id"])
        .order_by(Transaction.date.desc())
        .all()
    )

    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        user = User.query.filter_by(username=request.form.get("username").lower()).first()
        if user and bcrypt.check_password_hash(user.hash, request.form.get("password")):
            session["user_id"] = user.id
            flash("successfully logged in")

            return redirect("/")
        else:
            return apology("username or password incorrect", 403)

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol").lower()
        quote = lookup(symbol.strip())

        if not quote:
            return apology("invalid symbol")

        return render_template("quote.html", quote=quote)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    queryUser = User.query.filter_by(username=request.form.get("username")).first()

    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        elif queryUser:
            return apology("Username already taken!", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        elif not request.form.get("password_again"):
            return apology("must provide password", 403)

        elif not (request.form.get("password") == request.form.get("password_again")):
            return apology("different passwords")

        username = request.form.get("username").lower()
        pswd = request.form.get("password")
        password = bcrypt.generate_password_hash(pswd).decode("utf-8")

        user = User(username=username, hash=password, cash=10000)

        database.session.add(user)
        database.session.commit()

        flash("registered with success")
        return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    transactions = (
        Transaction.query.filter_by(id_user=session["user_id"])
        .group_by(Transaction.symbol)
        .all()
    )

    if request.method == "POST":
        shares = request.form.get("shares")
        symbol = request.form.get("symbol").lower()

        # check = Transaction.query.filter(Transaction.id_user==session["user_id"], Transaction.symbol == symbol).all()
        # check = check if check is not None else 0

        check = (
            database.session.query(func.sum(Transaction.shares))
            .filter(
                Transaction.id_user == session["user_id"], Transaction.symbol == symbol
            )
            .scalar()
        )
        check = check if check is not None else 0

        # sum = 0
        # for c in check:
        #    sum += c.shares

        if (check - 1) >= 0:
            quote = lookup(symbol.strip())
            shares = -abs(int(shares))

            transaction = Transaction(
                symbol=symbol,
                shares=shares,
                price=quote["price"],
                id_user=session["user_id"],
            )
            user = User.query.filter_by(id=session["user_id"]).first()
            user.cash = user.cash + (float(request.form.get("shares")) * quote["price"])

            database.session.add(user)
            database.session.add(transaction)
            database.session.commit()

            flash("Sold!")
            return redirect("/")
        else:
            return apology("too many shares!")

    return render_template("sell.html", transactions=transactions)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
