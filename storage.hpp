#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include "record.hpp"
#include "printing.hpp"

enum sortType {ascending = 0, descending = 1, none = 2};

bool comparePeselNrInc(const Record&, const Record&);
bool comparePeselNrDec(const Record&, const Record&);
bool compareLastNameInc(const Record&, const Record&);
bool compareLastNameDec(const Record&, const Record&);

void addRecordToBase(std::vector<Record>&);
void deleteByPeselNr(std::vector<Record>&, unsigned long int);
void deleteByLastName(std::vector<Record>&, std::string);

void sortByPeselNr(std::vector<Record>&, sortType);
void sortByLastName(std::vector<Record>&, sortType);

void findByLastName(std::vector<Record>&, std::string);
void findByPeselNr(std::vector<Record>&, unsigned long int);

sortType getUserDirection();