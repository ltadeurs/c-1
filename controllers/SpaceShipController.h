#ifndef PLANET_EXPRESS_SPACESHIPCONTROLLER_H
#define PLANET_EXPRESS_SPACESHIPCONTROLLER_H


#include "../models/Sector.h"
#include "../models/Universe.h"

class SpaceShipController {

public:
    void placeShip(Universe &universe, Sector *foundSector);

    void listenForKeys();
};


#endif //PLANET_EXPRESS_SPACESHIPCONTROLLER_H
