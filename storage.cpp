#include "storage.hpp"

bool comparePeselNrInc(const Record & lhs, const Record & rhs) {
    return lhs.getPeselNr() < rhs.getPeselNr();
}

bool comparePeselNrDec(const Record & lhs, const Record & rhs) {
    return lhs.getPeselNr() > rhs.getPeselNr();
}

bool compareLastNameInc(const Record & lhs, const Record & rhs) {
    return lhs.getLastName() < rhs.getLastName();
}

bool compareLastNameDec(const Record & lhs, const Record & rhs) {
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
}

//void deleteByIndex(std::vector<Record>& database, unsigned int index) {
    //for range loop
        //if indexNumber equal to the one passed
            //get element index in vector
            //delete element from vector
            //increment match counter
    //if no matches found,s say so
    //else print X records deleted
//}

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