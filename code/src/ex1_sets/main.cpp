////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 1: 
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       16.02.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
///  → Description
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>            // std::sort


typedef std::set<int, std::less<int> > IntSetLess;

void lessSample()
{
    IntSetLess s = { 2, 6, 4, 2, 7, -1, 0 };
    for (int el : s)
    {
        std::cout << el << ", ";
    }
}

typedef std::set<int, std::greater<int> > IntSetGreater;

void greaterSample()
{
    IntSetGreater s = { 2, 6, 4, 2, 7, -1, 0 };
    for (int el : s)
    {
        std::cout << el << ", ";
    }
}



bool myCompare(int lhv, int rhv)
{
    if ( (lhv < 0 && rhv < 0)
            || (lhv > 0 && rhv > 0) )
        return lhv < rhv;

    if (lhv < 0)
        return false;

    return true;
}


void myCompareSample()
{

    typedef std::set<int,
                     decltype(myCompare)* > IntSetMyCompare;

    IntSetMyCompare s( { 1, -1, 2 , -2 , 3, 0, -5, 6 }, myCompare);
    for (int el : s)
        std::cout << el << ", ";

}

typedef std::vector<int> IntVector;

void printIntVector(const IntVector& vec)
{
    for (int el : vec)
        std::cout << el << ", ";
}


void vectorSortingSample1()
{
    IntVector v = { 1, -1, 2 , -2 , 3, 0, -5, 6 };

    std::cout << "Before sorting: ";
    printIntVector(v);

    std::sort(std::begin(v), std::end(v));          // same as std::sort(v.begin(), v.end());
    std::cout << "\nAfter sorting: ";
    printIntVector(v);
}


void vectorSortingSample2()
{
    IntVector v = { 1, -1, 2 , -2 , 3, 0, -5, 6 };

    std::cout << "Before sorting: ";
    printIntVector(v);

    std::sort(std::begin(v), std::end(v), myCompare);          // use custom comparator
    std::cout << "\nAfter sorting: ";
    printIntVector(v);
}



int main()
{
//    lessSample();
//    std::cout << "\n\n";

//    greaterSample();
//    std::cout << "\n\n";

//    myCompareSample();
//    std::cout << "\n\n";

//    vectorSortingSample1();
//    std::cout << "\n\n";

    vectorSortingSample2();
    std::cout << "\n\n";

    return 0;
}


