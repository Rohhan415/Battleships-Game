#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "Enums.h"
#include "Constants.h"

class Player {
private:
    string name;
    int numberOfMisses;
    int numberOfHits;
public:
    int getNumberOfHits() const;

    void setNumberOfHits(int numberOfHits);

    int getNumberOfMisses() const;

    void setNumberOfMisses(int numberOfMisses);

    const string &getName() const;

    void setName(const string &name);

    Player();


};

#endif //MAIN_CPP_PLAYER_H
