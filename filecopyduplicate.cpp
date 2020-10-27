#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;

int main()
{
   ifstream iFile("input.txt"); // input.txt has integers, one per line

   int x;
   while (iFile >> x)
   {
      cout << x << endl;
   }
   if (!iFile.eof())
   {
      cout << "Error, copy failed before EOF";
   }

   iFile.close();

   return 0;
}
