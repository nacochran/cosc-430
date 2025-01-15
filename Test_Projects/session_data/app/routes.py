# app/routes.py
from flask import render_template
from app import app

@app.route('/')
def index():
    names = ['Hunter', 'Cole', 'Ryan']
    return render_template('index.html', user='John', names=names)
