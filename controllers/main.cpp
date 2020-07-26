#include <random>
#include <chrono>
#include "UniverseController.h"
#include "InputController.h"
#include "SectorController.h"
#include "SpaceShipController.h"


int main() {

    // controllers
    UniverseController universeController;
    InputController inputController;
    SectorController sectorController;
    SpaceShipController spaceShipController;

    // views
    ConsoleView consoleView;

    // objetcs
    Universe universe;
    bool gameLoop = true;
    enum gamestate {
        HQ_State, Sector_State
    };
    gamestate currentState = HQ_State;


    // random generator
    std::default_random_engine generator;
    const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator.seed(seed);

    while (gameLoop) {

        Sector currentSector;
        if (currentState == HQ_State) {
            // generate universe
            consoleView.clear();
            universeController.scanSectors(universe, generator);

            // wait for input
            char *chosenSectorNumber = inputController.getChosenSector();
            Sector *foundSector = universeController.searchSector(universe, chosenSectorNumber);

            // retry if false input
            while (foundSector == nullptr) {
                chosenSectorNumber = inputController.getChosenSector();
                foundSector = universeController.searchSector(universe, chosenSectorNumber);
            }

            // travel in Universe
            spaceShipController.placeShip(universe, foundSector, consoleView);
            spaceShipController.travelShip(universe, currentSector, consoleView, false);
            currentSector = spaceShipController.getShipCurrentSector();
            if(!spaceShipController.getShipOutOfBounds()) {
                currentState = Sector_State;
            }
        }

        if (currentState == Sector_State) {

            sectorController.travelToSector(currentSector, generator, consoleView);

            // travel in sector
            spaceShipController.travelShip(universe, currentSector, consoleView, true);

        }
    }

}
