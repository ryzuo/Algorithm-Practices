#ifndef __SORT_H
#define __SORT_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
std::vector<T> insertion_sort(std::vector<T>&& v)
{
    int size = v.size();

    for(int i=1; i < size; ++i) {
        auto key = v[i];
        int j = i - 1;
        
        // starts with one precedent(aka v[j]) of key
        // if it's larger than key(aka v[j+1]), move its
        // position one step forward, then look back to 2
        // steps more of the next element, make comparison
        // , and so on, untill we find the element is NOT
        // larger than the "key" or we already reach the heading
        // element of the array, we stop and settle down the 
        // "key" value at the current position
        while( (j > -1) && (v[j] > key) ) {
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = key;
    }

    return v;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T>&& v);

template<typename T>
std::vector<T> bubble_sort(std::vector<T>&& v);

template<typename T>
std::vector<T> quick_sort(std::vector<T>&& v);

template<typename T>
std::vector<T> heap_sort(std::vector<T>&& v);

#endif
