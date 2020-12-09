#include <iostream>

using std::cout;
using std::endl;

void selectionSort(double arr[], int size);

int main()
{
    double arr[] = {65, 2.0, 1, 2.3, 4, 5};

    for (double elem : arr)
        cout << elem << " ";
    cout << endl;

    selectionSort(arr, 6);

    for (double elem : arr)
        cout << elem << " ";
    cout << endl;

    return 0;
}

void selectionSort(double arr[], int size) {
    for (int startScan = 0; startScan < size-1; ++startScan)
    {
        int minIndex = startScan;
        double minValue = arr[startScan];
        for (int i = startScan + 1; i < size; ++i)
        {
            if (arr[i] < minValue)
            {
                minValue = arr[i];
                minIndex = i;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minValue;
    }
}
