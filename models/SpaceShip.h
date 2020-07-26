#ifndef PLANET_EXPRESS_SPACESHIP_H
#define PLANET_EXPRESS_SPACESHIP_H

class SpaceShip {
public:
    char shipIcon = 'P';
    Sector currentSector;
    bool outOfBounds = false;
};

#endif //PLANET_EXPRESS_SPACESHIP_H
