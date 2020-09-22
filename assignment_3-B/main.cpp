/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Assignment 3-B: Madlibs
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: The purpose of this program is for more practice with data
        input/output, flow of control, and good programming style. This
        program prompts the user for one random word or numerical value of
        each type specified, and then outputs a story with these random values
        inserted at specified locations.
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    // Declare and intialize the string and integer vars
    std::string name = "", noun = "", bodyPart = "", verb = "";
    int number = 0;

    // Prompt for each of the necessary inputs, one at a time.
    cout << "Enter a proper first name: ";
    cin >> name;
    cout << "Enter a plural noun: ";
    cin >> noun;
    cout << "Enter an arbitrary integer: ";
    cin >> number;
    cout << "Enter some part of the anatomy: ";
    cin >> bodyPart;
    cout << "Enter a verb: ";
    cin >> verb;

    // Output a story, using each of the random user inputs to
    // fill in a specified word or value and create a nonsensical
    // story.
    cout << "The famous explorer " << name << " had nearly given up a life-long quest\n"
        << "to find the Lost City of " << noun << " when one day the " << noun << endl
        << "found the explorer.\n\n"

        << "Surrounded by " << number << " " << noun << ", a tear came to " << name << "’s" << endl
        << bodyPart << ". After all this time, the quest was finally over.\n"
        << "And then, the " << noun << " promptly devoured " << name << ".\n\n"

        << "The moral of the story? Be careful what you " << verb << " for.\n"; 


    return 0;
}
