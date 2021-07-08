#include "printing.hpp"

void printAllRecords(std::vector<Record>& database) {
    for (auto el : database){
        std::cout<< "First name: \t" << el.getFirstName() << '\n';
        std::cout<< "Last name: \t" << el.getLastName() << '\n';
        std::cout<< "Sex: \t\t" << el.getSexString() << '\n';
        std::cout<< "Address: \t" << el.getAddress() << '\n';
        std::cout<< "Index: \t\t" << el.getIndexNr() << '\n';
        std::cout<< "PESEL: \t\t" << el.getPeselNr() << "\n\n";
    }
}

void printRecord(Record printedRecord) {
    std::cout<< "First name: \t" << printedRecord.getFirstName() << '\n';
    std::cout<< "Last name: \t" << printedRecord.getLastName() << '\n';
    std::cout<< "Sex: \t\t" << printedRecord.getSexString() << '\n';
    std::cout<< "Address: \t" << printedRecord.getAddress() << '\n';
    std::cout<< "Index: \t\t" << printedRecord.getIndexNr() << '\n';
    std::cout<< "PESEL: \t\t" << printedRecord.getPeselNr() << "\n\n";
}

void printByIndex(std::vector<Record>& database, unsigned int index) {
    size_t count = 0;
    for (auto el : database) {
        if (index == el.getIndexNr()) {
            printRecord(el);
            ++count;
        }
    }
    if (count < 1) {
        std::cout << "No matches found!";
    }
}