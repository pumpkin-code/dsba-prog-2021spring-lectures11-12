/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       20.11.2019
 *
 *  Maps
 */

#include <iostream>
#include <map>

using std::cout;
using std::string;

typedef std::map<string, int> PersonSalaryMap;

PersonSalaryMap makePersonList()
{
    PersonSalaryMap pers;

    // inserting by pair
    pers.insert({"William Small", 34});
    pers.insert({"John Smith", 100});
    pers.insert({"Vanessa Mil", 78});
    pers.insert({"Mary Woo", 154});
    pers.insert({"Katy Bell", 96});

    // adding by []
    pers["Bill Johns"] = 17;

    // replacing by []
    pers["Vanessa Mil"] = 79;

    return pers;
}


void printPersonList(const PersonSalaryMap& lst)
{
    // iterating through the given map
    for(PersonSalaryMap::const_iterator it = lst.begin();
        it != lst.end();
        ++it)
    {
        // explicit approach
//        const std::pair<std::string, int>& cur = *it;
//        std::cout << cur.first << ": " << cur.second << "\n";

        // alternative (implicit) approach
        std::cout << it->first << ": " << it->second << "\n";
    }
}

// looks for a given person's name and return his/her salary if found, otherwise
// returns -1
int getSalary(const PersonSalaryMap& lst, const string& pers)
{
    // we can't use lst[pers], because it adds a new key-value pair
    // if there no exists a key equal to pers
    // use lst.find() instead
    PersonSalaryMap::const_iterator el = lst.find(pers);

    // if NO person is found, then el is equal to lst.end()
    if(el == lst.end())
        return -1;

    // if we reach this point, a person is found
    return el->second;
}


void increaseSalary(PersonSalaryMap& lst, const string& pers, int addSal)
{
    // now we use iterator because we are aiming to change a value through it
    PersonSalaryMap::iterator el = lst.find(pers);
    if(el == lst.end())
        return;                         // no person to increase salary for

    el->second += addSal;
}


int main()
{
    cout << "Hello world!\n\n";

    PersonSalaryMap lst = makePersonList();
    printPersonList(lst);

    // getting salary of some people
    int sal = getSalary(lst, "William Small");
    if(sal != -1)
    {
        cout << "\n\nThe salary of 'William Small' is " << sal << "\n";
    }

    sal = getSalary(lst, "Albert Enstein");
    if(sal == -1)
    {
        cout << "Albert Enstein doen't work with us, unfortunately!((\n\n";
    }

    // lets increase salary of Mr. William Small
    increaseSalary(lst, "William Small", 1000);
    printPersonList(lst);

    return 0;
}
