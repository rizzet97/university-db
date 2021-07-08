# university-db

Hi! 👋

This is a work-in-progress project for the online C++ course by [Coders-School](coders.school).
It's main focus is learning the basics of OOP as well as managing and working with simple projects.

It will eventually allow user to manage a simple database containing names, addresses etc. of students by:
* ➕ adding new records 
* ☠️ deleting existing ones 
* 📨 sorting the records by last name or PESEL 
* 🔎 querying the records by last name or PESEL

...but it doesn't do *most* of those things (yet!). 💤

Currently only the basic class which will be used for storing data has been implemented. 🚧 👷 🏗️
As of now I don't plan on adding automated tests, but this may change in the future.

---

💚 **Implemented:** 
* Add new student records to database
* Print student record by index number
* Print all student records

🧡 **To-do:**
* Main menu
* Print student record by PESEL
* Remove student record by PESEL
* Remove student record by index number
* Sort by PESEL
* Sort by index number

📂 **Files structure:** 
* menu - handles main menu logic
* printing - handles printing info in terminal
* record - defines basic record class 
* storage - handles adding and removing new records 
