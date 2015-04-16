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

string Station::getNC()
{
    if (NC == CE) return  "CE";
    if (NC == CI) return  "CI";
    if (NC == FA) return  "FA";
    if (NC == NP) return  "NP";
    if (NC == WR) return  "WR";
    exit(EXIT_FAILURE);
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


bool Station::CheckSC(string StatCode)
{
    int check = 0;
    // Ensures Station code is either 3 or 5 characters long
    if(StatCode.length() != 3 && StatCode.length() != 5)
    {
        check = 1;
    } else
    {   // Ensures code is all numbers if 5 characters long
        if (StatCode.length() == 5)
        {
            int num = 4;
            for (int w = 0; w <= num; w++)
            {
                if(!isdigit(StatCode[w]))
                {
                    check = 1;
                }
            }
        } else
        {
            int num = 2;
            for (int w = 0; w <= num; w++)
            {
                if(!isalpha(StatCode[w]))
                {
                    check = 1;
                }
                
                string temp = StatCode;
                string temp1 = temp;
                changetoupper(temp);
                
                if (temp != temp1)
                {
                    check = 1;
                }
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

void Station::SetSC(string check)
{
    SN = check;
}


string Station::getSN()
{
    string last = SN;
    return last;
}

string Station::getBT()
{
    if (BT == LONGPERIOD)  return "L";
    if (BT == SHORTPERIOD) return "B";
    if (BT == BROADBAND)   return "H";
    exit(EXIT_FAILURE);
}

