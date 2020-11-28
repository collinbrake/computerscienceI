/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Assignment 9-B
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: Practice allocating and reallocating arrays with
        dynamic memory.
*/

#include <iostream>
#include <memory>
#include "data.hpp"
#include "display.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::unique_ptr;

int main()
{
    const int SIZE = 5;
    int myNumbers[SIZE] = {18, 27, 3, 14, 95};

    // Copy the data to the unique pointer
    unique_ptr<int[]> copied = copy(myNumbers, SIZE);

    // Display the original data
    display(copied, SIZE);

    // shift one element to the right
    unique_ptr<int[]> shifted(new int[SIZE + 1]);
    shift(shifted, copied, SIZE);

    // Display the copy
    display(shifted, SIZE+1);

    return 0;
}
