#include "common.h"
#include "sort.h"
#include "funutil.h"
#include <unistd.h>
#include <fstream>
#include <iostream>

void Usage()
{
    std::cout << "run does not accept any argument." << std::endl
        << "Simply use \"run\" to launch" << std::endl;
}

Problem ChooseProblem()
{
    int pid;

    std::cout << "Choose the problem you want to run:" << std::endl
        << "0. Exit" << std::endl
        << "1. Sorting problems" << std::endl
        << "2. Tree problems" << std::endl
        << "3. Hash problems" << std::endl
        << "4. Other problems" << std::endl
        << ">> ";

    std::cin >> pid;
    switch(pid)
    {
        case 0:
            exit(0);
        case 1:
            return Problem::SORTING;
        case 2:
            return Problem::TREE;
        case 3:
            return Problem::HASH;
        case 4:
            return Problem::OTHER;
        default:
            cout << "Invalid choice, exit" << std::endl;
            exit(0);
    }
}

void RunSort()
{
    int mid;
    std::string arrFile;
    std::vector<int> sorted_voi;

    std::cout << "Enter the array file name: ";
    cin >> arrFile;
    std::cout << "Choose the sorting method:" << std::endl;
    DisplaySortingMethods();
    std::cout << ">> ";
    cin >> mid;
    
    std::vector<int> voi(std::move(BuildIntArrayFromFile(arrFile)));
    
    std::cout << "Before sort:" << std::endl;
    for(auto value : voi) {
        std::cout << value;
        if (value == *(--voi.end()))
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    // Do sorting 
    switch(mid) {
        case (int)SortingMethods::INSERTION:
            sorted_voi = insertion_sort<int>(std::move(voi));
            break;
        case (int)SortingMethods::BUBBLE:
            sorted_voi = bubble_sort<int>(std::move(voi));
            break;
        case (int)SortingMethods::SELECTION:
            sorted_voi = selection_sort<int>(std::move(voi));
            break;
        case (int)SortingMethods::MERGE:
            sorted_voi = merge_sort<int>(voi, 0, voi.size()-1);
            break;
        case (int)SortingMethods::QUICK:
            sorted_voi = quick_sort<int>(voi, 0, voi.size()-1);
            break;
        case (int)SortingMethods::HEAP:
            break;
        default:
            break;
    }

    std::cout << "After sorted:" << std::endl;
    for(auto value : sorted_voi) {
        std::cout << value;
        if (value == *(--sorted_voi.end()))
            std::cout << std::endl << std::endl;
        else
            std::cout << ", ";
    }
}

void RunTree()
{
}

void RunHash()
{
}

void RunSoundex()
{
    char srcName[20];
    std::string orgName;
    std::string nameListFile;
    std::vector<std::string> vNames;

    std::cout << "Enter the origin name:" << std::endl << ">> ";
    std::cin >> orgName;
    std::cout << "Enter the file name listing candidate names:\t" << std::endl << ">> ";
    std::cin >> nameListFile;

    std::ifstream is(nameListFile);

    while(is.getline(srcName, 20))
        vNames.push_back(srcName);

    GetSoundexNames(orgName, vNames);
}

void RunOthers()
{
    int prid;

    std::cout << "Choose the problem:" << std::endl;
    DisplayOtherProblems();
    std::cout << ">> ";
    std::cin >> prid;

    switch(prid)
    {
        case (int)OtherProblems::SOUNDEX:
            RunSoundex();
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 1) {
        Usage();
        exit(0);
    }

    while(true) {
        switch(ChooseProblem())
        {
            case Problem::SORTING:
                RunSort();
                break;
            case Problem::TREE:
                RunTree();
                break;
            case Problem::HASH:
                RunHash();
                break;
            case Problem::OTHER:
                RunOthers();
                break;
            default:
                break;
        }
    }

    return 0;
}

