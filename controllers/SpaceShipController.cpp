#include <iostream>
#include <stdio.h>
#include "SpaceShipController.h"

void SpaceShipController::placeShip(Universe &universe, Sector *foundSector) {

    for (int y = 0; y < universe.size; y++) {
        for (int x = 0; x < universe.size; x++) {

            // print Sectors
            if (universe.UniverseSectors[x][y].sectorNumber == foundSector->sectorNumber)
                std::cout << " P  ";
            else
                std::cout << universe.UniverseSectors[x][y].sectorNumber << " ";
        }
        std::cout << std::endl;
    }
    listenForKeys();

}

void SpaceShipController::listenForKeys() {

    char ch;
    do {
        ch = getchar();
        if (ch == 65)
            printf("You pressed UP key\n");
        else if (ch == 66)
            printf("You pressed DOWN key\n");
        else if (ch == 67)
            printf("You pressed RIGHT key\n");
        else if (ch == 68)
            printf("You pressed LEFT key\n");


    } while (ch != 'e');

}

