#ifndef PLANET_EXPRESS_UNIVERSE_H
#define PLANET_EXPRESS_UNIVERSE_H

#include "Sector.h"

class Universe {
public:
    int size = 5;
    Sector UniverseSectors[5][5];
};

#endif //PLANET_EXPRESS_UNIVERSE_H
