#include "common.h"
#include "CoinGames.h"

using namespace std;

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

    // Starts here
    amt[0] = 0;
    amt[1] = oa[0];

    for(int i=2; i<len+1; ++i)
    {
        int tmp = oa[i-1] + amt[i-2];
        amt[i] = (tmp > amt[i-1]) ? tmp : amt[i-1];
    }

    max = amt[len];

    // print out max amount of all sub problems.
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

/*
 * Assume we have plenty of collection of coins, of which
 * the values are 10, 20, 50 cents. Now we need to scrape
 * up 1 dollar, how many combination are there to achive it?
 * Apparently we have 10 different ways like following:
 *   1.  10*10
 *   2.  10*8 + 20
 *   3.  10*6 + 20*2
 *   4.  10*5 + 50
 *   5.  10*4 + 20*3
 *   6.  10*3 + 20 + 50
 *   7.  10*2 + 20*4
 *   8.  10 + 20*2 + 50
 *   9.  20*5
 *   10. 50*2
 * Plus, how about scrape up 5 dollars? And how about 10 dollars?
 * Enumerating will becoming unacceptable when the scale grows,
 * the way we solve this is using dynamic programmming.
 * */
int ScrapeUpCoins()
{
    int sum;    // Sum of the amount of money to make
    string arrFile;
    cout << "Enter the text file name lists all denomination of the coins: ";
    cin >> arrFile;
    vector<int> toc = BuildIntArrayFromFile(arrFile);  // Types of coins
    size_t numOfCoinsTypes = toc.size();      // The number of types of coins

    cout << "There are " << numOfCoinsTypes << " types of coins with following denomination:" << endl;
    for(int i=0; i<numOfCoinsTypes; ++i)
        cout << toc[i] << " ";
    cout << endl;
    
    cout << "Enter the sum number you want to make: ";
    cin >> sum;
   
    // An two dimensioned array, in which each element represents the
    // number of combinations of making sum[j](from 0 to sum) by using
    // heading i types of coins(TypesOfCoins[0...i(max to numOfCoinsTypes)]).
    // Initial all with 0, .
    vector<vector<int>> noc(numOfCoinsTypes+1, vector<int>(sum+1, 0));

    // Initialize all noc[i][0] = 1. For each sub problem noc[i], meaning
    // using head i types of coins, to make sum of 0 dollar, needs only one
    // combination - pick up none.
    for(int i=0; i <= numOfCoinsTypes; ++i)
        noc[i][0] = 1;

    for(int i=1; i <= numOfCoinsTypes; ++i)
    {
        for(int j=1; j <= sum; ++j)
        {
            for(int k=0; k <= j/toc[i-1]; ++k)
                noc[i][j] += noc[i-1][j-k*toc[i-1]];
        }
    }

    cout << "The combination is " << noc[numOfCoinsTypes][sum] << endl;
    return noc[numOfCoinsTypes][sum];
}

