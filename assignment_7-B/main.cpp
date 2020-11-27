/*
   COPYRIGHT (C) 2020 Collin Brake (cmb361)
   All rights reserved.
   Computer Science I - ASSIGNMENT 7-B
   Author: Collin Brake
       cmb361@zips.uakron.edu
   Purpose: Read data from a file, perform calculations, and output
     to the screen. Impliment BUBBLE sort algorithm for parallel arrays.
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

const int SIZE = 1000;

string fetchInput(string promptMsg, string invalidMsg);
// fetchInput prompts for, recieves from the input stream, and validates string
// type input

bool validateInput(string input, string message);
// This function validates the string type input, and prints out
// the provided message if the input is invalid. It ensures that
// the input is of the correct type, and that the string input // is a valid file name.

bool extractFields(ifstream &file, string items[], int len);
// This function reads until EOF, reading an item name from each line of a farmer's market report.

void sortByString(string items[], int len);
// The array of strings is BUBBLE sorted, alphabetically

int main()
{
   // Declare string to hold file name
   string fname = "";

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

   // Declare arrays to hold our item names
   string items[SIZE] = {""};

   extractFields(inFile, items, SIZE);
   sortByString(items, SIZE);
   
   // Sum up the counts and display
   int loadCount = 0, allItemsCount = 0;
   for (int i = 0; i < SIZE; ++i)
   {
      ++loadCount;
      if (i == SIZE-1 || items[i] != items[i+1] || items[i+1] == "")
      {
         cout << loadCount << " loads of " << items[i] << " were delivered\n";
         loadCount = 0;
         ++allItemsCount;
      }
      if (items[i+1] == "")
      {
         break;
      }
   }

   cout << "There were " << allItemsCount
      << " items contributing to this week's event.\n";

   inFile.close();

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

// Precondition: a file, and  one array to hold the field from
//    each line of the file. The length of array
//    is the final parameter.
// Postcondition: the array will be filled with the correct value from each
//    line.
bool extractFields(ifstream &file, string items[], int len)
{
   string line = "";
   char a = 'a', last = 'a';
   int i = 0;
   int count;
   while (!file.fail() && !file.eof())
   {
      while (file.get(a))
      {
         if (file.eof())
         {
            return true;
         }
         if (a == '\n')
         {
            break;
         }
         if (isdigit(a) && last == ' ')
         {
            file.putback(a);
            file >> count;
            file >> items[i];

            // Clear garbage
            getline(file, line);
            break;
         }
         last = a;
      }
      ++i;
   }
   return false;
}

// Precondition: One array which
//    has string as base type.
// Postcondition: the array sorted alphabetically by 
//    values.
void sortByString(string items[], int len)
{
   bool swap;
   string temp;

   do {
      swap = false;
      for (int count = 0; count < (len-1); ++count)
      {
         if (items[count] > items[count+1] && items[count] != "" && items[count+1] != "")
         {
            temp = items[count];
            items[count] = items[count+1];
            items[count+1] = temp;
            swap = true;
         }
      }
   } while (swap);
   return;
}