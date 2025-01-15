# file: routes.py
from app import app

@app.route('/')
@app.route('/index')
def index():
    return """
<h1>Nathan Cochran</h1>
<img src="" alt="Cool Prophet Image" />

<p>What's your name?</p>
<form>
What's your name? <input type='text' name='fullname'/> <br>
<input type='submit' value='Go'/>
</form>
"""


@app.route("/hello")
def hello():
    return """
<h1>Nathan Cochran</h1>
<img src="" alt="Cool Prophet Image" />
"""
