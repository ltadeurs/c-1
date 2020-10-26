#include <random>
#include <iostream>
#include <sstream>
#include "UniverseController.h"


void UniverseController::scanSectors(Universe &universe, default_random_engine &generator) {

    // generate random spaceObjects

    std::uniform_int_distribution<int> asteroids(0, 9);
    std::uniform_int_distribution<int> encounters(0, 3);
    std::uniform_int_distribution<int> planets(0, 2);

    // create sector
    Sector sector;

    for (int y = 0; y < universe.size; y++) {
        for (int x = 0; x < universe.size; x++) {
            int ast = asteroids(generator);
            int enc = encounters(generator);
            int pla = planets(generator);

            // print Sectors
            std::cout << ast << enc << pla << " ";

            sector.ast = ast;
            sector.enc = enc;
            sector.pla = pla;
            sector.xPos = x;
            sector.yPos = y;
            sector.id = x + y;

            ostringstream sectorStream;
            sectorStream << ast << enc << pla;
            istringstream sectorLine(sectorStream.str());
            sectorLine >> sector.sectorNumber;

            universe.UniverseSectors[x][y] = sector;
        }
        std::cout << std::endl;
    }
}

Sector *UniverseController::searchSector(Universe &universe, char* chosenSectorNumber) {
    bool sectorFound;
    bool sectorIsValid;
    Sector *selectedSector;
    for (int y = 0; y < universe.size; y++) {
        for (int x = 0; x < universe.size; x++) {
            if (atoi(universe.UniverseSectors[x][y].sectorNumber) == atoi(chosenSectorNumber)) {
                selectedSector = &universe.UniverseSectors[x][y];
                sectorIsValid = validateSector(universe, selectedSector);
                sectorFound = true;
            }
        }
    }
    if (!sectorFound)
        std::cout << "Chosen sector: " << chosenSectorNumber << " is not found" << std::endl;
    if(!sectorIsValid || !sectorFound)
        return nullptr;

    return selectedSector;
}

bool UniverseController::validateSector(Universe &universe, Sector *selectedSector) {
    if ((selectedSector->yPos >= 0 && selectedSector->xPos <= 0) ||
        (selectedSector->yPos <= 0 && selectedSector->xPos >= 0) ||
        (selectedSector->yPos == universe.size - 1) ||
        (selectedSector->xPos == universe.size - 1)) {
        std::cout << "Chosen sector: " << selectedSector->sectorNumber << " is valid" << std::endl;
        return true;
    } else {
        std::cout << "Chosen sector: " << selectedSector->sectorNumber << " is not an outer sector" << std::endl;
        return false;
    }
}
