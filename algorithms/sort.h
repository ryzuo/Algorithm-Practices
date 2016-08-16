#ifndef __SORT_H
#define __SORT_H

#include <iostream>
#include <vector>
#include <cmath>

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
std::vector<T> bubble_sort(std::vector<T>&& v)
{
    for(int i=0; i < v.size() - 1; ++i)
    {
        for(int j=0; j < v.size()-i-1; ++j)
        {
            if(v[j] > v[j+1])
            {
                T temp = v[j];
                v[j]= v[j+1];
                v[j+1] = temp;
            } // swap
        } // end of inner loop
    } // end of outer loop

    return v;
}

template<typename T>
std::vector<T> selection_sort(std::vector<T>&& v)
{
    for(int i=0; i< v.size() - 1; ++i)
    {
        int min = i;

        // inner loop finds out the minimum value among
        // the rest n-i elements, then swap this value
        // with the ith element.
        for(int j=i; j < v.size(); ++j)
        {
            if(v[j] < v[min])
                min = j;
        }
        T temp = v[i];
        v[i] = v[min];
        v[min] = temp;

        // Through out this, each round of the outer loop
        // will find out the minimum value among the rest
        // n-i elements, and put it to the ith heading of
        // the array.
    }

    return v;
}

template<typename T>
std::vector<T> merge(std::vector<T>& v, int begin, int mid, int end)
{
    int llen = mid - begin + 1;
    int rlen = end - mid;
    int lIdx = 0, rIdx = 0;
    int k = begin;

    vector<T> lv(llen);
    vector<T> rv(rlen);
    
    for(int i=0; i < llen; ++i)
        lv[i] = v[begin + i];

    for(int i=0; i < rlen; ++i)
        rv[i] = v[mid + 1 + i];

    while((lIdx < llen) && (rIdx < rlen))
    {
        if(lv[lIdx] < rv[rIdx])
            v[k++] = lv[lIdx++];
        else
            v[k++] = rv[rIdx++];
    }

    while(lIdx < llen)
        v[k++] = lv[lIdx++];

    while(rIdx < rlen)
        v[k++] = rv[rIdx++];

    return v;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T>& v, int begin, int end)
{
    if(begin >= end)
        return v;

    int mid = (begin + end)/2;
    
    merge_sort(v, begin, mid);
    merge_sort(v, mid+1, end);
    merge(v, begin, mid, end);

    return v;
}

template<typename T>
std::vector<T> quick_sort(std::vector<T>&& v);

template<typename T>
std::vector<T> heap_sort(std::vector<T>&& v);

#endif
