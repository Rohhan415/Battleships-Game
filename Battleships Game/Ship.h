#ifndef MAIN_CPP_SHIP_H
#define MAIN_CPP_SHIP_H

#include "Constants.h"
#include "Enums.h"
#include <iostream>


class Ship {

private:


    bool isSunk;
    bool shipSet;
    char shipSquaresTab[5][6];
    struct point {
        orientation shipOrientation;
        int cordX;
        int cordY;
        bool isHit;
    };
    vector<point> points;
public:


// Methods
    Ship(int shipSize);

    bool setPoint(int cordX, int cordY, int horizontal);


    bool recordHit(int moveX, int moveY, int shipCounter);

    bool isShipSunk() const;

    bool setPointAuto(int cordX, int cordY, int orientations);

    bool isShipDestroyed(int shipCounter);


};

#endif //MAIN_CPP_SHIP_H
