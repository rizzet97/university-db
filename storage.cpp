#include "storage.hpp"

bool comparePeselNrInc(const Record& lhs, const Record& rhs) {
    return lhs.getPeselNr() < rhs.getPeselNr();
}

bool comparePeselNrDec(const Record& lhs, const Record& rhs) {
    return lhs.getPeselNr() > rhs.getPeselNr();
}

bool compareLastNameInc(const Record& lhs, const Record& rhs) {
    return lhs.getLastName() < rhs.getLastName();
}

bool compareLastNameDec(const Record& lhs, const Record& rhs) {
    return lhs.getLastName() > rhs.getLastName();
}

void addRecordToBase(std::vector<Record>& database) {
    Record newRecord;
    std::string str;
    unsigned long int pesel;
    unsigned int index;
    sexType sex;

    std::cout << "Enter first name:\n";
    std::cin >> str;
    newRecord.setFirstName(str);
    std::cout << "Enter last name:\n";
    std::cin >> str;
    newRecord.setLastName(str);
    std::cout << "Enter address:\n";
    std::cin.ignore();
    getline(std::cin, str);
    newRecord.setAddress(str);
    std::cout << "Enter index number:\n";
    std::cin >> index;
    newRecord.setIndexNr(index);
    std::cout << "Enter PESEL number:\n";
    std::cin >> pesel;
    newRecord.setPeselNr(pesel);
    std::cout << "Choose sex (1-male, 2-female, 3-intersex, 4-prefer not to state):\n"; 
    std::cin >> index;
    switch(index){
        case(1):
            sex = male;
            break;
        case(2):
            sex = female;
            break;
        case(3):
            sex = intersex;
            break;
        case(4):
            sex = notStated;
            break;
        default:
            sex = notStated;
    }
    newRecord.setSex(sex);
    database.push_back(newRecord);
    std::cout << "New student '" << newRecord.getFirstName() << " " << newRecord.getLastName() << "' added!\n\n";
}


void deleteByPeselNr(std::vector<Record>& database, unsigned long int peselNr) {
    auto it = std::find_if(database.begin(), database.end(), [peselNr](const Record& obj) {return obj.getPeselNr() == peselNr;});
    database.erase(it);
}

void deleteByLastName(std::vector<Record>& database, std::string lastName) {
    auto it = std::find_if(database.begin(), database.end(), [lastName](const Record& obj) {return obj.getLastName() == lastName;});
    database.erase(it);
}

void sortByPeselNr(std::vector<Record>& database, sortType sortDir) {
    if (sortDir == descending) {
        std::sort(database.begin(), database.end(), comparePeselNrDec);
    } else {
        std::sort(database.begin(), database.end(), comparePeselNrInc);
    }
}

void sortByLastName(std::vector<Record>& database, sortType sortDir) {
    if (sortDir == descending) {
        std::sort(database.begin(), database.end(), compareLastNameDec);
    } else {
        std::sort(database.begin(), database.end(), compareLastNameInc);
    }
}

void findByLastName(std::vector<Record>& database, std::string lastName) {
    auto it = find_if(database.begin(), database.end(), [&lastName](const Record& obj) {return obj.getLastName() == lastName;});
    if (it != database.end())
    {
        // converting iterator to index - not needed (can access element by iterator)
        auto index = std::distance(database.begin(), it);
        printRecord(database[index]);
    } else {
        std::cout << "No student with last name '" << lastName << "' found in the database!\n\n"; 
    }
}

void findByPeselNr(std::vector<Record>& database, unsigned long int peselNr) {
    auto it = find_if(database.begin(), database.end(), [&peselNr](const Record& obj) {return obj.getPeselNr() == peselNr;});
    if (it != database.end()) {
        // converting iterator to index - not needed (can access element by iterator)
        auto index = std::distance(database.begin(), it);
        printRecord(database[index]);
    } else {
        std::cout << "No student with PESEL nr '" << peselNr << "' found in the database!\n\n"; 
    }
}

sortType getUserDirection() {
    sortType dir = none;
    char key;
    std::cout << "Choose direction of sorting.\n";
    std::cout << "[a]scending / [d]escending: ";
    std::cin >> key;
    while (dir == none) {
        if(key == 'd') {
            dir = descending;
            std::cout << "Sorting records descending:\n";
        } else if(key == 'a') {
            dir = ascending;
            std::cout << "Sorting records ascending:\n";
        } else {
            std::cout << "Wrong key pressed!\n";
            std::cout << "Choose direction of sorting.\n";
            std::cout << "[a]scending / [d]escending: ";
            std::cin >> key;
        }
    }
    return dir;
}