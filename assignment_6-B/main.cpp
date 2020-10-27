/*
   COPYRIGHT (C) 2020 Collin Brake (cmb361)
   All rights reserved.
   Computer Science I - ASSIGNMENT 6-B
   Author: Collin Brake
       cmb361@zips.uakron.edu
   Purpose: Read data from a file, perform calculations, and output
     to the screen as well as a new file.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

string fetchInput(string promptMsg, string invalidMsg);
// fetchInput prompts for, recieves from the input stream, and validates string
// type input

bool validateInput(string input, string message);
// This function validates the string type input, and prints out
// the provided message if the input is invalid. It ensures that
// the input is of the correct type, and that the string input // is a valid file name.

bool readData(ifstream &file, string &name, int &count, string &item,
              double &price);
// Reads all necesary data from a line of the input file. Clears newline
// and any junk/whitespace at end. Returns true if EOF encountered.

int main()
{
   // Declare string to hold file name
   string fname = "";

   // Prompt for and validate file name from user
   fname = fetchInput(
       "Enter the name of the file to be\nprocessed, including extention: ",
       "An invalid file name was entered.");

   // Print the header of the report
   cout << std::setw(61) << std::setfill('=') << '=' << endl;
   cout << '=' << std::setw(17) << std::setfill(' ') << ' ';
   cout << "FARMER'S MARKET INVENTORY";
   cout << std::setw(17) << std::setfill(' ') << ' ';
   cout << '=' << endl;
   cout << std::setw(61) << std::setfill('=') << '=' << endl;

   // Declare an input file stream and link to user-provided filename
   ifstream inFile;
   inFile.open(fname);

   // Declare an output file stream and link to output name for calculated
   // values
   ofstream outFile;
   outFile.open("output.txt");

   // Declare vars for different data types of input,
   // as well as calculated values.
   char nameChar = ' ';
   string name = "", item = "";
   int count = 0, totalCount = 0;
   double price = 0, total = 0, grandTotal = 0;

   while (!inFile.fail() && !inFile.eof())
   {
      if (readData(inFile, name, count, item, price))
      {
         break;
      }

      // Calculate item total and grand total and total count
      totalCount += count;
      total = count * price;
      grandTotal += total;

      // Output a line of the report to console
      cout << std::setprecision(2) << std::fixed
           << std::setw(25) << std::setfill(' ') << std::left
           << name + ":" << ' ';
      cout << count << " " << item << " @ "
           << price << " each totaling $" << total << endl;

      // Output a line to the file
      outFile << std::setprecision(2) << std::fixed << name
              << " " << count << " " << item << " " << price << " "
              << total << endl;
   }

   // Grand total to console
   cout << std::setw(25) << "Grand total: " << totalCount
        << " items totaling $" << grandTotal << endl;

   inFile.close();
   outFile.close();

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

// Precondition: pass reference variables to hold
//                1. input file stream
//                2. farm name
//                3. count of items
//                4. name of item
//                5. price per item
// Postcondition: read a line from the file to populate all
//    of these values. Returns true if EOF encountered.
bool readData(ifstream &file, string &name, int &count, string &item,
              double &price)
{
   // Read farm name with comma as delimiter
   getline(file, name, ',');

   if (file.eof())
   {
      return true;
   }

   // Get count of items
   file >> count;

   // Get name of items
   file >> item;

   // Get price per item
   file >> price;

   // Clean up newline and any whitespace/junk at end
   string lineRemainder;
   getline(file, lineRemainder);

   return file.eof();
}