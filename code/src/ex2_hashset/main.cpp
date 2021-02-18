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
#include <unordered_set>

using std::cout;

typedef std::unordered_set<int> IntHashSet;



//void printHeader()
//{
//    cout << ""
//}


void printHashSet(const IntHashSet& s)
{
    cout << '{';
    for (int el : s)
        cout << el << ", ";
    cout << '}';
}

// Prints meta-information toghether with data
void printHashSetWithMeta(const IntHashSet& s, int newEl)
{
    cout << s.size()  << " els: ";
    printHashSet(s);
    cout << "\n\tNumber of buckets: " << s.bucket_count()
         << "\n\tSize of buckets: [";
    for (size_t i = 0; i < s.bucket_count(); ++i)
        cout << s.bucket_size(i) << ", ";
    cout << "]";

    cout << "\n\tBucket number for new el: " << s.bucket(newEl);
    cout << "\n\tLoad factor: " << s.load_factor();
    cout << "\n\tMax Load factor: " << s.max_load_factor();


//    cout << "\n\tBucket number for corresponding el: {";
//    for (size_t i = 0; i < s.size(); ++i)
//            cout << s.bucket(i) << ", ";
//    cout << "}";

    cout << '\n';
}

void insertAndPrintWithMeta(IntHashSet& s, int newEl)
{
    s.insert(newEl);
    printHashSetWithMeta(s, newEl);
}

void intHashSetSample1()
{
    IntHashSet s;

    cout << "The maximum number of buckets according to library limitations: "
         << s.max_bucket_count() << '\n';

    //printHeader();

    //printHashSet(s);
    printHashSetWithMeta(s, 0);

    // add some elements { 1, -1, 2 , -2 , 2, 3, 0, -5, 6 }
    s.insert(1);
    printHashSetWithMeta(s, 1);

    insertAndPrintWithMeta(s, -2);
    insertAndPrintWithMeta(s, 2);
    insertAndPrintWithMeta(s, -1);
    insertAndPrintWithMeta(s, 2);
    insertAndPrintWithMeta(s, 3);
    insertAndPrintWithMeta(s, 0);
    insertAndPrintWithMeta(s, -5);
    insertAndPrintWithMeta(s, -6);

    cout << '\n';
}



int main()
{
    intHashSetSample1();
    return 0;
}


