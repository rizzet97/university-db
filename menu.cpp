#include "menu.hpp"

extern std::vector<Record> studentBase;
extern bool mainLoopKill;

char getMenuInput() {
    char input;
    std::cin >> input;
    return input;
}

unsigned int getUserIndexNr() {
    unsigned int indexNr;
    std::cout << "Input index number (6 digits): ";
    std::cin >> indexNr;
    std::cout << '\n';
    return indexNr;
}

unsigned long int getUserPeselNr() {
    unsigned long int peselNr;
    std::cout << "Input PESEL number (11 digits): ";
    std::cin >> peselNr;
    std::cout << '\n';
    return peselNr;
}

std::string getUserLastName() {
    std::string lastName;
    std::cout << "Input last name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, lastName);
    std::cout << '\n';
    return lastName;
}

void printMainMenu() {
    std::cout << "Welcome to university database! Select action:\n";
    std::cout << "[1] Print list of all students\n";
    std::cout << "[2] Add a new student to database\n";
    std::cout << "[3] Print student by index number\n";
    std::cout << "[4] Find a student by PESEL\n";
    std::cout << "[5] Find a student by last name\n";
    std::cout << "[6] Sort students by PESEL\n";
    std::cout << "[7] Sort students by last name\n";
    std::cout << "[8] Remove a student by PESEL\n";
    std::cout << "[9] Remove a student by last name\n";
    std::cout << "[0] Close database\n\n";
}

void mainMenuAction() {
    bool correctInput = false;
    unsigned long int peselNr;
    unsigned int indexNr;
    std::string lastName;
    char pressedKey;
    sortType dir;
    while (!correctInput) {
        pressedKey = getMenuInput();
        switch(pressedKey) {
            case('1'):
                printAllRecords(studentBase);
                correctInput = true;
                break;
            case('2'):
                addRecordToBase(studentBase);
                correctInput = true;
                break;
            case('3'):
                indexNr = getUserIndexNr();
                printByIndex(studentBase,indexNr);
                correctInput = true;
                break;
            case('4'):
                peselNr = getUserPeselNr();
                findByPeselNr(studentBase, peselNr);
                correctInput = true;
                break;
            case('5'):
                lastName = getUserLastName();
                findByLastName(studentBase, lastName);
                correctInput = true;
                break;
            case('6'):
                dir = getUserDirection();
                sortByPeselNr(studentBase, dir);
                correctInput = true;
                break;
            case('7'):
                dir = getUserDirection();
                sortByLastName(studentBase, dir);
                correctInput = true;
                break;
            case('8'):
                peselNr = getUserPeselNr();
                deleteByPeselNr(studentBase, peselNr);
                correctInput = true;
                break;
            case('9'):
                lastName = getUserLastName();
                deleteByLastName(studentBase, lastName);
                correctInput = true;
                break;
            case('0'):
                mainLoopKill = true;
                correctInput = true;
                break;
        }
    }
    if (pressedKey != '0') {
        waitForUser();
    }
}

void waitForUser() {
    std::cout << "Press Enter to Continue" << std::flush;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n";
    std::cout << "-----------------------\n\n";
}