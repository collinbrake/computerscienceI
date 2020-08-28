/* Lab 1: main.cpp
   Author: Collin Brake
   cmb361@zips.uakron.edu
   Purpose: Demonstration of a simple program
   Copyright 2020 by Collin Brake */

#include <iostream>

int main()
{
    using std::cout;
    using std::endl;

    cout << "Calculate total pay and output" << endl;

    int payrate = 7;
    int hours = 40;
    int totalPay = payrate*hours;
    cout << "Total pay: $" << totalPay << ".00" << endl;

    return 0;
}