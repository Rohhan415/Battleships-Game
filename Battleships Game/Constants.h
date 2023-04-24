
#ifndef MAIN_CPP_CONSTANTS_H
#define MAIN_CPP_CONSTANTS_H

#include <string>
#include <vector>

using namespace std;

const int boardSize = 10;
const int numberOfShips = 5;
const int numberOfShipSquares = 20;
const int shipSizes[numberOfShips]{6, 5, 4, 3, 2};

const char shipNotHit = 'O';
const char shipHit = 'X';
const char hiddenShip = 'S';
const char water = '*';
const char aircraftCarrierChar = 'A';
const char battleshipChar = 'B';
const char destroyerChar = 'D';
const char submarineChar = 'S';
const char patrolBoatChar = 'P';


#endif //MAIN_CPP_CONSTANTS_H
