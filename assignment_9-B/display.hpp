/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Assignment 9-B
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: Practice allocating and reallocating arrays with
        dynamic memory.
*/

#ifndef display_H
#define display_H

using std::cout;
using std::endl;
using std::unique_ptr;

// display sends an array of integers to the console, one by
// one.
// Precondition: a unique_ptr smart pointer to an array of
//      integers.
// Postcondition: the contents of the array displayed on the
//      screen.
void display(unique_ptr<int[]> data, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    return;
}

#endif
