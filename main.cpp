#include <iostream>
#include <vector>
#include "menu.hpp"
#include "printing.hpp"
#include "record.hpp"
#include "storage.hpp"

// WORKPLAN:
// 1) turn Record into abstract class (interface for records)
// 2) implement derived classes Employee nad Student
// 3) change studentBase from vector of objects to vector of shared pointers

// WYMAGANIA
// Przechowywanie rekordów pracowników uczelni o strukturze: imię, nazwisko, PESEL, płeć, adres, zarobki
// Wszystkie osoby niezależnie czy będą to pracownicy, czy studenci mają być trzymani w jednym kontenerze
// Wypełnianie bazy danych sztucznymi danymi (generowanie danych)
// Modyfikacja zarobków wyszukując osobę po numerze PESEL (problematyczne)
// Sortowanie po zarobkach (problematyczne)


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