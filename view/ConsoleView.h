#ifndef PLANET_EXPRESS_CONSOLEVIEW_H
#define PLANET_EXPRESS_CONSOLEVIEW_H
#include "../models/Universe.h"
#include "../models/SpaceShip.h"

class ConsoleView {

public:
    void clear();
    void drawUniverse(Universe &universe, SpaceShip &spaceShip);
    void drawSector(Sector &currentSector);

};


#endif //PLANET_EXPRESS_CONSOLEVIEW_H
