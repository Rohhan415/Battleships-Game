
#include "Player.h"

Player::Player() {
     name = "";
    numberOfHits = 0;
    numberOfMisses = 0;
}

int Player::getNumberOfMisses() const {
    return numberOfMisses;
}

void Player::setNumberOfMisses(int numberOfMisses1) {
    numberOfMisses = numberOfMisses1;
}

int Player::getNumberOfHits() const {
    return numberOfHits;
}

void Player::setNumberOfHits(int numberOfHits1) {
    numberOfHits = numberOfHits1;
}

const string &Player::getName() const {
    return name;
}

void Player::setName(const string &name) {
    Player::name = name;
}
