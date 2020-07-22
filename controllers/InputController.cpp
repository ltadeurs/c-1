#include "InputController.h"
#include <iostream>


char* InputController::getChosenSector() {

    char* typedNumber;
    std::cout << "Welcome at the headquarters, Please choose a sector to start: ";
    std::cin >> typedNumber;

    return typedNumber;
}