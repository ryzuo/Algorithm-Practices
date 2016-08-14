#include "common.h"
#include <fstream>
#include <cstdlib>

std::vector<int> BuildIntArrayFromFile(std::string filename)
{
    std::vector<int> voi;
    ifstream fin(filename);

    for(std::string num; std::getline(fin, num, ','); )
    {
        voi.push_back(std::stoi(num));
    }

    fin.close();

    return voi;
}
