#include "Board.h"
#include "Game.h"
#include <iostream>

Board::Board() {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j)
            board[i][j] = water;
    }
    for (int i = 0; i < numberOfShips; i++)
        shipVector.emplace_back(shipSizes[i]);

}


void Board::printBoard() {
    cout << "  0 1 2 3 4 5 6 7 8 9\n";
    for (int i = 0; i < boardSize; ++i) {
        cout << i << " ";
        for (int j = 0; j < boardSize; ++j) {
            cout << board[j][i] << " ";
        }
        cout << "\n";
    }

}

bool Board::placeShips(int cordX, int cordY, int shipCounter, int horizontal, bool autoPlacement) {


    if (shipCounter <= aircraftCarrierSize) {
        if (shipVector[shipCounter].setPoint(cordX, cordY, horizontal)) {
            if (!autoPlacement) {
                board[cordX][cordY] = aircraftCarrierChar;
            } else {
                board[cordX][cordY] = hiddenShip;
                return true;
            }
            return true;
        } else {
            return false;
        }
    } else {
        if (shipCounter <= battleshipSize) {
            if (shipVector[shipCounter].setPoint(cordX, cordY, horizontal)) {
                if (!autoPlacement) {
                    board[cordX][cordY] = battleshipChar;
                } else {
                    board[cordX][cordY] = hiddenShip;
                    return true;
                }
                return true;
            } else {
                return false;
            }
        } else {
            if (shipCounter <= destroyerSize) {
                if (shipVector[shipCounter].setPoint(cordX, cordY, horizontal)) {
                    if (!autoPlacement) {
                        board[cordX][cordY] = destroyerChar;
                    } else {
                        board[cordX][cordY] = hiddenShip;
                        return true;
                    }
                    return true;
                } else {
                    return false;
                }
            } else {
                if (shipCounter <= submarineSize) {
                    if (shipVector[shipCounter].setPoint(cordX, cordY, horizontal)) {
                        if (!autoPlacement) {
                            board[cordX][cordY] = submarineChar;
                        } else {
                            board[cordX][cordY] = hiddenShip;
                            return true;
                        }
                        return true;
                    } else {
                        return false;
                    }
                } else {
                    if (shipCounter <= patrolBoatSize) {
                        if (shipVector[shipCounter].setPoint(cordX, cordY, horizontal)) {
                            if (!autoPlacement) {
                                board[cordX][cordY] = patrolBoatChar;
                            } else {
                                board[cordX][cordY] = hiddenShip;
                                return true;
                            }
                            return true;
                        } else {
                            return false;
                        }
                    }
                }
            }
        }
    }

}

bool Board::placeShipsAuto(int cordX, int cordY, int shipCounter, int fittingOrientation) {

    if (fittingOrientation == fitsRight) {
        int cordXRight = cordX;
        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (shipVector[shipCounter].setPointAuto(cordXRight, cordY, fittingOrientation)) {
                board[cordXRight][cordY] = hiddenShip;
            }
            cordXRight++;
        }
        return true;
    } else if (fittingOrientation == fitsLeft) {
        int cordXLeft = cordX;
        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (shipVector[shipCounter].setPointAuto(cordXLeft, cordY, fittingOrientation)) {
                board[cordXLeft][cordY] = hiddenShip;
            }
            cordXLeft--;
        }

        return true;
    } else if (fittingOrientation == fitsUp) {
        int cordYUp = cordY;

        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (shipVector[shipCounter].setPointAuto(cordX, cordYUp, fittingOrientation)) {
                board[cordX][cordYUp] = hiddenShip;
            }
            cordYUp--;
        }
        return true;
    } else if (fittingOrientation == fitsDown) {
        int cordYDown = cordY;

        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (shipVector[shipCounter].setPointAuto(cordX, cordYDown, fittingOrientation)) {
                board[cordX][cordYDown] = hiddenShip;
            }
            cordYDown++;
        }
        return true;
    } else {
        return false;
    }
}


bool Board::isWater(int cordX, int cordY, bool orientation, int shipCounter) {

    if (board[cordX][cordY] == water) {

        return true;
    } else {
        return false;
    }
}

bool Board::isOutOfBounds(int cordX, int cordY) {
    if (cordX >= boardSize || cordX < 0 || cordY >= boardSize || cordY < 0) {
        return true;
    } else {
        return false;
    }

}

bool Board::isFitting(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement) {
    if (orientation == vertical) {
        int cordYFront = cordY;
        int cordYBack = cordY;
        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (board[cordX][cordYFront] != water || isOutOfBounds(cordX, cordYFront)) {
                cordYFront++;
            }
            for (int j = 0; j < shipSizes[shipCounter]; ++j) {
                cordYBack--;
                if (board[cordX][cordYBack] != water || isOutOfBounds(cordX, cordYBack)) {
                    return false;

                }
            }

        }
        return true;
    } else if (orientation == horizontal) {
        int cordXFront = cordX;
        int cordXBack = cordX;
        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (board[cordXFront][cordY] != water || isOutOfBounds(cordXFront, cordY)) {
                for (int j = 0; j < shipSizes[shipCounter]; ++j) {
                    if (board[cordXBack][cordY] != water || isOutOfBounds(cordXBack, cordY)) {
                        return false;
                    }
                    cordXBack--;
                }
                return true;
            }
            cordXFront++;
        }
        return true;

    }
}

bool Board::isFittingRight(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement) {
    if (orientation == horizontal) {
        int cordXFront = cordX;
        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (board[cordXFront][cordY] != water || isOutOfBounds(cordXFront, cordY)) {
                return false;

            }
            cordXFront++;
        }

    }
    return true;
}

bool Board::isFittingDown(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement) {
    if (orientation == vertical) {
        int cordYFront = cordY;

        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (board[cordX][cordYFront] != water || isOutOfBounds(cordX, cordYFront)) {
                return false;
            }
            cordYFront++;
        }
    }
    return true;
}

bool Board::isFittingLeft(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement) {
    if (orientation == horizontal) {
        int cordXBack = cordX;
        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (board[cordXBack][cordY] != water || isOutOfBounds(cordXBack, cordY)) {
                return false;
            }
            cordXBack--;
        }

    }
    return true;
}

bool Board::isFittingUp(int cordX, int cordY, int orientation, int shipCounter, bool autoPlacement) {
    if (orientation == vertical) {
        int cordYBack = cordY;

        for (int i = 0; i < shipSizes[shipCounter]; ++i) {
            if (board[cordX][cordYBack] != water || isOutOfBounds(cordX, cordYBack)) {
                return false;
            }
            cordYBack--;
        }
    }
    return true;
}

bool Board::recordHit(int cordX, int cordY) {
    int shipCounter = -1;
    for (int i = 0; i < numberOfShips; ++i) {
        shipCounter++;

        if (shipVector[i].recordHit(cordX, cordY, shipCounter)) {
            board[cordX][cordY] = shipHit;
            if (shipVector[i].isShipSunk()) {
               Game::whatShipIsSunk(i);
            }
            return true;
        } else {
            board[cordX][cordY] = shipNotHit;
        }
    }
    return false;
}



bool Board::isShotAttempted(int cordX, int cordY) {
    if (board[cordX][cordY] == shipHit || board[cordX][cordY] == shipNotHit) {
        return true;
    } else { return false; }
}

int Board::getNumberOfHits() {
    int counter = 0;

    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            if (board[i][j] == shipHit)
                counter++;

    return counter;
}
