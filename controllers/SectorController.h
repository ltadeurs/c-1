#ifndef PLANET_EXPRESS_SECTORCONTROLLER_H
#define PLANET_EXPRESS_SECTORCONTROLLER_H


#include "../models/Sector.h"
#include "../view/ConsoleView.h"

using namespace std;
class SectorController{

public:
    void travelToSector(Sector &currentSector, default_random_engine &generator, ConsoleView &consoleView);
    void createSectorGrid(Sector &currentSector);

private:
    void placeObjectInSector(char objectIcon, Sector &currentSector, default_random_engine &generator);

    int generateRandomPosition(Sector &currentSector, default_random_engine &generator);
};


#endif //PLANET_EXPRESS_SECTORCONTROLLER_H
