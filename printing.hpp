#pragma once
#include <iostream>
#include <vector>
#include "menu.hpp"
#include "record.hpp"

void printAllRecords(std::vector<Record>& database);

void printRecord(Record printedRecord);

void printByIndex(std::vector<Record>& database, unsigned int index);