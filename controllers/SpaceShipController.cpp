#include <windows.h>
#include "SpaceShipController.h"

void SpaceShipController::placeShip(Universe &universe, Sector *foundSector, ConsoleView &consoleView) {
    consoleView.clear();
    for (int y = 0; y < universe.size; y++) {
        for (int x = 0; x < universe.size; x++) {
            if (universe.UniverseSectors[x][y].sectorNumber == foundSector->sectorNumber) {
                universe.UniverseSectors[x][y].shipIsPresent = true;
                spaceShip.currentSector = universe.UniverseSectors[x][y];
            }
        }
    }
    consoleView.drawUniverse(universe, spaceShip);
}

void
SpaceShipController::travelShip(Universe &universe, Sector &currentSector, ConsoleView &consoleView, bool inSector) {
    while (!spaceShip.outOfBounds) {
        Sleep(100);
        if (GetAsyncKeyState(VK_UP) < 0) {
            moveShip(universe, currentSector, VK_UP, inSector);
            if (inSector)
                consoleView.drawSector(currentSector);
            else
                consoleView.drawUniverse(universe, spaceShip);
        } else if (GetAsyncKeyState(VK_DOWN) < 0) {
            moveShip(universe, currentSector, VK_DOWN, inSector);
            if (inSector)
                consoleView.drawSector(currentSector);
            else
                consoleView.drawUniverse(universe, spaceShip);
        } else if (GetAsyncKeyState(VK_RIGHT) < 0) {
            moveShip(universe, currentSector, VK_RIGHT, inSector);
            if (inSector)
                consoleView.drawSector(currentSector);
            else
                consoleView.drawUniverse(universe, spaceShip);
        } else if (GetAsyncKeyState(VK_LEFT) < 0) {
            moveShip(universe, currentSector, VK_LEFT, inSector);
            if (inSector)
                consoleView.drawSector(currentSector);
            else
                consoleView.drawUniverse(universe, spaceShip);
        } else if (GetAsyncKeyState(VK_SPACE)) {
            return;
        }
    }
}


void SpaceShipController::moveShip(Universe &universe, Sector &currentSector, int direction, bool &inSector) {
    int areaSize;
    if (inSector)
        areaSize = currentSector.size;
    else
        areaSize = universe.size;

    for (int y = 0; y < areaSize; y++) {
        for (int x = 0; x < areaSize; x++) {
            if ((universe.UniverseSectors[x][y].shipIsPresent && !inSector) ||
                (currentSector.sectorContent[x][y] == 'P' && inSector)) {
                int newXcor = x;
                int newYcor = y;
                if (direction == VK_UP)
                    newYcor--;
                else if (direction == VK_DOWN)
                    newYcor++;
                else if (direction == VK_RIGHT)
                    newXcor++;
                else if (direction == VK_LEFT)
                    newXcor--;

                if (inSector) {
                    currentSector.sectorContent[x][y] = '.';
                    currentSector.sectorContent[newXcor][newYcor] = 'P';
                } else {
                    if (newXcor >= areaSize || newYcor >= areaSize) {
                        spaceShip.outOfBounds = true;
                        return;
                    }
                    universe.UniverseSectors[x][y].shipIsPresent = false;
                    universe.UniverseSectors[newXcor][newYcor].shipIsPresent = true;
                    spaceShip.currentSector = universe.UniverseSectors[newXcor][newYcor];
                }
                return;
            }
        }
    }
}


Sector SpaceShipController::getShipCurrentSector() {

    return spaceShip.currentSector;
}

bool SpaceShipController::getShipOutOfBounds() {

    return spaceShip.outOfBounds;
}


