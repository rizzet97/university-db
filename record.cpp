#include "record.hpp"

std::string Record::getSexString() const {
    if (sex_ == SexType::Male) {
        return "male";
    } else if (sex_ == SexType::Female) {
        return "female";
    } else if (sex_ == SexType::Other) {
        return "other";
    } else {
        return "not stated";
    }
}
void Record::printRecord() {
    std::cout<< "First name: \t" << firstName_ << '\n';
    std::cout<< "Last name: \t" << lastName_ << '\n';
    std::cout<< "Sex: \t\t" << getSexString() << '\n';
    std::cout<< "Address: \t" << address_ << '\n';
    // if student
    std::cout<< "Index: \t\t" << indexNr_ << '\n';
    // if employee
    // std::cout<< "Salary: \t\t" << record->getIndexNr() << '\n';

    std::cout<< "PESEL: \t\t" << peselNr_ << "\n\n";
}