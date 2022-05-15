#include <iostream>
#include <vector>
#include "menu.hpp"
#include "record.hpp"
#include "database.hpp"

// WORKPLAN:
// 1) turn Record into base class (interface for records) [done]
// 2) implement derived classes Employee nad Student [done]
// 3) change studentBase from vector of objects to vector of shared pointers [done]
// 4) add missing functions [   ]

// WYMAGANIA
// Przechowywanie rekordów pracowników uczelni o strukturze: imię, nazwisko, PESEL, płeć, adres, zarobki
// Wszystkie osoby niezależnie czy będą to pracownicy, czy studenci mają być trzymani w jednym kontenerze
// Wypełnianie bazy danych sztucznymi danymi (generowanie danych)
// Modyfikacja zarobków wyszukując osobę po numerze PESEL (problematyczne)
// Sortowanie po zarobkach (problematyczne)

int main() {
    Database database;
    Menu menu;
    
    database.addRecordToBase(Occupation::Student, "Pawel", "Nita", "ul. Dluga 86", 97001122334, SexType::Male, 112233);
    database.addRecordToBase(Occupation::Student, "Marek", "Nowak", "ul. Krotka 117", 68082822334, SexType::Male, 657321);
    database.addRecordToBase(Occupation::Student, "Celina", "Nowak", "ul. Krotka 117", 68111622379, SexType::Female, 657322);
    database.addRecordToBase(Occupation::Student, "Janina", "Kowalska", "ul. Warszawska 40", 77010232999, SexType::Female, 336040);
    database.addRecordToBase(Occupation::Employee, "Maria", "Sklodowska-Curie", "ul. Uniwersytecka 91", 12458810347, SexType::Female, 16250);
    database.addRecordToBase(Occupation::Student, "Jan", "Niezbedny", "ul. Kosciuszki 19", 95030821210, SexType::Other, 203787);
    database.addRecordToBase(Occupation::Employee, "Stefan", "Banach", "Lwowska 3", 92083012345, SexType::Male, 12500);

    // database.printAllRecords();
    menu.run();

    while(menu.isRunning()) {
        menu.mainLoop(database);
    }
    
    return 0;
}