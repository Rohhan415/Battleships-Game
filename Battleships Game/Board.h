#ifndef MAIN_CPP_BOARD_H
#define MAIN_CPP_BOARD_H

#include "Constants.h"
#include "Ship.h"
#include "Enums.h"

#include <iostream>
#include <vector>

using namespace std;

class Board {
private:

    char board[boardSize][boardSize];
    vector<Ship> shipVector;

public:
    Board();

    void printBoard();

    bool placeShips(int cordX, int cordY, int shipCounter, int horizontal, bool autoPlacement);

    bool isWater(int cordX, int cordY,bool orientation, int shipCounter);

    static bool isOutOfBounds(int cordX, int cordY);

    bool isFitting(int cordX, int cordY, int orientation, int shipCounter,bool autoPlacement);

    bool isFittingRight(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement);

    bool isFittingLeft(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement);

    bool isFittingDown(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement);

    bool isFittingUp(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement);

    bool placeShipsAuto(int cordX, int cordY, int shipCounter, int fittingOrientation);

    bool recordHit (int cordX, int cordY);

    bool isShotAttempted(int cordX, int cordY);

    int getNumberOfHits();

};

#endif //MAIN_CPP_BOARD_H
