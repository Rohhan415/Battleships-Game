#ifndef MAIN_CPP_ENUMS_H
#define MAIN_CPP_ENUMS_H

enum shipNames {
    aircraftCarrier = 0, battleship, destroyer, submarine, patrolBoat
};


enum typeOfPlayer {
    humanPlayer = 1, computerPlayer
};

enum shipTypes {
    aircraftCarrierSize = 0, battleshipSize, destroyerSize, submarineSize, patrolBoatSize
};
enum orientation {
    horizontal = 1, vertical = 2
};
enum fittingOrientation {
    fitsRight, fitsLeft, fitsUp, fitsDown
};

enum gameState {
    playerWon, computerWon, unfinished
};


#endif //MAIN_CPP_ENUMS_H
