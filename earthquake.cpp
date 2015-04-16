#include "earthquake.h"

void Earthquake::set_id(string &ID)
{
    eyedee = ID;
}

string Earthquake::get_id()
{
    return eyedee;
}


// sabber 

// Functions to check time (ss, mm, hh) validity

// Checks that time seperators are individually valid
bool Earthquake::CheckTimeSeperators(string tempS, string VarExp)
{
    if (tempS.compare(VarExp) != 0) return false;
    return true;
}

// Checks that only numbers are used in the time
bool Earthquake::CheckTimeValidity(int place)
{
    if (!isdigit(time[place])) return false;
    return true;
}


void Earthquake::set_time(string timetime)
{
    time = timetime;
}

// this function ensures that,  only numbers are used in the data
void Earthquake::GetTimeSubStr(int ii, string &tempS)
{
    tempS = time.substr(ii,1);
}

bool Earthquake::CheckTimeLength()
{
    if (time.length() != 12) return false;
    return true;
}

bool Earthquake::CheckHourRange(int h)
{
    if (h > 23) return false;
    return true;
}

bool Earthquake::CheckMinuteRange(int m)
{
    if (m > 59) return false;
    return true;
}

bool Earthquake::CheckSecondRange(int s)
{
    if (s > 59) return false;
    return true;
}


// This function set earthquake name

void Earthquake::set_eq_name(ifstream &IF)
{
    int check = 1, check2 = 1;
    string Name = "", Ename;
    while(check == 1)
    {
        IF >> Name;
        if (check2 == 1)
        {
            Ename = Name;
            check2 = 0;
        } else
        {
            Ename = Ename + " " + Name;
        }
        if(IF.peek() == '\n') check = 0;
    }
    earthquake_name = Ename;
}


// This function checks the validity of magnitude type

bool Earthquake::set_mag_type(string magtypemagtype)
{
    changetoupper(magtypemagtype);
    if(magtypemagtype == "ML")
    {
        magnitude_type = ML;
        return true;
    } else if (magtypemagtype == "MS")
    {
        magnitude_type = MS;
        return true;
    } else if (magtypemagtype == "MB")
    {
        magnitude_type = MB;
        return true;
    } else if (magtypemagtype == "MW")
    {
        magnitude_type = MW;
        return true;
    } else
    {
        return false;
    }
}


// Get Earthquake magnitude type for output
string Earthquake::getMagType()
{
    if (magnitude_type == ML) return "ML";
    if (magnitude_type == MS) return "MS";
    if (magnitude_type == MB) return "MB";
    if (magnitude_type == MW) return "MW";
    exit(EXIT_FAILURE);
}
