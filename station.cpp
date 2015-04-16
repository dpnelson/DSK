#include "station.h"

#include <list>
#include <iostream>

void Station::changetoupper(string &temp2)
{
    for (unsigned i = 0; i < temp2.length(); i++)
    {
        if (isalpha(temp2[i]))
        {
            temp2[i] = toupper(temp2[i]);
        }
    }
}

void Station::BadEntry(ofstream &LF, int z, int &change, string errortype) 
{
    if (change == 0)
    {
        change = 1;
        cout << "Entry # " << right << setw(5) << z << " ignored.";
        LF   << "Entry # " << right << setw(5) << z << " ignored.";
    }
    cout << " Invalid " << errortype;
    LF   << " Invalid " << errortype;
}

string Station::getNC()
{
    if (NC == CE) return  "CE";
    if (NC == CI) return  "CI";
    if (NC == FA) return  "FA";
    if (NC == NP) return  "NP";
    if (NC == WR) return  "WR";
    exit(EXIT_FAILURE);
}