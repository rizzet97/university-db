#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "record.hpp"
#include "storage.hpp"

enum sortType {ascending, descending};

bool comparePeselNrInc(const Record & lhs, const Record & rhs);
bool comparePeselNrDec(const Record & lhs, const Record & rhs);
bool compareLastNameInc(const Record & lhs, const Record & rhs);
bool compareLastNameDec(const Record & lhs, const Record & rhs);

void addRecordToBase(std::vector<Record>& database);

//ITERATOR TO RECORD getRecordByIndex(unsigned int indexNr);

//ITERATOR TO RECORD getRecordByPesel(unsigned long int peselNr);

//void deleteByIndex(std::vector<Record>& database, unsigned int index);

void sortByPeselNr(std::vector<Record>& database, sortType sortDir);
void sortByLastName(std::vector<Record>& database, sortType sortDir);