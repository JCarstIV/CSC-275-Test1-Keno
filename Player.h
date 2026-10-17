//
// Created by da0ma on 10/16/2026.
//

#ifndef CSC_275_TEST1_KENO_PLAYER_H
#define CSC_275_TEST1_KENO_PLAYER_H
#include <vector>
#include <iostream>
#include <algorithm>


/* Placing this text in all headers:
    Having private variables that others can't 'see' but can use via doing #include is a form of encapsulation.

    Having private variables in the classes that you can't change from outside (without following the 'rules' of the class)
    as well as only being able to 'get' them from a certain function makes these a form on encapsulation.
*/


class Player {
private:
    std::vector <int> m_playerNumbers;
public:
    void inputPlayerNumbers();
    std::vector <int> getPlayerNumbers();
    void printPlayerNumbers();
    void clearPlayerNumbers();
};


#endif //CSC_275_TEST1_KENO_PLAYER_H
