#include <iostream>
#include <string>
#include <limits>
#include "iofun.h"

using namespace std;

// Prompt for an integer.  Force the user to give us a number
// or end the file.
int prompt_int(string prompt)
{
    int n;  //number

    //loop until we get a valid input
    for(;;) {
        //try to get the number
        cout << prompt;
        cin >> n;

        //if we succeed, or the input ends, return
        if(cin or cin.eof()) {
            return n;
        }

        //something went wrong
        cout << "Invalid entry. Please Try Again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
}


// Prompt the user for an integer within a given range
// only return valid output, or return on eof
int prompt_int_range(string prompt, int min, int max) 
{
    int n;  //number we read

    //loop until we get a valid input
    for(;;) {
        n = prompt_int(prompt);

        //return valid integers
        if(n >= min and n <= max) {
            return n;
        }

        //return on eof
        if(cin.eof()) {
            return n;
        }

        //print an error message
        cout << "Entry out of range.  Please try again." << endl;
    }
}



// Prompt for a dobule.  Force the user to give us a number
// or end the file.
double prompt_double(string prompt)
{
    double n;  //number

    //loop until we get a valid input
    for(;;) {
        //try to get the number
        cout << prompt;
        cin >> n;

        //if we succeed, or the input ends, return
        if(cin or cin.eof()) {
            return n;
        }

        //something went wrong
        cout << "Invalid entry. Please Try Again" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
}


// Prompt the user for an double within a given range
// only return valid output, or return on eof
double prompt_double_range(string prompt, double min, double max) 
{
    double n;  //number we read

    //loop until we get a valid input
    for(;;) {
        n = prompt_double(prompt);

        //return valid doubleegers
        if(n >= min and n <= max) {
            return n;
        }

        //return on eof
        if(cin.eof()) {
            return n;
        }

        //prdouble an error message
        cout << "Entry out of range.  Please try again." << endl;
    }
}
