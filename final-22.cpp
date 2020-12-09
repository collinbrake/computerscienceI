#include <iostream>

int searchW(char cString[])
{
    int count = 0, i = 0;
    while (cString[++i] != '\0')
    {
        if (cString[i] == 'w') {++count;}
    }
    return count;
}

int main()
{
    char cString[] = "hewqiw1234w";

    std::cout << searchW(cString) << std::endl;

    return 0;
}
