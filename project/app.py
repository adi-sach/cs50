from flask import Flask, render_template, request, redirect
import sqlite3
import calendar
from datetime import date, datetime

app = Flask(__name__)

DATABASE = "habits.db"


def get_db():
    """Connect to the SQLite database."""
    conn = sqlite3.connect(DATABASE)
    conn.row_factory = sqlite3.Row
    return conn

def get_month_days(year, month):
    """Return a list of day numbers for the given month."""
    _, num_days = calendar.monthrange(year, month)
    return list(range(1, num_days + 1))

@app.route("/")
def index():
    today = date.today()
    year = today.year
    month = today.month
    today_day = today.day

    days = get_month_days(year, month)

    db = get_db()
    cursor = db.cursor()

    # Fetch all habits
    cursor.execute("SELECT id, name FROM habits")
    habits = cursor.fetchall()

    # Fetch all logs for the current month
    cursor.execute("""
        SELECT habit_id, date, completed
        FROM habit_logs
        WHERE strftime('%Y', date) = ?
          AND strftime('%m', date) = ?
    """, (str(year), f"{month:02d}"))

    logs = cursor.fetchall()
    db.close()

    # Build habit-wise data structure
    habit_data = {}

    for habit in habits:
        habit_data[habit["id"]] = {
            "name": habit["name"],
            "logs": {}
        }

    for log in logs:
        day = int(log["date"].split("-")[2])
        habit_data[log["habit_id"]]["logs"][day] = log["completed"]

     print(habit_data)


    return render_template(
        "index.html",
        habit_data=habit_data,
        days=days,
        today_day=today_day,
        username="Adi",
        month=today.strftime("%B"),
        year=year
    )


@app.route("/add", methods=["POST"])
def add():
    habit_name = request.form.get("habit")

    if not habit_name:
        return redirect("/")

    db = get_db()
    cursor = db.cursor()

    cursor.execute(
        "INSERT INTO habits (name, created_at) VALUES (?, ?)",
        (habit_name, date.today().isoformat())
    )

    db.commit()
    db.close()

    return redirect("/")


@app.route("/toggle", methods=["POST"])
def toggle():
    habit_id = request.form.get("habit_id")
    today = date.today().isoformat()

    db = get_db()
    cursor = db.cursor()

    # Check if log already exists
    cursor.execute(
        "SELECT completed FROM habit_logs WHERE habit_id = ? AND date = ?",
        (habit_id, today)
    )
    log = cursor.fetchone()

    if log is None:
        # Create new log and mark as completed
        cursor.execute(
            "INSERT INTO habit_logs (habit_id, date, completed) VALUES (?, ?, 1)",
            (habit_id, today)
        )
    else:
        # Toggle completion
        new_status = 0 if log["completed"] == 1 else 1
        cursor.execute(
            "UPDATE habit_logs SET completed = ? WHERE habit_id = ? AND date = ?",
            (new_status, habit_id, today)
        )

    db.commit()
    db.close()

    return redirect("/")

if __name__ == "__main__":
    app.run(debug=True)
