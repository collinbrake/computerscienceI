/*
    COPYRIGHT (C) 2017 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Lab 3, Data Validation
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: This program is designed to validate one user input to be of the correct
        type (int) and within the correct range (2 - Inf). It does not use the input,
        and the purpose is strictly to practice data validation and provide useful
        validation code for later projects.
*/

#include <iostream> // for input-output stream operations
#include <iomanip>  // for providing parametric manipulators operations
#include <limits>   // for providing elements with the characteristics of arithmetic types

using std::cout;
using std::cin;

int main()
{
    double organisms = 0.00;    // to hold the number of organisms

    bool loopFlag = true;   // control flag for the loop

    do
    {
        cout << "Enter the starting number of organisms: "; // output steam a message
        cin >> organisms;                                   // input stream a variable

        // Do not accept a number less than 2 for the
        // starting size of the population.
        if (cin.fail() || organisms < 2)    // if construct, short-circuit test 2 conditions
        {
            cout << "The starting number of organisms must be a valid number that is "
                << "at least 2.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            loopFlag = false;   // end the loop by setting our while condition to false
        }
    }
    while(loopFlag);    // iterate the loop while the flag is true (incorrect user input)
        
    return 0;
}