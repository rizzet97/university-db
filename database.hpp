#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
#include "record.hpp"

enum class SortType {Ascending, Descending, None};

SortType getUserDirection();

std::string stringToLower(const std::string&);
class Database {
public:
    std::vector<std::shared_ptr<Record>>& getDataBase() {return database_;} 
    void printAllRecords() const;
    void printAllRecords(Occupation) const;
    void printRecord(std::shared_ptr<Record>);
    bool checkIfExists(unsigned long int);
    void addRecordToBase(Occupation occupation, const std::string& first, const std::string& last, const std::string& address, unsigned long int pesel, SexType sex, unsigned int classSpecific);
    std::vector<std::shared_ptr<Record>> searchByLastName(std::string);
    std::shared_ptr<Record> searchByPesel(unsigned long int);
    void sortByPeselNr(SortType);
    void sortByLastName(SortType);
    void sortBySalary(SortType);
    void deleteByIndexNr(unsigned int index);
private:
    std::vector<std::shared_ptr<Record>> database_;
};