//
// Created by da0ma on 10/16/2026.
//

#ifndef CSC_275_TEST1_KENO_GAME_H
#define CSC_275_TEST1_KENO_GAME_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "KenoNumbers.h"
#include "Player.h"

/* Placing this text in all headers:
    Having private variables that others can't 'see' but can use via doing #include is a form of encapsulation.

    Having private variables in the classes that you can't change from outside (without following the 'rules' of the class)
    as well as only being able to 'get' them from a certain function makes these a form on encapsulation.
*/

class Game {
private:
    KenoNumbers m_keno;
    Player m_player;
    std::vector <int> m_matches;
public:
    Game();
    void printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers);
    void displayResults();
    void playGame();
};


#endif //CSC_275_TEST1_KENO_GAME_H
