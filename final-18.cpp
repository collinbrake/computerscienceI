#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

int main()
{
    const int SIZE = 10;
    int idNumList[SIZE] = {0};
    double weeklyPayList[SIZE] = {0};

    /*
    for (int i = 0; i < SIZE; ++i)
    {
        idNumList[i] = 2*i+1;
        weeklyPayList[i] = 4*i;
    }
    */

    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << "Employee " << i+1 << ": ID Number is " << idNumList[i] << ", Weekly Gross Pay is $" << std::setprecision(2) << std::fixed << weeklyPayList[i] << endl;
    }

    return 0;
}
