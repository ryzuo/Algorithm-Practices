#include <cmath>

#include "pstrings.h"
#include "common.h"


#ifdef __CSTRING_SOL

char *Reverse(char *source, size_t len)
{
    std::cout << "Using CString solution..." << std::endl;

    char tmpChr;
    int mid;

    if(CSTR_NTS == len)
        len = strlen(source);
    
    mid = floor(len/2);

    for(int i = 0, j = len-1; i < mid; ++i, --j)
    {
        tmpChr = source[i];
        source[i] = source[j];
        source[j] = tmpChr;
    }

    return source;
}

#else

std::string Reverse(std::string &&source)
{
    std::cout << "Using C++ string solution..." << std::endl;

    char tmpChr;
    int mid;
    size_t len = source.size();

    mid = floor(len/2);

    for(int i = 0, j = len-1; i < mid; ++i, --j)
    {
        tmpChr = source[i];
        source[i] = source[j];
        source[j] = tmpChr;
    }

    return source;
}

#endif

