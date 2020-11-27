#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int size = 0;
    cout << "Enter the size for the arrays p and p2\n"
        << "(p is dynamically allocated, while p2 is not): ";

    int *p = new int[size];
    int *p2;

    int val = 0;
    cout << "Enter numbers to store in the arrays: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> val;
        p[i] = val;
        p2[i] = val;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "Here are the stored numbers from p:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << p[i] << " ";
    }
    cout << endl;

    cout << "Here are the stored numbers from p2:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << p2[i] << " ";
    }
    cout << endl;

    cout << "Enter the new size for the arrays: ";
    cin >> size;

    cout << "Reallocating the dynamically allocated array p.\n";
    delete p;
    p = nullptr;
    p = new int[size];

    return 0;
}
