#include <iostream>
#include <random>
#include "SectorController.h"


void SectorController::createSectorGrid(int sectorSize) {
    for (int y = 0; y < sectorSize; y++) {
        for (int x = 0; x < sectorSize; x++) {
            traveledSector[x][y] = '.';
        }
    }

}


void SectorController::travelToSector(Sector *foundSector, default_random_engine &generator) {

    createSectorGrid(foundSector->size);

    for (int i = 0; i < foundSector->pla; i++) {
        placeObjectInSector('@', foundSector, generator);
    }

    for (int i = 0; i < foundSector->ast; i++) {
        placeObjectInSector('O', foundSector, generator);
    }

    for (int i = 0; i < foundSector->enc; i++) {
        placeObjectInSector('*', foundSector, generator);
    }

    for (int y = 0; y < foundSector->size; y++) {
        for (int x = 0; x < foundSector->size; x++) {
            std::cout << traveledSector[x][y] << "  ";
        }
        std::cout << std::endl;
    }

}

void SectorController::placeObjectInSector(char objectIcon, Sector *foundSector, default_random_engine &generator) {


    int randomXpos = generateRandomPosition(foundSector, generator);
    int randomYpos = generateRandomPosition(foundSector, generator);

    while (traveledSector[randomXpos][randomYpos] != '.'){
        randomXpos = generateRandomPosition(foundSector, generator);
        randomYpos = generateRandomPosition(foundSector, generator);
    }

    traveledSector[randomXpos][randomYpos] = objectIcon;

}

int SectorController::generateRandomPosition(Sector *foundSector, default_random_engine &generator){

    std::uniform_int_distribution<int> pos(0, foundSector->size - 1);
    return pos(generator);

}


