#ifndef PLANET_EXPRESS_UNIVERSECONTROLLER_H
#define PLANET_EXPRESS_UNIVERSECONTROLLER_H

#include "../models/Universe.h"

using namespace std;
class UniverseController{

public:
    void scanSectors(Universe &universe, default_random_engine &generator);
    Sector * searchSector(Universe &universe, char* chosenSectorNumber);

private:
    bool validateSector(Universe &universe, Sector *selectedSector);
};

#endif //PLANET_EXPRESS_UNIVERSECONTROLLER_H
