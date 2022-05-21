# university-db

Hi! 👋

This is a work-in-progress project for the online C++ course by [Coders-School](coders.school).
It's main focus is learning the basics of OOP as well as managing and working with simple projects.

It allows user to manage a simple database (containing names, addresses etc.) of students by:
* ➕ adding new records 
* ☠️ deleting existing ones 
* 📨 sorting the records by last name or PESEL 
* 🔎 querying the records by last name or PESEL

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

The database will be **empty** on launch. The user has to either:
* generate a new set of data by pressing `[2] Add/generate new record` -> `[3] Generate N random records`
* add new records by hand by pressing `[2] Add/generate new record` -> `[1] Manually add new record`

---

📂 **Files structure:** 
* menu - handles main menu logic
* database - handles operations on records (adding, modifying etc.)
* record - defines basic record classes 
* generator - allows user to add new records with randomly generated data 

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
