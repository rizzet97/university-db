#pragma once
#include <iostream>
#include <limits>
#include "printing.hpp"
#include "storage.hpp"

char getMenuInput();
unsigned int getUserIndexNr();
unsigned long int getUserPeselNr();
std::string getUserLastName();

void printMainMenu();
void mainMenuAction();

void waitForUser();