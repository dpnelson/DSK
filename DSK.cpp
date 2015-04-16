
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#include "earthquake.h"
#include "station.h"
#include "read_header.h"
#include "CheckSetEntries.h"

using namespace std;


int main(int argc, char* argv[])
{
    
    string   inputfilename, outputfilename, logfilename;
    ifstream inputfile;
    ofstream logfile, outputfile;
    
    open_outputfiles(logfile, "log file", "darin.log");
    
    if (argc < 2) {
        no_files(logfile);
    } else {
        for (int i = 1; i < argc; i++) {
            string file = argv[i];
            if(OpenIPOP(logfile, file, inputfilename, outputfilename, inputfile, outputfile) == 10)
            {
                printheader(logfile, "Processing input file " + inputfilename + "\n");
                
                Header h;
                string EyeDee = h.PassInput(inputfile, logfile, outputfile);
                
                printheader(logfile, "Header read correctly!\n");
                
                Set s;
                s.CSE(inputfile, logfile, outputfile, EyeDee);
                
                printheader(logfile, "Finished " + inputfilename + "\n\n");
                printheader(logfile, "====\n\n");
            }
            outputfile.close();
            inputfile.close();
        }
    }
    
    return 0;
    
}
