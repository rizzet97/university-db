#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "record.hpp"
#include "printing.hpp"

enum sortType {ascending, descending};

bool comparePeselNrInc(const Record&, const Record&);
bool comparePeselNrDec(const Record&, const Record&);
bool compareLastNameInc(const Record&, const Record&);
bool compareLastNameDec(const Record&, const Record&);

void addRecordToBase(std::vector<Record>&);
//void deleteRecordByIndex(std::vector<Record>& database, unsigned int index);

void sortByPeselNr(std::vector<Record>&, sortType);
void sortByLastName(std::vector<Record>&, sortType);

void findByLastName(std::vector<Record>&, std::string);
void findByPeselNr(std::vector<Record>&, unsigned long int);