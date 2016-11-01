#ifndef _DP_COMMON_H
#define _DP_COMMON_H

#include <iostream>

enum class DynPrgmProblems
{
    /* Coin-Row: A row of coins, values are not necessarily
     * distinct, pickup maximum amount of money subject, no
     * two coins adjacent in the initial row can be picked up.
     * */
    COIN_ROW = 221,
    COIN_COMBINATION,
    COIN_COLLECT
};

inline void DisplayDPProblems()
{
    std::cout
        << (int)DynPrgmProblems::COIN_ROW
        << ". Pick up maximum amount of money in a row of n coins, in which the values are not"
        << " necessarily distinct." << std::endl
        << "  And no two coins adjacent in the initial row can be picked up."
        << std::endl;
    
    /*
    std::cout
        << (int)DynPrgmProblems::COIN_COMBINATION
        << ""
        << std::endl;

    std::cout
        << (int)DynPrgmProblems::COIN_COMBINATION
        << ""
        << std::endl;
    */
}

void RunDP(void);
void RunCoinGames(int);

#endif
