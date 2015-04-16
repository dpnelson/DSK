
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Header
{
public:
    string PassInput(ifstream &IF, ofstream &logfile, ofstream &OF);
};