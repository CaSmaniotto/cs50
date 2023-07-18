from config import app, database
from flask_login import UserMixin, current_user
from datetime import datetime

class User(database.Model, UserMixin):
    id = database.Column(database.Integer, primary_key=True)
    username = database.Column(database.String, nullable=False, unique=True)
    hash = database.Column(database.String, nullable=False)
    cash = database.Column(database.Float, nullable=False, default=10000)
    transactions = database.relationship("Transaction", backref="user", lazy=True)

    def __repr__(self):
        return self.username

class Transaction(database.Model):
    id = database.Column(database.Integer, primary_key=True)
    symbol = database.Column(database.String, nullable=False)
    shares = database.Column(database.Integer, nullable=False)
    price = database.Column(database.Float, nullable=False)
    date = database.Column(database.DateTime, nullable=False, default=datetime.utcnow())
    id_user = database.Column(database.Integer, database.ForeignKey('user.id'), nullable=False)

    def __repr__(self):
        return self.symbol