from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_bcrypt import Bcrypt

# Configurando aplicação
app = Flask(__name__)

# Configurando SQLAlchemy
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///finance.db"
app.config["SECRET_KEY"] = "a3190c71717b80582c2b580d8bc02528"
database = SQLAlchemy(app)

# Configurando Bcrypt
bcrypt = Bcrypt(app)