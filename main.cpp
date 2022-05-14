#include <iostream>
#include <vector>
#include "menu.hpp"
#include "record.hpp"
#include "database.hpp"

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

int main() {
    Database database;
    Menu menu;
    
    database.addRecordToBase("Pawel", "Nita", "ul. Dluga 86", 112233, 97001122334, SexType::Male);
    database.addRecordToBase("Marek", "Nowak", "ul. Krotka 117", 657321, 68082822334, SexType::Male);
    database.addRecordToBase("Celina", "Nowak", "ul. Krotka 117", 657322, 68111622379, SexType::Female);
    database.addRecordToBase("Janina", "Kowalska", "ul. Warszawska 40", 336040, 77010232999, SexType::Female);
    database.addRecordToBase("Maria", "Sklodowska-Curie", "ul. Uniwersytecka 91", 990087, 12458810347, SexType::Female);
    database.addRecordToBase("Jan", "Niezbedny", "ul. Kosciuszki 19", 203787, 95030821210, SexType::Other);

    // database.printAllRecords();
    menu.run();

    while(menu.isRunning()) {
        menu.mainLoop(database);
    }
    
    return 0;
}