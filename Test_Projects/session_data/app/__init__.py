# app/__init__.py
from flask import Flask
from flask_debugtoolbar import DebugToolbarExtension

# Initialize the Flask app
app = Flask(__name__)

# Set a secret key for sessions
app.config['SECRET_KEY'] = 'SOME_RANDOM_SECRET_KEY'

# Initialize the DebugToolbar
toolbar = DebugToolbarExtension(app)

# Import routes after initializing app
from app import routes
