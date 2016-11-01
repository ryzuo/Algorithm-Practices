#include "dpcommon.h"
#include "CoinGames.h"

void RunDP(void)
{
    int pId;
    
    std::cout << "Choose the problem to run:" << std::endl;
    DisplayDPProblems();
    std::cout << ">> ";
    std::cin >> pId;
 
    switch(pId)
    {
        case (int)DynPrgmProblems::COIN_ROW:
        case (int)DynPrgmProblems::COIN_COMBINATION:
        case (int)DynPrgmProblems::COIN_COLLECT:
            RunCoinGames(pId);
            break;
        default:
            std::cout << "Unkown problem ID." << std::endl;
            break;
    }
}

void RunCoinGames(int pid)
{
    switch(pid)
    {
        case (int)DynPrgmProblems::COIN_ROW:
            MaxAmountOfCoinRow();
            break;
        case (int)DynPrgmProblems::COIN_COMBINATION:
            break;
        case (int)DynPrgmProblems::COIN_COLLECT:
            break;
        default:
            break;
    }
}
