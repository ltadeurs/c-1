#ifndef PLANET_EXPRESS_SECTOR_H
#define PLANET_EXPRESS_SECTOR_H

class Sector {
public:
    int size = 10;
    char sectorNumber[3];
    char sectorContent[10][10];
    int ast;
    int enc;
    int pla;
    int xPos;
    int yPos;
    bool shipIsPresent = false;
};

#endif //PLANET_EXPRESS_SECTOR_H
