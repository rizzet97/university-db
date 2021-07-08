#include <iostream>
#include <vector>
#include "menu.hpp"
#include "printing.hpp"
#include "record.hpp"
#include "storage.hpp"

void addRecordToBase();
void printByIndex(unsigned int);

std::vector<Record> studentBase;

int main() {
    Record test("Pawel", "Nita", "ul. Dluga 86", 112233, 97001122334, male);
    Record test2("Marek", "Nowak", "ul. Krotka 117", 657321, 68082822334, male);
    Record test3("Janina", "Kowalska", "ul. Warszawska 40", 336040, 77010232999, female);
    Record test4("Maria", "Sklodowska-Curie", "ul. Promienna 91", 990087, 12458810347, female);
    studentBase.push_back(test);
    studentBase.push_back(test2);
    studentBase.push_back(test3);
    studentBase.push_back(test4); 
    std::cout << "UNSORTED:\n";
    printAllRecords(studentBase);
    std::cout << "-----------------------------\n";
    std::cout << "ASCENDING BY NAME:\n";
    sortByLastName(studentBase,ascending);
    printAllRecords(studentBase);
    std::cout << "-----------------------------\n";
    std::cout << "DESCENDING BY NAME:\n";
    sortByLastName(studentBase,descending);
    printAllRecords(studentBase);
    return 0;
}