#include "earthquake.h"

void Earthquake::set_id(string &ID)
{
    eyedee = ID;
}

string Earthquake::get_id()
{
    return eyedee;
}

// khademul

// function to make sure only numbers are used in the data
string Earthquake::GetDateSubStr(int ii, string &tempS)
{
    tempS = date.substr(ii,1);
    return tempS;
}

bool Earthquake::CheckDateLength()
{
    if (date.length() != 10) return false;
    return true;
}

bool Earthquake::CheckMonthRange(int mon)
{
    if (mon < 1 || mon > 12) return false;
    return true;
}

bool Earthquake::CheckDayRange(int day)
{
    if (day < 1 || day > 31) return false;
    return true;
}

bool Earthquake::CheckYearRange(int year)
{
    if (year > 2015) return false;
    return true;
}

//khademul

// This function makes sure that the day of the month and month of the year combination is valid
bool Earthquake::MonthDayComboCheck(int day, int month)
{
    switch (month)
    {
        case 2:
            if (day > 28)
            {
                return false;
                break;
            }
        case 4: case 6: case 9: case 11:
            if (day == 31)
            {
                return false;
                break;
            }
        default:
            return true;
    }
}

//khademul
// This function obtains month, day, and year from earthquake date
void Earthquake::MDY(string &MM, string &DD, string &YY)
{
    MM = date.substr(0,2);
    DD = date.substr(3,2);
    YY = date.substr(6,4);
}

// Individual date separator check
bool Earthquake::CheckDateSeperators(string tempS)
{
    if (tempS.compare("/") != 0 && tempS.compare("-") != 0) return false;
    return true;
}

// Number check in the date
bool Earthquake::CheckDateValidity(int place)
{
    if (!isdigit(date[place])) return false;
    return true;
}

// Same date separator check
bool Earthquake::CheckDateSeperators2(int aa, int bb)
{
    if (date[aa] != date[bb]) return false;
    return true;
}

void Earthquake::set_date(string datedate)
{
    date = datedate;
}

// Number check in the time
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

void Earthquake::set_time_zone(string &TZone)
{
    timezone = TZone;
}

bool Earthquake::CheckTimeZoneLength()
{
    if (timezone.length() != 3) return false;
    return true;
}

bool Earthquake::CheckTimeZoneEntries()     // Checks that only letters are used in the time zone
{
    for (int i = 0; i < 3; i++)
    {
        if(!isalpha(timezone[i])) return false;
    }
    return true;
}

void Earthquake::HMS(string &H, string &M, string &S)     // Acquires hour, minute, and second from earthquake time
{
    H = time.substr(0,2);
    M = time.substr(3,2);
    S = time.substr(6,2);
}

void Earthquake::changetoupper(string &temp2)
{
    for (unsigned i = 0; i < temp2.length(); i++)
    {
        if (isalpha(temp2[i]))
        {
            temp2[i] = toupper(temp2[i]);
        }
    }
}

double Earthquake::set_longitude(double longitudelong)
{
    longitude = longitudelong;
    return longitude;
}

double Earthquake::set_latitude(double latitudelat)
{
    latitude = latitudelat;
    return latitude;
}

double Earthquake::set_depth(double depthd)
{
    depth = depthd;
    return depth;
}

float Earthquake::mag(float &magmag)
{
    magnitude = magmag;
    return magnitude;
}

void Earthquake::HeaderOutput(ofstream &OF, string DD, string MM, string YY)
{
    string StrMagType = getMagType();
    OF <<  "# " << DD << " " << MM << " " << YY << " " << time << " " << timezone << " ";
    OF << StrMagType << " " << magnitude << " " << earthquake_name << " ";
    OF << "[" << eyedee << "] " << "(" << longitude << ", " << latitude << ", " << depth << ")\n";
}

