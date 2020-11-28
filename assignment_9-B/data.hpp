/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Assignment 9-B
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: Practice allocating and reallocating arrays with
        dynamic memory.
*/

#ifndef data_H
#define data_H

using std::unique_ptr;

// copy copies data from an array into a unique pointer
// pointing to an array.
// Precondition: an array of int containing the original data.
//      Also give the size of the array.
// Postcondition: returns a unique_ptr to an array holding the
//      data. This array is the same size as the original.
unique_ptr<int[]> copy(int data[], int size)
{
    // Define a unique_ptr smart pointer, pointing
    // to a dynamically allocated array of integers.
    // A unique_ptr is a small, fast, move-only smart
    // pointer usually used for managing resources
    // with exclusive ownership semantics
    unique_ptr<int[]> copied(new int[size]);

    for (int i = 0; i < size; ++i)
    {
        copied[i] = data[i];
    }

    return copied;
}

// shift copies data from one array into another, shifting the
// elements one position to the right.
// Precondition: a unique pointer to an array of int to hold
//      the copied and shifted data, and another unique pointer
//      to an array of int containing the original data. Also
//      give the size of the array containing the original data.
// Postcondition: the first array holds the data from the second
//      shifted one element to the right. Its size is one larger
//      than the original array, and the first element is zero.
void shift(unique_ptr<int[]> shifted, unique_ptr<int[]> data,
        int size)
{
    if (size > 1)
    {
        shifted[0] = 0;

        for (int i = 0; i < size; ++i)
        {
            shifted[i+1] = data[i];
        }
    }

    return;
}

#endif
