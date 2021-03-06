#include "read_header.h"
#include "earthquake.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int MonthtoInteger(string MM)
{
    if (MM == "01") return 1;
    if (MM == "02") return 2;
    if (MM == "03") return 3;
    if (MM == "04") return 4;
    if (MM == "05") return 5;
    if (MM == "06") return 6;
    if (MM == "07") return 7;
    if (MM == "08") return 8;
    if (MM == "09") return 9;
    if (MM == "10") return 10;
    if (MM == "11") return 11;
    if (MM == "12") return 12;
    exit(EXIT_FAILURE);
}

enum months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

string monthtostring(months M)
{
    if (M == January  )  return  "January";
    if (M == February )  return  "February";
    if (M == March    )  return  "March";
    if (M == April    )  return  "April";
    if (M == May      )  return  "May";
    if (M == June     )  return  "June";
    if (M == July     )  return  "July";
    if (M == August   )  return  "August";
    if (M == September)  return  "September";
    if (M == October  )  return  "October";
    if (M == November )  return  "November";
    if (M == December )  return  "December";
    exit(EXIT_FAILURE);
}

void Fail(ofstream &logfile, string failtype)     // Handles any error in the header
{
    cout    << "Error: " << failtype << "\n";
    logfile << "Error: " << failtype << "\n";
    logfile.flush();
    exit(EXIT_FAILURE);
}

string Header::PassInput(ifstream &IF, ofstream &logfile, ofstream &outputfile)
{
    
    Earthquake eq;
    
    string ID, date;
    IF >> ID;
    IF >> date;
    eq.set_id(ID);
    eq.set_date(date);
    
    string temp = "Invalid Data Length";
    if (eq.CheckDateLength() == false) Fail(logfile, temp);
    
    string tempstring;
    for (int i = 0; i <= 9; i++)    // Checks each position in the data for correct variable type
    {
        if (i == 2 || i == 5)
        {
            temp = "Invalid Date Separators";
            string temp2 = eq.GetDateSubStr(i, temp) ;
            if(eq.CheckDateSeperators(temp2)== false) Fail(logfile, temp);
        } else
        {
            temp = "Non-Number in Date";
            if(eq.CheckDateValidity(i) == false) Fail(logfile, temp);
        }
    }
    
    temp = "Date Seperators are not the same";
    if(eq.CheckDateSeperators2(2,5) == false) Fail(logfile, temp);
    
    string M, D, Y;
    eq.MDY(M,D,Y);
    int intmonth = atoi(M.c_str());
    int intday = atoi(D.c_str());
    int intyear = atoi(Y.c_str());
    
    months month;
    month = (months)intmonth;
    
    temp = "Invalid Month";
    if (eq.CheckMonthRange(intmonth) == false) Fail(logfile, temp);
    
    temp = "Invalid Day";
    if (eq.CheckDayRange(intday) == false) Fail(logfile, temp);
    
    temp = "Invalid Year";
    if (eq.CheckYearRange(intyear) == false) Fail(logfile, temp);
    
    string monthstring = monthtostring(month);
    
    temp = "Invalid Day/Month Combination";
    if (eq.MonthDayComboCheck(intday, intmonth) == false) Fail(logfile, temp);
    
    string timetime;
    IF >> timetime;
    eq.set_time(timetime);
    
    temp = "Invalid Time Length";
    if (eq.CheckTimeLength() == false) Fail(logfile, temp);
    
    string expVar;
    for (int i = 0; i <= 11; i++)     // Checks each position in the time for correct variable type
    {
        if (i == 2 || i == 5)
        {
            temp = "Invalid Time Seperator";
            eq.GetTimeSubStr(i, tempstring);
            expVar = ":";
            if(eq.CheckTimeSeperators(tempstring, expVar) == false) Fail(logfile, temp);
        } else if (i == 8)
        {
            temp = "Invalid Time Seperator";
            eq.GetTimeSubStr(i, tempstring);
            expVar = ".";
            if(eq.CheckTimeSeperators(tempstring, expVar) == false) Fail(logfile, temp);
        } else
        {
            temp = "Non-Number in Time";
            if(eq.CheckTimeValidity(i) == false) Fail(logfile, temp);
        }
    }
    
    temp = "Time Seperators are not the same";
    if (eq.CheckDateSeperators2(2,5) == false) Fail(logfile, temp);
    
    string TZone;
    IF >> TZone;
    temp = "Invalid Time Zone Length";
    eq.set_time_zone(TZone);
    if (eq.CheckTimeZoneLength() == false) Fail(logfile, temp);
    
    string HH, MM, SS;
    eq.HMS(HH,MM,SS);
    int inthour = atoi(HH.c_str());
    int intminute = atoi(MM.c_str());
    int intsecond = atoi(SS.c_str());
    
    temp = "Invalid Hour";
    if (eq.CheckHourRange(inthour) == false) Fail(logfile, temp);
    
    temp = "Invalid Minute";
    if (eq.CheckMinuteRange(intminute) == false) Fail(logfile, temp);
    
    temp = "Invalid Second";
    if (eq.CheckSecondRange(intsecond) == false) Fail(logfile, temp);
    
    temp = "Invalid Day/Month Combination";
    if (eq.MonthDayComboCheck(intday, intmonth) == false) Fail(logfile, temp);
    
    temp = "Invalid Time Zone Entry";
    if (eq.CheckTimeZoneEntries() == false) Fail(logfile, temp);
    
    eq.set_eq_name(IF);
    
    double Longitude, Latitude, Depth;
    
    double LO, LA, DE;
    IF >> LO;
    IF >> LA;
    IF >> DE;
    Longitude = eq.set_longitude(LO);
    Latitude = eq.set_latitude(LA);
    Depth = eq.set_depth(DE);
    
    string magtype;
    IF >> magtype;
    temp = "Invalid Magnitude Type";
    if (eq.set_mag_type(magtype) == false) Fail(logfile, temp);
    
    float magmag;
    IF >> magmag;
    temp = "Negative Magnitude";
    if (eq.mag(magmag) == false) Fail(logfile, temp);
    
    eq.HeaderOutput(outputfile, D, monthstring, Y);
    
    return ID;
}