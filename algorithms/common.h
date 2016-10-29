#ifndef _COMMON_H
#define _COMMON_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#ifdef __CSTRING_SOL
#define AS_STRING(x) x
#else
#define AS_STRING(x) std::move(x)
#endif

enum class Problem
{
    SORTING,
    STRING,
    LIST,
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

enum class StringProblems
{
    REVERSE = 344  // Leetcode #344
};

enum class ListProblems
{
    REVERSE = 206    // Leetcode #206
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

vector<int> BuildIntArrayFromFile(string filename);

inline void DisplayStringProblems()
{
    std::cout
        << (int)StringProblems::REVERSE 
        << ". Reverse String(LeetCode problem #344): Returns the input string as reversed."
        << std::endl;
}

inline void DisplayListProblems()
{
    std::cout
        << (int)StringProblems::REVERSE
        << ". Reverse a Linked List(LeetCode problem #206): Reversed a singly linked list."
        << std::endl;
}

inline void DisplayOtherProblems()
{
    std::cout
        << (int)OtherProblems::SOUNDEX
        << ". Soundex (a phonetic algorithm for indexing names by sound)"
        << std::endl;
}

#endif
