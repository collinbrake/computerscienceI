/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - Lab 05
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: This program is used for the University of Akron, Department of Computer Science Laboratories
        Goal: refactor main into functions
        examine each portion in main and analyze the code for refactoring
        Next build your function prototype
        Next build your function by copying and pasting the code from main, into your function
        repeat until complete
*/

#include <iostream>
#include <iomanip>

using namespace std; // forgive me for being lazy!

const double TAX_RATE = .05;

void getPrice(double& price);
// getPrice prompts the user for the price and stores the input in the passed var

void getNumber(int& num);
// getPrice prompts the user for the number purchased and stores the input in the passed var

void getSaleType(char& saleType);
// getSaleType prompts the user for the sale type ('W' for wholesale, 'R' for retail)
// and stores the input in the passed var

void calcTotal(double& total, char saleType, double price, int number);
// calcTotal calculates the total cost based on the sale type and stores the
// calculated value in the passed var

void dispTotal(double total, char saleType, double price, int number);
// dispTotal displays the total as well as all info used to calculate it

int main()
{
    char saleType;
    int number = 0;
    double price = 0, total = 0;

    getPrice(price);        // Get price of items
    getNumber(number);      // Get number purchased
    getSaleType(saleType);  // Get the sale type
    
    calcTotal(total, saleType, price, number);  // Calculate total cost from all inputs

    dispTotal(total, saleType, price, number);  // Display total on console
    
    return 0;
}

// precondition: pass a variable to hold the input.
// postcondition: the user input is stored to the given variable
void getPrice(double& price)
{
    cout << "Enter price $";
    cin >> price;
    return;
}

// precondition: pass a variable to hold the number purchased
// postcondition: the user input is stored to the given variable
void getNumber(int& num)
{
    cout << "Enter number purchased: ";
    cin >> num;
    return;
}

// precondition: pass a variable to hold the sale type. The user must input
// 'W','w', 'R', or 'r'
// postcondition: the user input is stored to the given variable
void getSaleType(char& saleType)
{
    cout << "Type W if this is wholesale purchase. \n"
            << "Type R if this is retail purchase. \n"
            << "then press return... \n";
    cin.ignore();
    cin.get(saleType);
    return;
}

// precondition: Pass the double to hold the calculated total. Sale type must be chars
// 'W','w', 'R', or 'r'. Also need price and number purchased.
// postcondition: the calculated value is stored to the given ref variable
void calcTotal(double& total, char saleType, double price, int number)
{
    double subTotal = 0;
    if ((saleType == 'W') || (saleType == 'w'))
    {
        total = price * number;
    }
    else if ((saleType == 'R') || (saleType == 'r'))
    {
        subTotal = price * number;
        total = subTotal + subTotal * TAX_RATE;
    }
    else
    {
        cout << "Error in the input...";
    }
    return;
}

// precondition: Pass the double holding the calculated total. Sale type must be chars
// 'W','w', 'R', or 'r'. Also need price and number purchased.
// postcondition: total is outputed to the console
void dispTotal(double total, char saleType, double price, int number)
{
    cout << setprecision(2) << fixed << showpoint << number << " items at $" << price << endl;
    cout << "Total bill $" << total;
    if ((saleType == 'R') || (saleType == 'r'))
    {
        cout << " includes sales tax.\n";
    }
    return;
}