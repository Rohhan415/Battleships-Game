
#include "Ship.h"

Ship::Ship(int shipSize) {
    this -> shipSet;
    this -> shipSquaresTab;
    for (int i = 0; i < numberOfShips; i++){
        for (int j = 0; j <shipSize; ++j) {
            shipSquaresTab[i][j] = shipNotHit;
            isSunk = false;
        }

    }
}

bool Ship::setPoint(int cordX, int cordY, int orientations) {
    point coordinate = {static_cast<orientation>(orientations), cordX, cordY};
    if (points.empty()) {
        points.push_back(coordinate);
        shipSet = true;

        return true;
    } else {
        if (orientations == horizontal) {
            if (points.back().cordY == cordY) {
                if ((points.back().cordX == cordX + 1 || points.back().cordX == cordX - 1)) {
                    if (points.size() >= 2 && points.at(points.size() - 2).cordX == cordX) {
                        return false;
                    }
                    points.push_back(coordinate);
                    shipSet = true;
                    return true;
                }
            }
        } else {
            if (points.back().cordX == cordX) {
                if ((points.back().cordY == cordY + 1 || points.back().cordY == cordY - 1)) {
                    if (points.size() >= 2 && points.at(points.size() - 2).cordY == cordY) {
                        return false;
                    }
                    points.push_back(coordinate);
                    shipSet = true;
                    return true;
                }

            }
        }
        return false;
    }

}

bool Ship::setPointAuto(int cordX, int cordY, int orientations) {
    point coordinate = {static_cast<orientation>(orientations), cordX, cordY};
    points.push_back(coordinate);
    shipSet = true;
    return true;
}

bool Ship::recordHit(int moveX, int moveY, int shipCounter) {
    for (int i = 0; i < shipSizes[shipCounter]; ++i) {
        if (points.at(i).cordX == moveX && points.at(i).cordY == moveY) {
            points.at(i).isHit = true;
            isSunk = isShipDestroyed(shipCounter);
            return true;
        }
    }
    return false;


}
bool Ship:: isShipDestroyed(int shipCounter){
    for (int i = 0; i <shipSizes[shipCounter] ; ++i) {
       if(!points.at(i).isHit){
           return false;
       }
    }
    return true;
}





bool Ship::isShipSunk() const {
    return isSunk;
}


