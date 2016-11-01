#include "common.h"
#include "CoinGames.h"

/* Coin-Row: A row of coins, values are not necessarily
 * distinct, pickup maximum amount of money subject, no
 * two coins adjacent in the initial row can be picked up.
 * */
int MaxAmountOfCoinRow()
{
    std::string arrFile;
    int *amt = nullptr;
    int *oa = nullptr;
    int len, max;
    
    std::cout << "Enter the array file name: ";
    cin >> arrFile;
    
    std::vector<int> vOrig = BuildIntArrayFromFile(arrFile);
    len = vOrig.size();
    amt = new int[len+1];

    oa = vOrig.data();

    amt[0] = 0;
    amt[1] = oa[0];

    for(int i=2; i<len+1; ++i)
    {
        int tmp = oa[i-1] + amt[i-2];
        amt[i] = (tmp > amt[i-1]) ? tmp : amt[i-1];
    }

    max = amt[len];

    for(int i=0; i< len+1; ++i)
    {
        std::cout << "The max amount money of picking up in "
            << i
            << " coins is "
            << amt[i]
            << std::endl;
    }

    delete[] amt;

    return max;
}

