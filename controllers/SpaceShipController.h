#ifndef PLANET_EXPRESS_SPACESHIPCONTROLLER_H
#define PLANET_EXPRESS_SPACESHIPCONTROLLER_H

#include "../models/Sector.h"
#include "../models/Universe.h"
#include "../models/SpaceShip.h"
#include "../view/ConsoleView.h"

class SpaceShipController {

public:
    void placeShip(Universe &universe, Sector *foundSector, ConsoleView &consoleView);
    void travelShip(Universe &universe, Sector &currentSector, ConsoleView &consoleView, bool inSector);
    void moveShip(Universe &universe, Sector &currentSector, int direction, bool &inSector);

    Sector getShipCurrentSector();
    bool getShipOutOfBounds();

private:
    SpaceShip spaceShip;
};


#endif //PLANET_EXPRESS_SPACESHIPCONTROLLER_H
