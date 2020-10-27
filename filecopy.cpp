#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
   ifstream inFile;
   ofstream outFile;
   string inFileName;
   string outFileName;
   cout << "Enter input file name: " << endl;
   getline(cin, inFileName);
   cout << "Enter output file name: " << endl;
   getline(cin, outFileName);
   char ch;

   // Treat as binary, convert name to cstring,
   // not really necessary for > C++11.
   inFile.open(inFileName.c_str(), std::ios::binary);
   if (!inFile)
   {
      cout << "input file open error" << endl;
      return 0;
   }

   outFile.open(outFileName.c_str(), std::ios::binary);
   if (!outFile)
   {
      cout << "output file open error" << endl;
      return 0;
   }

   while (inFile.get(ch)) // Get data and check fail in one statement
   {
      outFile.put(ch);
      if (outFile.fail())
      {
         cout << "Error in writing to output file" << endl;
         break;
      }
   }
   if (!inFile.eof()) // Make sure all of file was read
   {
      cout << "Error in reading input file" << endl;
   }

   inFile.close();
   outFile.close();
}