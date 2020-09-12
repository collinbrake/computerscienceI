/*
  Pgm: ASSGN2-B  Name: Collin Brake
  Purpose: This program takes 10 whole numbers as user input and
  outputs their sum, the sum of all entered numbers greater than
  0, and the sum of all entered numbers less than 0.
  Copyright 2020 by Collin Brake.
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter 10 whole numbers, one at a time.\n";

    int numberArray[10];
    for (uint i = 0; i < 10; i++)
    {
        cin >> numberArray[i];
    }

    int sumAll = 0, sumGreater0 = 0, sumLess0 = 0;
    int number = 0;
    for (uint i = 0; i < 10; i++)
    {
        number = numberArray[i];
        sumAll += number;
        if (number > 0)
        {
            sumGreater0 += number;
        }
        if (number < 0)
        {
            sumLess0 += number;
        }
    }

    cout << "Sum of all numbers entered: " << sumAll << endl
        << "Sum of all numbers greater than 0: " << sumGreater0 << endl
        << "Sum of all numbers less than 0: " << sumLess0 << endl;

    return 0;
}