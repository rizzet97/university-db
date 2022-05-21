#include <iostream>
#include "menu.hpp"
#include "record.hpp"
#include "database.hpp"
#include "generator.hpp"

int main() {
    Database database;
    Menu menu;

    menu.run();

    while(menu.isRunning()) {
        menu.mainLoop(database);
    }
    
    return 0;
}