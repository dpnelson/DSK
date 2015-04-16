#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

using namespace std;

enum NetworkCode {
    CE,
    CI,
    FA,
    NP,
    WR
};

enum BandTypes {
    LONGPERIOD,
    SHORTPERIOD,
    BROADBAND
};

enum InstrumentTypes {
    HIGHGAIN,
    LOWGAIN,
    ACCELEROMETER
};

class Station
{
public:
    
    void changetoupper(string &temp2);
    
    void BadEntry(ofstream &LF, int z, int &change, string errortype);
    
    bool CheckNC(string &check);
    void SetNC(string check);
    
    bool CheckSC(string StatCode);
    void SetSC(string check);

    bool CheckBT(string &TB);
    void SetBT(string TB);

    bool CheckIT(string &INST);
    void SetIT(string INST);

    bool CheckOR(string ORE);
    void SetOR(string check);

    string getNC();
    
    string getSN();
    string getBT();

    string getIT();
    string getOR();
    
    
private:
    NetworkCode NC;
    string SN;
    BandTypes BT;
    InstrumentTypes IT;
    string OR;
};
