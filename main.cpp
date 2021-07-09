#include <iostream>
#include <vector>
#include "menu.hpp"
#include "printing.hpp"
#include "record.hpp"
#include "storage.hpp"

std::vector<Record> studentBase;
bool mainLoopKill = false;

int main() {
    Record test("Pawel", "Nita", "ul. Dluga 86", 112233, 97001122334, male);
    Record test2("Marek", "Nowak", "ul. Krotka 117", 657321, 68082822334, male);
    Record test3("Janina", "Kowalska", "ul. Warszawska 40", 336040, 77010232999, female);
    Record test4("Maria", "Sklodowska-Curie", "ul. Uniwersytecka 91", 990087, 12458810347, female);
    studentBase.push_back(test);
    studentBase.push_back(test2);
    studentBase.push_back(test3);
    studentBase.push_back(test4); 
    
    while(!mainLoopKill) {
        printMainMenu();
        mainMenuAction();
    }
    return 0;
}