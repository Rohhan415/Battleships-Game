#include "Game.h"

void Game::startGame() {
    cout << "Welcome to the battleships, set up your ships." << endl;
    cout << "Please enter your name/nickname: ";
    string playerName;
    cin >> playerName;
    human.setName(playerName);
    setShips();
    setShipsAuto();
    cout << "Ships are set, lets play a game!" << endl;
    printStateOfGame();
    playGame();
}

bool Game::playGame() {

    int firstMove;
    int currentTurn;
    cout << "Who will make the first move?" << endl;
    cout << "1. Player, 2. Computer" << endl;
    cin >> firstMove;

    if (firstMove == humanPlayer) {
        currentTurn = humanPlayer;

    } else {
        currentTurn = computerPlayer;
    }
    while (gameCondition() == unfinished) {
        if (currentTurn == humanPlayer) {
            getNextTurn();
            printStateOfGame();
        } else {
            getNextTurnAuto();
            printStateOfGame();
        }
        if (currentTurn == humanPlayer) {
            currentTurn = computerPlayer;
        } else {
            currentTurn = humanPlayer;
        }
    }
    if (gameCondition() == playerWon) {
        cout << "Congratulations, you win!!" << endl;
    } else {
        cout << "Computer win, better luck next time." << endl;
    }
    cout << "Here's some statistics: " << endl;
    cout << human.getName() << " hits:" << human.getNumberOfHits() << endl;
    cout << human.getName() << " misses:" << human.getNumberOfMisses() << endl;
    cout << "Computer hits:" << bot.getNumberOfHits() << endl;
    cout << "Computer misses: " << bot.getNumberOfMisses() << endl;
    cout << "Battleship game ended. Bye " << human.getName() << "!" << endl;
    return true;
}


void Game::setShips() {
    int moveX, moveY;
    int shipCounter = -1;
    int orientation;
    bool firstPlacement;
    bool autoPlacement = false;
    for (int i = 0; i < numberOfShips; ++i) {
        shipCounter++;
        firstPlacement = true;
        gameBoard.printBoard();
        cout << "Set ship's orientation: " << "\n" << "1.Horizontal 2. Vertical" << endl;
        do{
            cin >> orientation;
            if(!(orientation==horizontal || orientation==vertical)){
                cout << "Choose between 1.Horizontal 2. Vertical" << endl;
            }
        }
        while(orientation > 2 || orientation < 1);
        cout << endl;

        for (int j = 0; j < shipSizes[i]; ++j) {

            cout << "Set coordinate x: ";
            cin >> moveX;
            cout << "Set coordinate y: ";
            cin >> moveY;
            if (gameBoard.isOutOfBounds(moveX, moveY)) {
                cout << "Coordinates are out of bounds, pick number from 0 to " << boardSize - 1 << endl;
                j--;
            } else if (firstPlacement) {
                if (!gameBoard.isFitting(moveX, moveY, orientation, shipCounter, autoPlacement)) {
                    cout << "Ship is not going to fit, try different coordinates" << endl;
                    j--;
                } else if (!gameBoard.placeShips(moveX, moveY, shipCounter, orientation, autoPlacement)) {
                    cout << "Bad orientation of the ship or spaces between elements are to big" << endl;
                    j--;

                }
            } else if (!gameBoard.isWater(moveX, moveY, orientation, shipCounter)) {
                cout << "The coordinates have already been placed!" << endl;
                j--;
            } else if (!gameBoard.placeShips(moveX, moveY, shipCounter, orientation, autoPlacement)) {
                cout << "Bad orientation of the ship or spaces between elements are to big" << endl;
                j--;

            }
            firstPlacement = false;
        }


    }
}

bool Game::setShipsAuto() {
    int moveX, moveY, orientation, fittingOrientation;
    int shipCounter = -1;
    bool autoPlacement = true;
    srand(time(0));
    for (int i = 0; i < numberOfShips; ++i) {
        shipCounter++;
        orientation = rand() % 2 + 1;
        while (true) {
            moveX = rand() % 9 + 1;
            moveY = rand() % 9 + 1;

            if (orientation == horizontal) {

                if (gameBoard2.isFittingRight(moveX, moveY, orientation, shipCounter, autoPlacement)) {
                    fittingOrientation = fitsRight;
                    gameBoard2.placeShipsAuto(moveX, moveY, shipCounter, fittingOrientation);
                    break;
                } else if (gameBoard2.isFittingLeft(moveX, moveY, orientation, shipCounter, autoPlacement)) {
                    fittingOrientation = fitsLeft;
                    gameBoard2.placeShipsAuto(moveX, moveY, shipCounter, fittingOrientation);
                    break;
                } else {
                    shipCounter--;
                    i--;
                    break;

                }
            } else if (orientation == vertical) {
                if (gameBoard2.isFittingDown(moveX, moveY, orientation, shipCounter, autoPlacement)) {
                    fittingOrientation = fitsDown;
                    gameBoard2.placeShipsAuto(moveX, moveY, shipCounter, fittingOrientation);
                    break;
                } else if (gameBoard2.isFittingUp(moveX, moveY, orientation, shipCounter, autoPlacement)) {
                    fittingOrientation = fitsUp;
                    gameBoard2.placeShipsAuto(moveX, moveY, shipCounter, fittingOrientation);
                    break;
                }
            }

        }
    }
    return true;
}

bool Game::getNextTurn() {
    int moveX, moveY,hits =human.getNumberOfHits(), misses = human.getNumberOfMisses();

    bool goodMove = false;

    while (!goodMove) {
        cout << "Please enter location of desired shot:" << endl;
        cout << "moveX: ";
        cin >> moveX;
        cout << "moveY: ";
        cin >> moveY;
        cout << endl;
        if (gameBoard2.isShotAttempted(moveX, moveY)) {
            cout << "That move has already been attempted. Try different coordinates." << endl;
        } else if (gameBoard2.isOutOfBounds(moveX, moveY)) {
            cout << "Coordinates are out of bounds, pick number from 0 to " << boardSize - 1 << endl;
        } else if (gameBoard2.recordHit(moveX, moveY)) {
            cout << "Ship hit!" << endl;
            hits++;
            human.setNumberOfHits(hits);
            goodMove = true;
        } else {
            cout << "Miss!" << endl;
            misses++;
            human.setNumberOfMisses(misses);
            goodMove = true;
        }

    }
    return true;

}

bool Game::getNextTurnAuto() {
    int moveX, moveY, hits = bot.getNumberOfHits(), misses = bot.getNumberOfMisses();
    bool goodMove = false;
    srand(time(0));
    while (!goodMove) {
        moveX = rand() % 10;
        moveY = rand() % 10;
        if (!gameBoard.isShotAttempted(moveX, moveY)) {
            if (gameBoard.isOutOfBounds(moveX, moveY)) {
                cout << "Coordinates are out of bounds, pick number from 0 to " << boardSize - 1 << endl;
            } else if (gameBoard.recordHit(moveX, moveY)) {
                cout << "Ship hit!" << endl;
                hits++;
                bot.setNumberOfHits(hits);
                goodMove = true;
            } else {
                cout << "Miss!" << endl;
                misses++;
                bot.setNumberOfMisses(misses);
                goodMove = true;

            }
        }


    }
    return true;
}

int Game::gameCondition() {
    if (gameBoard2.getNumberOfHits() == numberOfShipSquares) {
        return playerWon;
    } else if (gameBoard.getNumberOfHits() == numberOfShipSquares) {
        return computerWon;
    } else {
        return unfinished;
    }

}

void Game::printStateOfGame() {
    cout << "YOUR BOARD: \n";
    gameBoard.printBoard();
    cout << "YOUR OPPONENT'S BOARD: \n";
    gameBoard2.printBoard();
    cout << endl << endl;
}

void Game::whatShipIsSunk(int shipCounter) {

    switch (shipCounter) {
        case aircraftCarrier:
        {
            cout << "Aircraft carrier has been sunk!!" << endl;
            break;
        }
        case battleship:
        {
            cout << "Battleship has been sunk!!"  << endl;
            break;
        }
        case destroyer:
        {
            cout << "Destroyer has been sunk!!"  << endl;
            break;
        }
        case submarine:
        {
            cout << "Submarine has been sunk!!"  << endl;
            break;
        }
        case patrolBoat:
        {
            cout << "Patrol boat has been sunk!!"  << endl;
            break;
        }



    }
}