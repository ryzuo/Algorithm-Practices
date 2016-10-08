#ifndef _COMMON_H
#define _COMMON_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum class Problem
{
    SORTING,
    TREE,
    HASH,
    OTHER
};

enum class SortingMethods
{
    INSERTION = 101,
    BUBBLE,
    SELECTION,
    MERGE,
    QUICK,
    HEAP
};

enum class OtherProblems
{
    SOUNDEX = 501
};

inline void DisplaySortingMethods()
{
    std::cout
        << (int)SortingMethods::INSERTION << ". Insertion Sort" << std::endl
        << (int)SortingMethods::BUBBLE << ". Bubble Sort" << std::endl
        << (int)SortingMethods::SELECTION << ". Selection Sort" << std::endl
        << (int)SortingMethods::MERGE << ". Merge Sort" << std::endl
        << (int)SortingMethods::QUICK << ". Quick Sort" << std::endl
        << (int)SortingMethods::HEAP << ". Heap Sort" << std::endl;
}

inline void DisplayOtherProblems()
{
    std::cout
        << (int)OtherProblems::SOUNDEX << ". Soundex (a phonetic algorithm for indexing names by sound)" << std::endl;
}

vector<int> BuildIntArrayFromFile(string filename);

#endif
