#include "database.hpp"

std::string stringToLower(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(), [](unsigned char c){ return std::tolower(c); });
    return lower;
}
void Database::addRecordToBase(std::string first, std::string last, std::string address, unsigned int index, unsigned long int pesel, SexType sex) {
    //check if PESEL exists
    //if yes: 
        // std::cout << "Person with given PESEL number already exists in the database!\n";
    database_.push_back(std::make_shared<Record>(Record(first, last, address, index, pesel, sex)));
}
void Database::printAllRecords() const {
    for(const auto& record : database_) {
        record->printRecord();
    }
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
        return std::make_shared<Record>(NullRecord());
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
void Database::deleteByIndexNr(unsigned int index) {
    auto findIndex = [&index](const std::shared_ptr<Record>& ptr) {
        return ptr->getIndexNr() == index;
    };
    auto it = std::find_if(database_.cbegin(), database_.cend(), findIndex);
    database_.erase(it);
}