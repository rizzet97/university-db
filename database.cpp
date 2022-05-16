#include "database.hpp"

std::string stringToLower(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c){ return std::tolower(c); });
    return lower;
}
void Database::addRecordToBase(Occupation occupation, const std::string& first, const std::string& last, const std::string& address, unsigned long int pesel, SexType sex, unsigned int classSpecific) {
    //check if PESEL exists
    if(checkIfExists(pesel)) {
        std::cout << "Person with given PESEL number already exists in the database!\n\n";
    } else {
        if(occupation == Occupation::Student) {
            database_.push_back(std::make_shared<Student>(Student(first, last, address, pesel, sex, classSpecific)));
        } else if(occupation == Occupation::Employee) {
            database_.push_back(std::make_shared<Employee>(Employee(first, last, address, pesel, sex, classSpecific)));
        } else {
            database_.push_back(std::make_shared<NullRecord>(NullRecord()));
        }
    }
}
void Database::printAllRecords() const {
    for(const auto& record : database_) {
        record->printRecord();
    }
}

void Database::printAllRecords(Occupation occupation) const {
    if(occupation == Occupation::Employee) {
        for(const auto& record : database_) {
            if(record->getOccupation() == Occupation::Employee) {
                record->printRecord();
            }
        }
    } else if(occupation == Occupation::Student) {
        for(const auto& record : database_) {
            if(record->getOccupation() == Occupation::Student) {
                record->printRecord();
            }
        }
    }
}

bool Database::checkIfExists(unsigned long int pesel) {
    auto findPesel = [&pesel](const std::shared_ptr<Record>& ptr){
        return ptr->getPeselNr() == pesel; 
    };
    auto it = std::find_if(database_.begin(), database_.end(), findPesel);
    return it != database_.end();
}

std::vector<std::shared_ptr<Record>> Database::searchByLastName(std::string name) {
    std::vector<std::shared_ptr<Record>> matches;
    auto findLastName = [&name](const std::shared_ptr<Record>& ptr){
        std::string lastNameToSearch = stringToLower(name);
        std::string currentLastName = stringToLower(ptr->getLastName());
        return currentLastName.find(lastNameToSearch) != std::string::npos;
    };
    auto it = std::find_if(database_.cbegin(), database_.cend(), findLastName);
    while (it != database_.end()) {
        matches.emplace_back(*it++);
        it = std::find_if(it, database_.cend(), findLastName);
    }
    if(matches.size() < 1) {matches.emplace_back(std::make_shared<NullRecord>(NullRecord()));}
    return matches;
}
std::shared_ptr<Record> Database::searchByPesel(unsigned long int pesel) {
    auto findPesel = [&pesel](const std::shared_ptr<Record>& ptr) {
        return ptr->getPeselNr() == pesel;
    };
    auto it = std::find_if(database_.cbegin(), database_.cend(), findPesel);
    if(it != database_.end()) {
        return *it;
    } else {
        // return std::make_shared<NullRecord>(NullRecord());
        return std::make_shared<NullRecord>(NullRecord());
    }
}
void Database::sortByPeselNr(SortType sortDir) {
    if (sortDir == SortType::Descending) {
        std::sort(database_.begin(),
                  database_.end(),
                  [](std::shared_ptr<Record> lhs, std::shared_ptr<Record> rhs){
                      return lhs->getPeselNr() > rhs->getPeselNr();
                  });
    } else {
        std::sort(database_.begin(),
                  database_.end(),
                  [](std::shared_ptr<Record> lhs, std::shared_ptr<Record> rhs){
                      return lhs->getPeselNr() < rhs->getPeselNr();
                  });
    }
}
void Database::sortByLastName(SortType sortDir) {
    if (sortDir == SortType::Descending) {
        std::sort(database_.begin(),
                  database_.end(),
                  [](std::shared_ptr<Record> lhs, std::shared_ptr<Record> rhs){
                      return lhs->getLastName() > rhs->getLastName();
                  });
    } else {
        std::sort(database_.begin(),
                  database_.end(),
                  [](std::shared_ptr<Record> lhs, std::shared_ptr<Record> rhs){
                      return lhs->getLastName() < rhs->getLastName();
                  });
    }
}
void Database::sortBySalary(SortType sortDir) {
    if (sortDir == SortType::Descending) {
        std::sort(database_.begin(),
                  database_.end(),
                  [](std::shared_ptr<Record> lhs, std::shared_ptr<Record> rhs){
                      return lhs->getSalary() > rhs->getSalary();
                  });
    } else {
        std::sort(database_.begin(),
                  database_.end(),
                  [](std::shared_ptr<Record> lhs, std::shared_ptr<Record> rhs){
                      return lhs->getSalary() < rhs->getSalary();
                  });
    }
}
void Database::deleteByIndexNr(unsigned int index) {
    auto findIndex = [&index](const std::shared_ptr<Record>& ptr) {
        return ptr->getIndexNr() == index;
    };
    auto it = std::find_if(database_.cbegin(), database_.cend(), findIndex);
    if(it == database_.end()) {
        std::cout << "Person with given index number doesn't exist in the database!\n\n";
    } else {
        database_.erase(it);
        std::cout << "Record successfully removed!\n\n";
    }
}