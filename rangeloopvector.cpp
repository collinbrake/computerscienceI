#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main()
{
    int size;
    cout << "Enter the size of the vector you want: ";
    cin >> size;
    vector<string> vec(size, "blank");

    cout << "\nInitial contents of vector:\n";
    for (string entry : vec)
    {
        cout << entry << " ";
    }
    cout << endl;

    cout << "\nEnter " << size << " items.\n";
    for (string &entry : vec)
    {
        cin >> entry;
    }

    cout << "\nNew contents of vector:\n";
    for (string entry : vec)
    {
        cout << entry << " ";
    }
    cout << endl;

    return 0;
}
