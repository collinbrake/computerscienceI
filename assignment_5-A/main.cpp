/*
    COPYRIGHT (C) 2020 Collin Brake (cmb361)
    All rights reserved.
    Computer Science I - ASSIGNMENT 5-A
    Author: Collin Brake
        cmb361@zips.uakron.edu
    Purpose: To practice writing functions that meet specific requirements.
*/

#include <iostream>
#include <limits>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool isPrime(int);
// isPrime tests if the given integer is prime or not.
// Considers a integer not prime if it is less than 2
// or is evenly divisible by an integer between 1 and itself
// non-inclusive. Prime otherwise.

bool validateInput(int input, int rangeLow, int rangeHigh,
                   string message);
// This function validates the int type input, and prints out
// the provided message if the input is invalid. It ensures that
// the input is within the provided range and is of the correct
// type

int main()
{
   // Declare integer to hold user input, and bool to hold is prime.
   // Declare bool that will be true if user wants to quit.
   int num = 0;
   bool prime = false, quit = false;

   while (true)
   {
      // Prompt for input, recieve from stream, and validate.
      cout << "Please enter a positive integer"
           << " (enter a character a-z to quit program): ";
      cin >> num;
      // we put an upper limit here of 999M and a zero lower limit
      quit = validateInput(num, 0, 999999999, "Program quiting....");
      if (quit)
      {
         return 0; // Quit the program if invalid input entered
      }

      prime = isPrime(num);

      // Notify the user whether it is prime or not
      string postfix = "";
      if (!prime)
      {
         postfix = "n't";
      }
      cout << "The number " << num << " is" << postfix << " prime.\n";

      // Print all prime numbers from two up until the input number
      cout << "The following numbers less than " << num << " are prime:\n";
      for (int i = 0; i < num; i++)
      {
         if (isPrime(i))
         {
            cout << i << endl;
         }
      }
   }

   return 0;
}

// Precondition: a valid positive integer greater than zero.
// Postcondition: whether or not that integer is prime.
bool isPrime(int num)
{
   if (num < 2) // No integer less than 2 is prime
   {
      return false;
   }

   // If divisible by an int in this range, not prime
   for (int i = 2; i < num; i++)
   {
      if (num % i == 0)
      {
         return false;
      }
   }

   // Prime
   return true;
}

// Precondtion: pass the function the user input
//              pass the function a range, rangeLow lowest acceptable
//              pass the function a range, rangeHigh highest acceptable
//              pass the message to display for any user error
// Postcondition: returns false if valid and true if not. Displays message.
bool validateInput(int input, int rangeLow, int rangeHigh, string message)
{
   bool goodOrNot = false; // Is the input good?
   if ((cin.fail()) || ((input < rangeLow) || (input > rangeHigh)))
   {
      cout << message << endl;
      goodOrNot = true;
   }
   cin.clear();
   // Clear the input stream to the numeric limit
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   return goodOrNot;
}