
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

//khademul
void no_files(ofstream &log)
{
    
    cout << "No input files to process";
    log  << "No input files to process";
    
}

//function to open input file
void open_input(ifstream &IF, string IF2)
{
    IF.open(IF2.c_str());
    if ( !IF.is_open() )
    {
        cout << "Cannot open input file: "
             << IF2
             << endl;
        exit(EXIT_FAILURE);
    }
}

// Opens log and output files
void open_outputfiles(ofstream &file, string file2, string file3)
{
    file.open(file3.c_str());
    if ( !file.is_open() )
    {
        cout << "Cannot open " << file2 << "file: " << file3;
        file.flush();
        exit(EXIT_FAILURE);
    }
}

int OpenIPOP(ofstream &log, string &file, string &inputfilename, string &outputfilename, ifstream &input, ofstream &output)
{
    
    inputfilename = file + ".in";
    input.open(inputfilename.c_str());
    if ( !input.is_open() )
    {
        cout << inputfilename + " does not exist\n\n====\n\n";
        log  << inputfilename + " does not exist\n\n====\n\n";
		outputfilename = file + ".out";
		output.open(outputfilename.c_str());
        return 100;
    }

    return 10;
    
}

void printheader(ofstream &LF, string top)
{
    cout << top;
    LF   << top;
}

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
	
	printheader(logfile, "Finished all!");
    
    return 0;
    
}
