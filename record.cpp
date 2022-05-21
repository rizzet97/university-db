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

unsigned int Student::getIndexNr() const {
    return indexNr_;
}

unsigned int Student::getSalary() const {
    return 0;
}

void Student::setIndexNr(unsigned int indexNr) {
    indexNr_ = indexNr;
}

void Student::setSalary(unsigned int salary) {
    (void)salary;
}

void Student::printRecord() {
    std::cout << "First name: \t" << getFirstName() << '\n';
    std::cout << "Last name: \t" << getLastName() << '\n';
    std::cout << "Occupation: \t" << "STUDENT" << '\n';
    std::cout << "Sex: \t\t" << getSexString() << '\n';
    std::cout << "Address: \t" << getAddress() << '\n';
    std::cout << "PESEL: \t\t" << getPeselNr() << '\n';
    std::cout << "Index: \t\t" << getIndexNr() << "\n\n";
}

unsigned int NullRecord::getIndexNr() const {
    return 0;
}

unsigned int NullRecord::getSalary() const {
    return 0;
}

void NullRecord::setIndexNr(unsigned int indexNr) {
    (void)indexNr;
}

void NullRecord::setSalary(unsigned int salary) {
    (void)salary;
}

void NullRecord::printRecord() {
        std::cout << "-record doesn't exist in database-\n\n";
}

unsigned int Employee::getIndexNr() const {
    return 0;
}

unsigned int Employee::getSalary() const {
    return salary_;
}

void Employee::setIndexNr(unsigned int indexNr) {
    (void)indexNr;
}

void Employee::setSalary(unsigned int salary) {
    salary_ = salary;
}

void Employee::printRecord() {
    std::cout << "First name: \t" << getFirstName() << '\n';
    std::cout << "Last name: \t" << getLastName() << '\n';
    std::cout << "Occupation: \t" << "EMPLOYEE" << '\n';
    std::cout << "Sex: \t\t" << getSexString() << '\n';
    std::cout << "Address: \t" << getAddress() << '\n';
    std::cout << "PESEL: \t\t" << getPeselNr() << '\n';
    std::cout << "Salary: \t" << getSalary() << " PLN\n\n";
}