#ifndef PLANET_EXPRESS_SECTORCONTROLLER_H
#define PLANET_EXPRESS_SECTORCONTROLLER_H


#include "../models/Sector.h"

using namespace std;
class SectorController{

public:
    void travelToSector(Sector *foundSector, default_random_engine &generator);
    void createSectorGrid(int sectorSize);

private:
    char traveledSector[10][10];

    void placeObjectInSector(char objectIcon, Sector *foundSector, default_random_engine &generator);

    int generateRandomPosition(Sector *foundSector, default_random_engine &generator);
};


#endif //PLANET_EXPRESS_SECTORCONTROLLER_H
