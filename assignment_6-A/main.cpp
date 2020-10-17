#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

string fetchInput(string promptMsg, string invalidMsg);
// fetchInput prompts for, recieves from the input stream, and validates string
// type input

bool validateInput(string input, string message);
// This function validates the string type input, and prints out
// the provided message if the input is invalid. It ensures that
// the input is of the correct type, and that the string input
// is a valid file name.

int main()
{
   // Declare string to hold file name
   string fname = "";

   // Prompt for and validate file name from user
   fname = fetchInput(
       "Enter the name of the file to be\ndisplayed, including extention: ",
       "An invalid file name was entered.");

   return 0;
}

// Precondition: prompt message and message to display when invalid input
// received
// Postcondition: returns valid input of type string
string fetchInput(string promptMsg, string invalidMsg)
{
   string input;         // to hold user input
   bool loopFlag = true; // control for validation
   do
   {
      cout << promptMsg;
      cin >> input;
      loopFlag = validateInput(input, invalidMsg);
   } while (loopFlag);
   return input;
}

// Precondtion: pass the function the user input
//              pass the message to display for any user error
// Postcondition: returns false if valid and true if not
bool validateInput(string input, string message)
{
   bool goodOrNot = false;
   if (cin.fail())
   {
      cout << message << endl;
      goodOrNot = true;
   }
   else
   {
      ifstream test;
      test.open(input);
      if (test.fail())
      {
         cout << message << endl;
         goodOrNot = true;
      }
   }
   cin.clear();
   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
   return goodOrNot;
}