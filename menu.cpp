#include "menu.hpp"

// MAIN MENU
// printing
    // print all
    // print all employees $$$
    // print all students $$$
// add/generate
    // add new record !
    // generate random record $$$
    // generate N random records !
    // generate new student $$$
    // generate new employee $$$
// search
    // find by pesel
    // find by last name
// sort
    // sort by pesel
    // sort by last name
    // sort by salary !
// remove
    // remove by index
    // remove by pesel $$$
// other
    // modify salary by pesel !
    // modify index by pesel $$$
// close

std::shared_ptr<Record> Menu::getUserRecordData() {
    auto isEmployee = getUserInput<char>("occupation (0- student, 1- employee)");
    std::cin.ignore();
    auto firstName = getUserInputStr("first name");
    auto lastName = getUserInputStr("last name");
    auto address = getUserInputStr("address");
    auto peselNr = getUserInput<unsigned long int>("PESEL number");
    auto sexChar = getUserInput<char>("sex ([m]ale, [f]emale, [o]ther, [n]ot stated)");
    SexType sex = SexType::NotStated;
    switch(sexChar) {
        case('m'):
            sex = SexType::Male;
            break;
        case('f'):
            sex = SexType::Female;
            break;
        case('o'):
            sex = SexType::Other;
            break;
        default:
            sex = SexType::NotStated;
            break;
    }
    if(isEmployee == '0') {
        auto classSpecific = getUserInput<unsigned int>("index number");
        std::cout << '\n';
        return std::make_shared<Student>(Student(firstName, lastName, address, peselNr, sex, classSpecific));
    } else {
        auto classSpecific = getUserInput<unsigned int>("salary");
        std::cout << '\n';
        return std::make_shared<Employee>(Employee(firstName, lastName, address, peselNr, sex, classSpecific));
    }
}

char Menu::getMenuInput() {
    char input;
    std::cin >> input;
    return input;
}

void Menu::printMenu(MenuType type) {
    switch(type) {
        case MenuType::Main:
            std::cout << "Welcome to university database! Please select action group:\n";
            std::cout << "[1] Print record\n";
            std::cout << "[2] Add/generate new record\n";
            std::cout << "[3] Search record in database\n";
            std::cout << "[4] Sort database\n";
            std::cout << "[5] Remove from database\n";
            std::cout << "[6] Modify existing record\n";
            std::cout << "[7] Exit\n";
            break;
        case MenuType::Print:
            std::cout << "What would you like to print? Please select action:\n";
            std::cout << "[1] Print all records\n";
            std::cout << "[2] Print all students (extra)\n";
            std::cout << "[3] Print all employees (extra)\n";
            std::cout << "[4] Back\n";
            break;
        case MenuType::Add:
            std::cout << "What would you like to add/generate? Please select action:\n";
            std::cout << "[1] Manually add new record\n";
            std::cout << "[2] Generate random record (!)\n";
            std::cout << "[3] Generate N random records (extra)\n";
            std::cout << "[4] Generate random student (extra)\n";
            std::cout << "[5] Generate random employee (extra)\n";
            std::cout << "[6] Back\n";
            break;
        case MenuType::Search:
            std::cout << "What are you searching for? Please select action:\n";
            std::cout << "[1] Find record by PESEL\n";
            std::cout << "[2] Find record by last name\n";
            std::cout << "[3] Back\n";
            break;
        case MenuType::Sort:
            std::cout << "How would you like to sort records? Please select action:\n";
            std::cout << "[1] Sort records by PESEL\n";
            std::cout << "[2] Sort records by last name\n";
            std::cout << "[3] Sort records by salary\n";
            std::cout << "[4] Back\n";
            break;
        case MenuType::Remove:
            std::cout << "What would you like to remove? Please select action:\n";
            std::cout << "[1] Delete record by index\n";
            std::cout << "[2] Delete record by PESEL (extra)\n";
            std::cout << "[3] Back\n";
            break;
        case MenuType::Modify:
            std::cout << "Please select action:\n";
            std::cout << "[1] Modify salary by PESEL\n";
            std::cout << "[2] Modify index number by PESEL (extra)\n";
            std::cout << "[3] Back\n";
            
            break;
        default:
            std::cout << "-not implemented-\n";
            break;
    }
}

void Menu::mainLoop(Database& database) {
    printMenu(MenuType::Main);
    input_ = getMenuInput();
    std::cout << '\n';
    switch(input_) { // make it so switch..case uses enums, not explicit values
        case '1':
            do {
                printMenu(MenuType::Print);
                input_ = getMenuInput();
                std::cout << '\n';
                if(input_ == '1') {database.printAllRecords();}
                if(input_ == '2') {std::cout << "-to be implemented-\n";}
                if(input_ == '3') {std::cout << "-to be implemented-\n";}
            } while (input_ != '4');
            break;
        case '2':
            do {
                printMenu(MenuType::Add);
                input_ = getMenuInput();
                std::cout << '\n';
                if(input_ == '1') {
                    auto ptr = getUserRecordData(); 
                    if(ptr->getOccupation() == Occupation::Student) {
                        database.addRecordToBase(ptr->getOccupation(),
                                              ptr->getFirstName(), //simple copying constructor would work here
                                              ptr->getLastName(),
                                              ptr->getAddress(),
                                              ptr->getPeselNr(),
                                              ptr->getSex(),
                                              ptr->getIndexNr()
                        );
                    } else {
                        database.addRecordToBase(ptr->getOccupation(),
                                              ptr->getFirstName(), //simple copying constructor would work here
                                              ptr->getLastName(),
                                              ptr->getAddress(),
                                              ptr->getPeselNr(),
                                              ptr->getSex(),
                                              ptr->getSalary()
                        );
                    }
                    ;}
                if(input_ == '2') {std::cout << "-to be implemented-\n";}
                if(input_ == '3') {std::cout << "-to be implemented-\n";}
                if(input_ == '4') {std::cout << "-to be implemented-\n";}
                if(input_ == '5') {std::cout << "-to be implemented-\n";}
            } while (input_ != '6');
            break;
        case '3':
            do {
                printMenu(MenuType::Search);
                input_ = getMenuInput();
                std::cout << '\n';
                if(input_ == '1') {
                    auto peselNr = getUserInput<unsigned long int>("pesel");
                    auto result = database.searchByPesel(peselNr);
                    result->printRecord();
                }
                if(input_ == '2') {
                    auto lastName = getUserInput<std::string>("last name");
                    auto results = database.searchByLastName(lastName);
                    for(auto record : results) {
                        record->printRecord();
                    }
                }
            } while (input_ != '3');
            break;
        case '4':
            do {
                printMenu(MenuType::Sort);
                input_ = getMenuInput();
                std::cout << '\n';
                if(input_ == '1') { //pesel
                    auto direction = getUserDirection();
                    database.sortByPeselNr(direction);
                }
                if(input_ == '2') {//last name
                    auto direction = getUserDirection();
                    database.sortByLastName(direction);
                }
                if(input_ == '3') {//salary
                    auto direction = getUserDirection();
                    database.sortBySalary(direction);
                }
            } while (input_ != '4');
            break;
        case '5':
            do {
                printMenu(MenuType::Remove);
                input_ = getMenuInput();
                std::cout << '\n';
                if(input_ == '1') {
                    auto indexNr = getUserInput<unsigned int>("index number");
                    database.deleteByIndexNr(indexNr);
                }
                if(input_ == '2') {std::cout << "-to be implemented-\n";}
            } while (input_ != '3');
            break;
        case '6':
            do {
                printMenu(MenuType::Modify);
                input_ = getMenuInput();
                std::cout << '\n';
                if(input_ == '1') {
                    auto pesel = getUserInput<unsigned long int>("pesel");
                    auto ptr = database.searchByPesel(pesel);
                    if(ptr->getOccupation() == Occupation::Employee) {
                        auto salary = getUserInput<unsigned int>("salary");
                        database.modifySalary(pesel, salary);
                    } else if(ptr->getOccupation() == Occupation::Student) {
                        std::cout << "This person is not an employee!\n\n";
                    } else {
                        std::cout << "Person with given PESEL number doesn't exist in the database!\n\n";
                    }
                }
                if(input_ == '2') {std::cout << "-to be implemented-\n";}
            } while (input_ != '3');
            break;
        case '7':
        running_ = false;
        std::cout << "Closing database... \n";
            break;
        default:
            break;
    }
}
