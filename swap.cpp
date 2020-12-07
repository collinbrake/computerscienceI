#include <iostream>

using std::cout;
using std::endl;

void swapRef(int &, int &);

void swapPtr(int *, int *);

int main()
{
    int x = 42, y = 31;

    cout << x << " " << y << endl;
    swapRef(x, y);
    cout << x << " " << y << endl;
    swapRef(x, y);
    cout << x << " " << y << endl;

    swapPtr(&x, &y);
    cout << x << " " << y << endl;
    swapPtr(&x, &y);
    cout << x << " " << y << endl;

    return 0;
}

void swapRef(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
    return;
}

void swapPtr(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}
