#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include "Constants.h"
#include "Board.h"
#include "Player.h"
#include "Enums.h"
#include <random>
#include <ctime>
#include <vector>

class Game {
private:
    Board gameBoard;
    Board gameBoard2;
    Player bot;
    Player human;

public:

    void setShips();

    bool setShipsAuto();

    bool getNextTurn();

    bool playGame();

    int gameCondition();

    void startGame();

    void printStateOfGame();

    bool getNextTurnAuto();

    static void whatShipIsSunk(int shipCounter);

};


#endif //MAIN_CPP_GAME_H
