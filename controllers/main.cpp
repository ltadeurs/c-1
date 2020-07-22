#include <random>
#include <chrono>
#include "UniverseController.h"
#include "InputController.h"
#include "SectorController.h"
#include "SpaceShipController.h"
#include "../view/ConsoleView.h"


int main() {

    std::default_random_engine generator;
    const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator.seed(seed);

    UniverseController universeController;
    InputController inputController;
    SectorController sectorController;
    SpaceShipController spaceShipController;

    Universe universe;
    universeController.scanSectors(universe, generator);

    ConsoleView consoleView;

    char* chosenSectorNumber = inputController.getChosenSector();
    Sector *foundSector = universeController.searchSector(universe, chosenSectorNumber);
    while (foundSector == nullptr){
        chosenSectorNumber = inputController.getChosenSector();
        foundSector = universeController.searchSector(universe, chosenSectorNumber);
    }

    consoleView.Clear();
    spaceShipController.placeShip(universe, foundSector);
    sectorController.travelToSector(foundSector, generator);

}
