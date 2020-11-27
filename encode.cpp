#include <iostream>
#include <fstream>
#include <cctype>

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
   string inName = "DATA.txt", outName = "DATA10.txt";

   inFile.open(inName);
   outFile.open(outName);

   char ch;

   while (inFile.get(ch))
   {
      // if alphanumeric, enclode
      if (std::isalpha(ch) || std::isdigit(ch))
      {
         ch += 10;
      }

      if (!outFile.put(ch))
      {
         cout << "Error writing to file.\n";
         break;
      }
   }
   if (inFile.fail() && !inFile.eof())
   {
      cout << "Error with input file.\n";
   }

   inFile.close();
   outFile.close();

   return 0;
}