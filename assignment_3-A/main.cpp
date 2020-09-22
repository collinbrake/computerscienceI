/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Assignment 3-A: Rectangle Display
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: This program uses the character 'X' to draw a rectangle on the console.
        It takes as user input the width and height of the rectagle. The main purpose
        is for practice of basic input and output, flow of control, and data validation.
*/

#include <iostream>
#include <limits>

using std::cout;
using std::cin;

int main()
{
    // Take the width and height as user input after prompting
    int width = 0, height = 0;  // declare variables to hold the integers
    bool loopFlag = true;       // declare Boolean control flag for the loop
    do
    {
        cout << "Please enter two positive integers no greater than 75. Hit "
            << "Return after each entry.\n";
        cin >> width >> height;  // input stream the two variables
        if (cin.fail() || width > 75 || height > 75) // each input must be valid and less than or equal to 75
        {
            cout << "The two entries must be valid integers no greater than 75.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            loopFlag = false;   // end the loop by setting our while condition to false
        }
    }
    while(loopFlag);    // iterate the loop while the flag is true (incorrect user input)

    // Loop through each row of X's for the rectangle, and for each row
    // loop through each 'X' in the width and output it. Output a carriage
    // return after each row.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << 'X';
        }
        cout << std::endl;
    }

    return 0;
}
