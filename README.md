# university-db

Hi! 👋

This is a work-in-progress project for the online C++ course by [Coders-School](coders.school).
It's main focus is learning the basics of OOP as well as managing and working with simple projects.

It allows user to manage a simple database (containing names, addresses etc.) of students by:
* ➕ adding new records 
* ☠️ deleting existing ones 
* 📨 sorting the records by last name or PESEL 
* 🔎 querying the records by last name or PESEL

As of now I don't plan on adding automated tests, but this may change in the future.

---

**Following project uses CMake.**
In order to build it open terminal, go to project directory and type:
```
mkdir build
cd build
cmake ..
make
```
Program will be created as: `university-db`

---

📂 **Files structure:** 
* menu - handles main menu logic
* printing - handles printing info in terminal
* record - defines basic record class 
* storage - handles adding and removing new records 

---

💚 **Implemented:** 
* Add new student records to database
* Print student record by index number
* Print all student records
* Sort by PESEL
* Sort by last name
* Search by PESEL
* Search by last name
* Main menu
* Remove student record by PESEL
* Remove student record by index number
* Store university employee data in the same vector as students
* Generate dummy data
* Modify earnings by PESEL 
* Sort by earnings
* add .github/workflows/main.yml
