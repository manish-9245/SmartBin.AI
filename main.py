from flask import Flask,render_template,render_template
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app = Flask(__name__)
app.config["SECRET_KEY"] = "gfhfghfghfg"
app.config["SQLALCHEMY_DATABASE_URI"] = "sqlite:///data.db"
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False
db = SQLAlchemy(app)

class Users(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    text = db.Column(db.String(300), nullable=False)
    date_created = db.Column(db.DateTime, default=datetime.utcnow)

    def __repr__(self) -> str:
        return f"Text:{self.id}"

@app.route('/')
def index():
   return render_template("index.html")

@app.route('/analytics')
def analytics():
   return render_template("analytics.html")

@app.route('/recom')
def recom():
   return render_template("recommendation.html")

if __name__ == '__main__':
   app.run(debug = True)