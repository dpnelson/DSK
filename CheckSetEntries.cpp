
#include "CheckSetEntries.h"
#include "station.h"
#include "earthquake.h"

#include <list>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

//khademul
void print2(ofstream &LF, string texty, int n)
{
    cout << texty << n << "\n";
    LF   << texty << n << "\n";
}

void backslash(ofstream &LF, string ret)
{
    cout << ret;
    LF   << ret;
}

void printout(string ID, ofstream &out, string NetC, string SN, string SCab, string ITab, char O)
{
    out << ID << "." << NetC << "." << SN << "." << SCab << ITab << O << "\n";
}


void Set::CSE(ifstream &IF, ofstream &logfile, ofstream &OF, string ID) {
    
    Earthquake eq;
    Station st;
    list<Station> stats;
    Station temp;
    int countbad = 0;
    int totsignals = 0;
    int validentries = 0, numentries = 0, changer;
    string NetCode, StatCode, TypeBand, TypeInst, Orient;
    
    while (IF >> NetCode)
    {
        
        IF >> StatCode;
        IF >> TypeBand;
        IF >> TypeInst;
        IF >> Orient;
        
        numentries++;
        changer = 0;
        int go = 0, numerr = 0;
        
        if(go == 0)
        {
            if(st.CheckNC(NetCode) == false)
            {
                numerr++;
                st.BadEntry(logfile, numentries, changer, "Network Code.");
            } else
            {
                temp.SetNC(NetCode);
            }
            if (go == 0)
            {
                if(st.CheckSC(StatCode) == false)
                {
                    numerr++;
                    st.BadEntry(logfile, numentries, changer, "Station Code.");
                } else
                {
                    temp.SetSC(StatCode);
                }
                if(go == 0)
                {
                    if(st.CheckBT(TypeBand) == false)
                    {
                        numerr++;
                        st.BadEntry(logfile, numentries, changer, "Band Type.");
                    } else
                    {
                        temp.SetBT(TypeBand);
                    }
                    if(go == 0)
                    {
                        if(st.CheckIT(TypeInst) == false)
                        {
                            numerr++;
                            st.BadEntry(logfile, numentries, changer, "Instrument Type.");
                        } else
                        {
                            temp.SetIT(TypeInst);
                        }
                        if(go == 0)
                        {
                            if(st.CheckOR(Orient) == false)
                            {
                                numerr++;
                                st.BadEntry(logfile, numentries, changer, "Orientation.");
                            } else
                            {
                                temp.SetOR(Orient);
                            }
                            if (numerr == 0)
                            {
                                stats.push_back(temp);
                                validentries++;
                                int LenOrient = (int)Orient.length();
                                totsignals += LenOrient;
                            } else
                            {
                                backslash(logfile, "\n");
                                countbad++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    OF << totsignals << "\n";
