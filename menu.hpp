#pragma once
#include <iostream>
#include <limits>
#include "record.hpp"
#include "database.hpp"
#include "generator.hpp"

class Menu {
public:
    enum class MenuType {
        Main,
        Print,
        Add,
        Search,
        Sort,
        Remove,
        Modify
    };
    bool isRunning() const {return running_;}
    void run() {running_ = true;}
    std::shared_ptr<Record> getUserRecordData();
    char getMenuInput();   
    template<class T>
    T getUserInput(std::string userLabel) {
        T input;
        std::cout << "Input " << userLabel << ": ";
        std::cin  >> input;
        std::cout << '\n';
        return input;
    }
    std::string getUserInputStr(std::string userLabel) {
        std::string input;
        std::cout << "Set " << userLabel << ": ";
        std::getline(std::cin, input);
        return input;
    }
    SortType getUserDirection() {
        auto directionChar = getUserInput<char>("direction ([a]scending or [d]escending)");
            SortType direction = SortType::None;
            switch(directionChar) {
                case('a'):
                    direction = SortType::Ascending;
                    break;
                case('d'):
                    direction = SortType::Descending;
                    break;
                default:
                    direction = SortType::Ascending;
                    break;
            }
        return direction;
    }
    void printMenu(MenuType);
    void mainLoop(Database&);
    void modifyRecord(Occupation);
private:
bool running_;
char input_;
Generator generator_;
};
