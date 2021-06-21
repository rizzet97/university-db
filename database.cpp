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
#include "database.hpp"

        

        std::string Record::getSexString() const {
            if (sex_ == 0) {
                return "male";
            } else if (sex_ == 1) {
                return "female";
            } else if (sex_ == 2) {
                return "intersex";
            } else {
                return "not stated";
            }
        }