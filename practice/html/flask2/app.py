from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/")
def index():
    name = request.args.get("name","world")
    return render_template ("index.html")

@app.route("/greet", methods=["GET","POST"])
def greet():
    if request.method=="POST":
        return render_template ("index.html", name=request.form.get("name"))
    return render_templated("index.html")
