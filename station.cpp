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

//khademul
bool Station::CheckBT(string &TB)
{
    changetoupper(TB);
    if(TB == "LONG-PERIOD" || TB == "LONGPERIOD")
    {
        return true;
    } else if (TB == "SHORT-PERIOD" || TB == "SHORTPERIOD")
    {
        return true;
    } else if (TB == "BROADBAND")
    {
        return true;
    } else
    {
        return false;
    }
}

//khademul
void Station::SetBT(string TB)
{
    if(TB == "LONG-PERIOD" || TB == "LONGPERIOD" )
    {
        BT = LONGPERIOD;
    } else if (TB == "SHORT-PERIOD" || TB == "SHORTPERIOD")
    {
        BT = SHORTPERIOD;
    } else if (TB == "BROADBAND")
    {
        BT = BROADBAND;
    }
}

//khademul
bool Station::CheckIT(string &INST)
{
    changetoupper(INST);
    if(INST == "HIGH-GAIN" || INST == "HIGHGAIN")
    {
        return true;
    } else if (INST == "LOW-GAIN" || INST == "LOWGAIN")
    {
        return true;
    } else if (INST == "ACCELEROMETER")
    {
        return true;
    } else
    {
        return false;
    }
}

//khademul
void Station::SetIT(string INST)
{
    if(INST == "HIGH-GAIN" || INST == "HIGHGAIN")
    {
        IT = HIGHGAIN;
    } else if (INST == "LOW-GAIN" || INST == "LOWGAIN")
    {
        IT = LOWGAIN;
    } else if (INST == "ACCELEROMETER")
    {
        IT = ACCELEROMETER;
    }
}

//khademul
bool Station::CheckOR(string ORE)
{
    int check = 0, x = 0, length = 0;
    while (isalpha(ORE[x]) || isdigit(ORE[x]))
    {
        length++;
        x++;
    }
    if(length < 1 || length > 3) // Orientation characters check
    {
        check = 1;
    }
    int alphacount = 0, numbercount = 0;
    for (int g = 1; g <= length; g++)
    {
        if (isalpha(ORE[g-1]))
        {
            alphacount++;
        } else if (isdigit(ORE[g-1]))
        {
            numbercount++;
        } else
        {
            check = 1;
        }
    }
    
    if (alphacount != length && numbercount != length)
    {
        check = 1;
    }
    
    if (alphacount != 0)  // Orientation letters check
    {
        changetoupper(ORE);
        for (int c = 1; c <= length; c++)
        {
            string tempString = ORE.substr(c-1,1);
            if (tempString.compare("N") && tempString.compare("E") && tempString.compare("Z"))
            {
                check = 1;
            }
        }
    }
    
    if (numbercount != 0)  // Orientation numbers check
    {
        for (int c = 1; c <= length; c++)
        {
            string tempString = ORE.substr(c-1,1);
            if (tempString.compare("1") && tempString.compare("2") && tempString.compare("3"))
            {
                check = 1;
            }
        }
    }
    if (check == 1)
    {
        return false;
    } else
    {
        return true;
    }
}

//khademul
void Station::SetOR(string check)
{
    OR = check;
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

//khademul
string Station::getOR()
{
    
    return OR;
    
}

// Sabber 

bool Station::CheckNC(string &check)
{
    changetoupper(check);
    if(check == "CE")
    {
        return true;
    } else if (check == "CI")
    {
        return true;
    } else if (check == "FA")
    {
        return true;
    } else if (check == "NP")
    {
        return true;
    } else if (check == "WR")
    {
        return true;
    } else
    {
        return false;
    }
}


void Station::SetNC(string check)
{
    if(check == "CE")
    {
        NC = CE;
    } else if (check == "CI")
    {
        NC = CI;
    } else if (check == "FA")
    {
        NC = FA;
    } else if (check == "NP")
    {
        NC = NP;
    } else if (check == "WR")
    {
        NC = WR;
    }
}

//khademul

string Station::getIT()
{
    if (IT == HIGHGAIN)       return "H";
    if (IT == LOWGAIN)        return "L";
    if (IT == ACCELEROMETER)  return "N";
    exit(EXIT_FAILURE);
}

