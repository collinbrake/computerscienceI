#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;

void getNumber(int &num);

int main()
{
   int num = 0;
   getNumber(num);
}

void getNumber(int &num)
{
   bool loopFlag = false; // Control loop flag
   do
   {
      std::cout << "Enter a number in the range of 1 to 100: ";
      std::cin >> num;
      if (std::cin.fail() || num < 1 || num > 100)
      {
         std::cout << "that number is in error.\n";
         // repair input stream
         cin.clear();
         // ignore garbage
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         loopFlag = true;
      }
      else
      {
         loopFlag = false; // valid input -> end loop
      }
   } while (loopFlag); // iterate until valid input received
   return;
}