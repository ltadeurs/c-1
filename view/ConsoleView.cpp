#include <iostream>
#include "ConsoleView.h"

void ConsoleView::clear() {
    std::system("clear");

}

void ConsoleView::drawUniverse(Universe &universe, SpaceShip &spaceShip) {
    int shipXpos;
    int shipYpos;

    clear();

    for (int y = 0; y < universe.size; y++) {
        for (int x = 0; x < universe.size; x++) {
            if (universe.UniverseSectors[x][y].shipIsPresent) {
                std::cout << " " << spaceShip.shipIcon << "  ";
                shipXpos = x;
                shipYpos = y;
            } else
                std::cout << universe.UniverseSectors[x][y].sectorNumber << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Press 'Space' for sector: " << universe.UniverseSectors[shipXpos][shipYpos].sectorNumber << std::endl;
}

void ConsoleView::drawSector(Sector &currentSector) {

    clear();
    std::cout << "You are now at Sector: " << atoi(currentSector.sectorNumber) << std::endl;

    for (int y = 0; y < currentSector.size; y++) {
        for (int x = 0; x < currentSector.size; x++) {
            std::cout << currentSector.sectorContent[x][y] << "  ";
        }
        std::cout << std::endl;
    }
}