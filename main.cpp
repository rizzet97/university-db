/*
    Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, adres, nr indeksu, PESEL, płeć
    Dodawanie nowych studentów
    Wyświetlanie całej bazy danych
    Wyszukiwanie po nazwisku
    Wyszukiwanie po numerze PESEL
    Sortowanie po numerze PESEL
    Sortowanie po nazwisku
    Usuwanie po numerze indeksu
*/
#include <iostream>
#include "database.hpp"

int main() {
    Record test("John", "Doe", "Streetname 123", 112233, 97001122334, male);
    std::cout<< test.getFirstName() << '\n';
    std::cout<< test.getLastName() << '\n';
    std::cout<< test.getAddress() << '\n';
    std::cout<< test.getIndexNr() << '\n';
    std::cout<< test.getPeselNr() << '\n';
    std::cout<< test.getSexString() << '\n';
    return 0;
}