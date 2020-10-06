/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - ASSIGNMENT 4-A
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: This program implements functions to calculate the balance in an accout after
        1 year and n years of compounding interest, as well as the number of years needed to
        accumulate 1 million dollars in the account.
*/

#include <iostream>
#include <iomanip>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ios;

double newBalance(double initialBalance, double interestRate);
// This first version of the new balance function computes the
// final account balance that will be reached by starting with
// an initial balance and adding one year's interest at a given
// interest rate (such as 0.05 for 5%). The function works
// correctly for any non-negative arguments.

double newBalance(double initialBalance, double interestRate, int n);
// This second version of the new balance function computes the
// final account balance that will be reached by starting with
// an initial balance and adding some n number of years of interest
// at a given interest rate (such as 0.05 for 5%). The interest is added
// once per year and it is applied to the entire balance.
// For example, new_balance(100.00, 0.10, 2) is 121.00 since
// the first year received 10.00 interest (10% of 100) and the
// second year received 11.00 interest (10% of the 110, which
// was the second year's starting balance). The function works
// correctly for any non-negative arguments.
// Notice n is not an appropriate variable name, but will not be
// deducted for this program.

int yearsNeeded(double initialBalance, double interestRate, double goal);
// The years needed function computes the number of years needed for
// a given starting balance to reach a given goal at a certain rate
// of compound interest. The function works correctly for any
// positive arguments

bool validateInput(double input, double rangeLow, double rangeHigh, string message);
// This function validates the double type input, and prints out
// the provided message if the input is invalid. It ensures that
// the input is within the provided range and is of the correct
// type

double fetchInput(string promptMsg, string invalidMsg);
// fetchInput prompts for, recieves from the input stream, and validates double type input

int main()
{   
    double initialBalance = 0, interestRate = 0, balance1Year = 0, balance10Years = 0,
        yearsToMillion = 0; // Declare local vars to hold user input and calculated values

    // Set output formatting to settings for tidy display of monetary values
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    // Prompt for user input and validate
    initialBalance = fetchInput("Enter the initial account balance: ", "The balance was invalid.");
    interestRate = fetchInput("Enter the interest rate: ", "The interest rate was invalid.");

    // Calculate the three desired values
    balance1Year = newBalance(initialBalance, interestRate);
    balance10Years = newBalance(initialBalance, interestRate, 10);
    yearsToMillion = yearsNeeded(initialBalance, interestRate, 1000000); // set the goal to 1 million

    // Display the values
    cout << "Balance after 1 year: $" << balance1Year << endl
        << "Balance after 10 years: $" << balance10Years << endl
        << "Years needed to reach $1,000,000: " << yearsToMillion << endl;

    return 0;
}

// precondition: the initial balance and interest rate
// postcondition: return the new balance after 1 year of compounding interest
double newBalance(double initialBalance, double interestRate)
{
    return initialBalance*(1 + interestRate); // Return initial balance multiplied by (100% + interest rate)
}

// precondition: the initial balance, interest rate, and number of years
// postcondition: return the new balance after n years of compounding interest
double newBalance(double initialBalance, double interestRate, int n)
{
    double balance = initialBalance;
    for (int i = 0; i < n; i++) // Calculate for n years
    {
        balance += balance*interestRate; // Add amount accumulated through interest for each year
    }
    return balance;
}

// precondition: the initial balance, interest rate, and goal in dollars
// postcondition: return the number of years needed to reach the goal
int yearsNeeded(double initialBalance, double interestRate, double goal)
{
    int years = 0;
    double balance = initialBalance;
    if (initialBalance <= 0 || interestRate <= 0) // Local data validation to avoid an infinite loop
    {
        return 0;
    }
    for (int i = 0; balance < goal; i++)    // Loop while the balance is less than the goal
    {
        balance = newBalance(initialBalance, interestRate, i); // Use newBalance to find balance at this number of years
        years = i;  // Update the number of years with each loop iteration
    }
    return years;
}

// validateInput takes double data and ensures it is correct.
// Note: it is asking is the data invalid? so true/false is in that vein
// precondtion: pass the function the user input
//              pass the function a range, rangeLow lowest acceptable
//              pass the function a range, rangeHigh highest acceptable
//              pass the message to display for any user error
// postcondition: returns false if valid and true if not
bool validateInput(double input, double rangeLow, double rangeHigh, string message)
{
  bool goodOrNot = false;
  if ((cin.fail()) || ((input < rangeLow) || (input > rangeHigh)))
  {
 	cout << message << endl;
    goodOrNot = true;
  }
  cin.clear();
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return goodOrNot;
}

// fetchInput prompts for, recieves from the input stream, and validates double type input
// precondition: prompt message and message to display when invalid input received
// postcondition: returns valid input
double fetchInput(string promptMsg, string invalidMsg)
{
    double input;                           // to hold user input
    bool loopFlag = true;                   // control for validation
    do
    {
        cout << promptMsg;
        cin >> input;
        loopFlag = validateInput(input, 0.0001, 999999999.99, invalidMsg); // we put an upper limit here of 999M and a small lower limit
    } while (loopFlag);
    return input;
}