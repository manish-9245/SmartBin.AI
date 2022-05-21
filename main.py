from flask import Flask,render_template

app = Flask(__name__)

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