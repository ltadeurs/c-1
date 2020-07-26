#include <random>
#include "SectorController.h"


void SectorController::createSectorGrid(Sector &currentSector) {
    for (int y = 0; y < currentSector.size; y++) {
        for (int x = 0; x < currentSector.size; x++) {
            currentSector.sectorContent[x][y] = '.';
        }
    }

}


void SectorController::travelToSector(Sector &currentSector, default_random_engine &generator, ConsoleView &consoleView) {

    createSectorGrid(currentSector);

    for (int i = 0; i < currentSector.pla; i++)
        placeObjectInSector('@', currentSector, generator);
    for (int i = 0; i < currentSector.ast; i++)
        placeObjectInSector('O', currentSector, generator);
    for (int i = 0; i < currentSector.enc; i++)
        placeObjectInSector('*', currentSector, generator);
    placeObjectInSector('P', currentSector, generator);

    consoleView.clear();
    consoleView.drawSector(currentSector);

}

void SectorController::placeObjectInSector(char objectIcon, Sector &currentSector, default_random_engine &generator) {


    int randomXpos = generateRandomPosition(currentSector, generator);
    int randomYpos = generateRandomPosition(currentSector, generator);

    while (currentSector.sectorContent[randomXpos][randomYpos] != '.'){
        randomXpos = generateRandomPosition(currentSector, generator);
        randomYpos = generateRandomPosition(currentSector, generator);
    }

    currentSector.sectorContent[randomXpos][randomYpos] = objectIcon;

}

int SectorController::generateRandomPosition(Sector &currentSector, default_random_engine &generator){

    std::uniform_int_distribution<int> pos(0, currentSector.size - 1);
    return pos(generator);

}


