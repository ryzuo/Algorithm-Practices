#include <cctype>
#include "funutil.h"

std::string soundex(std::string word)
{
    int targetLen = 4;
    std::string targetStr = "";

    short previous = 0;
    short current = 0;

    targetStr.push_back(word[0]);    // Retain the first letter
    int setLen = 1;

    for(auto chr : word)
    {
        if(setLen == 1)
            continue;

        chr = toupper(chr);
        switch(chr)
        {
            case 'A':
            case 'E':
            case 'H':
            case 'I':
            case 'O':
            case 'U':
            case 'W':
            case 'Y':
                current = 0;
                break;
            case 'B':
            case 'F':
            case 'P':
            case 'V':
                current = 1;
                break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
                current = 2;
                break;
            case 'D':
            case 'T':
                current = 3;
                break;
            case 'L':
                current = 4;
                break;
            case 'M':
            case 'N':
                current = 5;
                break;
            case 'R':
                current = 6;
                break;
            default:
                break;
        }

        if(current)    // Only non-zero valued letter shall ve retained, 0 will be discarded
        {
            if(previous != current)
            {
                targetStr.append(std::to_string(current));
                setLen++;
            }
        }

        previous = current;

        if(setLen == targetLen)    // Don't overhit the target string
            break;
    } // end of for loop

    if(setLen < targetLen)
        targetStr.append(targetLen - setLen, '0');

    std::cout << targetStr << std::endl;

    return targetStr;

} // end of soundex

void GetSoundexNames(std::string name, std::vector<std::string> vNames)
{
    std::string phoneticStr = soundex(name);
    for(auto candidate : vNames)
    {
        if(phoneticStr == soundex(candidate))
            std::cout << candidate << std::endl;
    }
}

