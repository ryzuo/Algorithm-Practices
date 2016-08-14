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
    HASH 
};

enum class SortingMethods
{
    INSERTION = 1001,
    MERGE,
    BUBBLE,
    QUICK,
    HEAP,
    SELECTION
};

inline void DisplaySortingMethods()
{
    std::cout
        << (int)SortingMethods::INSERTION << ". Insertion Sort" << std::endl
        << (int)SortingMethods::MERGE << ". Merge Sort" << std::endl
        << (int)SortingMethods::BUBBLE << ". Bubble Sort" << std::endl
        << (int)SortingMethods::QUICK << ". Quick Sort" << std::endl
        << (int)SortingMethods::HEAP << ". Heap Sort" << std::endl
        << (int)SortingMethods::SELECTION << ". Selection Sort" << std::endl;
}

vector<int> BuildIntArrayFromFile(string filename);

#endif
