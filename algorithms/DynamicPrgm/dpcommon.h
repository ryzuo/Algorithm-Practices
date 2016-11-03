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
    SCRPAEUP_COMBINATION,
    COIN_COLLECT
};

inline void DisplayDPProblems()
{
    std::cout
        << (int)DynPrgmProblems::COIN_ROW
        << ". Pick up maximum amount of money in a row of n coins, in which the values are not"
        << " necessarily distinct." << std::endl
        << "     And no two coins adjacent in the initial row can be picked up."
        << std::endl;
    
    std::cout
        << (int)DynPrgmProblems::SCRPAEUP_COMBINATION
        << ". Assume we have plenty of collection of coins, of which" << std::endl
        << "     the values are 10, 20, 50 cents. Now we want to make" << std::endl
        << "     1 dollar, how many combination are there to achive it?" << std::endl
        << "     Now expanding the problem, how about scrape up 5 dollars or even more?" << std::endl
        << "     How about if there are more types of coins of different denomination? Like 10, 20, 30, 50, etc."
        << std::endl;

    /*
    std::cout
        << (int)DynPrgmProblems::COIN_COLLECT
        << ""
        << std::endl;
    */
}

void RunDP(void);
void RunCoinGames(int);

#endif
