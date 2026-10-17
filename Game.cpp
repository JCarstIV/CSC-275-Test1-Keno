//
// Created by da0ma on 10/16/2026.
//

#include "Game.h"


Game::Game() {
    m_keno;
    m_player;
    /* The above two variables are pulled from the 'Player.h' and 'KenoNumbers.h' classes.
        The idea is that the 'end programmer' wouldn't have to worry about how the Player or KenoNumber class works,
        and they're just able to use them. This is the form of abstraction.
    */

    m_matches;
    playGame();
}

void Game::printMatches(std::vector<int> playerPicks, std::vector<int> kenoNumbers) {

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 20; j++) {
            if(m_player.getPlayerNumbers().at(i) == m_keno.getKenoNumbers().at(j)) {
                m_matches.push_back(m_player.getPlayerNumbers().at(i));
            }
        }
    }

    std::cout << "You matched: ";
    std::sort(m_matches.begin(), m_matches.end());
    for (auto i:m_matches) {
        std::cout << i << " ";
    }

    if (m_matches.size() > 0) {
        std::cout<<"\nMatching " << m_matches.size() << " of 20 numbers wins ";
        switch (m_matches.size()){
            case 10:
                std::cout<<"the GRAND PRIZE of $250,000";
                break;
            case 9:
                std::cout << "$2,500";
                break;
            case 8:
                std::cout<<"$250";
                break;
            case 7:
                std::cout<<"$50";
                break;
            case 6:
                std::cout<<"$10";
                break;
            case 5:
                std::cout<<"$5";
                break;
            default:
                std::cout<<"$0. Sorry, better luck next time.";
        }
    }
    else {
        std::cout << "\nSorry, you didn't have any matches.";
    }
}

void Game::displayResults() {
    std::cout <<"\n----------------------------------Results----------------------------------\n";

    m_keno.printKenoNumbers();
    m_player.printPlayerNumbers();
    printMatches(m_player.getPlayerNumbers(),m_keno.getKenoNumbers());

}

void Game::playGame() {
    char again = 'y';

    do {
        std::cout << "\nTo play Keno, select 10 unique (no repeats) numbers in the range of 1-80.\n\n";
        std::cout << "Let's Play Keno!\n\n";

        m_player.inputPlayerNumbers();
        m_keno.generateNumbers();
        displayResults();

        std::cout << "\n\nPlay again? (y/n): ";
        std::cin >> again;
        m_player.clearPlayerNumbers();
        m_keno.clearKenoNumbers();
        m_matches.clear();
    } while (tolower(again) == 'y');
    std::cout << "\nTHANKS FOR PLAYING!!\n";
}