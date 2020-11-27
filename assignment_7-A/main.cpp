/*
   COPYRIGHT (C) 2020 Collin Brake (cmb361)
   All rights reserved.
   Computer Science I - ASSIGNMENT 7-A
   Author: Collin Brake
       cmb361@zips.uakron.edu
   Purpose: Read data from a file, perform calculations, and output
     to the screen. Impliment sort algorithm for parallel arrays.
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

bool extractFields(ifstream &file, string items[], int counts[],
                     double prices[], int len);
// This function reads until EOF, reading an item name, count, and
// price from each line of a farmer's market report.

void sortByString(string items[], int counts[],
                     double prices[], int len);
// The arrays are processed
//    in parallel, sorting each array alphabetically by
//    the values in the first array.

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

   // Declare arrays to hold our three types of data
   int counts[SIZE] = {0};
   string items[SIZE] = {""};
   double prices[SIZE] = {0.0};

   extractFields(inFile, items, counts, prices, SIZE);
   sortByString(items, counts, prices, SIZE);
   

   // Sum up the counts and the revinue for each item type
   int itemCount = 0, allItemsCount = 0;
   double itemRevinue = 0;
   for (int i = 0; i < SIZE; ++i)
   {
      itemCount += counts[i];
      itemRevinue += counts[i]*prices[i];
      if (i == SIZE-1 || items[i] != items[i+1] || items[i+1] == "")
      {
         cout << items[i] << ": ";
         cout << std::setw(17) << std::setfill(' ') << ' ';
         cout << std::fixed << std::setprecision(2)
            << itemCount << " items totaling $" << itemRevinue << endl;
         itemCount = 0;
         itemRevinue = 0;
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

// Precondition: a file, and three arrays to hold the three fields from
//    each line of the file. The length of all the arrays is the same and
//    is the final parameter.
// Postcondition: the arrays will be filled with the respective values from each
//    field.
bool extractFields(ifstream &file, string items[], int counts[],
                     double prices[], int len)
{
   string line = "";
   char a = 'a', last = 'a';
   int i = 0;
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
            file >> counts[i];
            file >> items[i];
            file >> prices[i];

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

// Precondition: Three arrays, the first of which is 
//    has string as base type.
// Postcondition: all arrays sorted alphabetically by 
//    values in first array.
void sortByString(string items[], int counts[],
                     double prices[], int len)
{
   string tempItems;
   int tempCounts;
   double tempPrices;
   int startScan, minIndex;
   for (startScan = 0; startScan < len-1; ++startScan)
   {
      minIndex = startScan;
      tempItems = items[startScan];
      for (int i = startScan+1; i < len; ++i)
      {
         if (items[i] < tempItems && items[i] != "")
         {
            tempItems = items[i];
            tempCounts = counts[i];
            tempPrices = prices[i];
            minIndex = i;
         }
      }

      items[minIndex] = items[startScan];
      items[startScan] = tempItems;
      counts[minIndex] = counts[startScan];
      counts[startScan] = tempCounts;
      prices[minIndex] = prices[startScan];
      prices[startScan] = tempPrices;
   }
}