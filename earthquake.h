
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

using namespace std;

enum TypeofMag {
    ML,
    MS,
    MB,
    MW
};

class Earthquake
{
public:
    
    void set_id(string &ID);
    string get_id();
    
    void set_date(string datedate);
    string GetDateSubStr(int ii, string &tempS);
    bool CheckDateLength();
    bool CheckMonthRange(int mon);
    bool CheckDayRange(int day);
    bool CheckYearRange(int year);
    bool MonthDayComboCheck(int day, int month);
    bool CheckDateSeperators(string tempS);
    void MDY(string &MM, string &DD, string &YY);
    bool CheckDateValidity(int place);
    bool CheckDateSeperators2(int aa, int bb);

    void set_time(string timetime);
    void GetTimeSubStr(int ii, string &tempS);
    bool CheckTimeLength();
    bool CheckHourRange(int h);
    bool CheckMinuteRange(int m);
    bool CheckSecondRange(int s);
    bool CheckTimeSeperators(string tempS, string VarExp);
    bool CheckTimeValidity(int place);
    
    void set_time_zone(string &TZone);
    bool CheckTimeZoneLength();
    bool CheckTimeZoneEntries();
    void HMS(string &H, string &M, string &S);
    void get_eqTimeZone(ifstream &IF);

    void set_eq_name(ifstream &IF);

    double set_longitude(double longitudelong);
    double set_latitude(double latitudelat);
    double set_depth(double depthd);
    
    bool set_mag_type(string magtypemagtype);
    string getMagType();
    
    void changetoupper(string &temp2);

    float mag(float &magmag);
    bool Check_Mag();
    
    void HeaderOutput(ofstream &OF, string DD, string MM, string YY);
    void printout(ofstream &OF, string SN, string NetC, string SCab, string ITab, string O);
private:
    string eyedee;
    string date;
    string time;
    string timezone;
    string earthquake_name;
    double longitude;
    double latitude;
    double depth;
    TypeofMag magnitude_type;
    float magnitude;
};
