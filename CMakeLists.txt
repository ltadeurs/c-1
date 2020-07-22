cmake_minimum_required(VERSION 3.15)
project(Planet_express)

set(CMAKE_CXX_STANDARD 14)

add_executable(Planet_express controllers/main.cpp controllers/UniverseController.cpp controllers/UniverseController.h controllers/SectorController.cpp controllers/SectorController.h controllers/InputController.cpp controllers/InputController.h models/Sector.h models/Universe.h view/ConsoleView.cpp view/ConsoleView.h controllers/SpaceShipController.cpp controllers/SpaceShipController.h)