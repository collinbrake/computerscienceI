#include <iostream>

int main()
{
    int grid[15][9] = {{1, 2, 3}, {1, 2, 3}}, *gridPointers[135] = {nullptr};

    int k = 0;
    for (int i = 0; i < 15; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            *(gridPointers + k++) = &grid[i][j];
        }
    }

    k = 0;
    while (k < 134)
    {
        std::cout << **(gridPointers + k++) << " ";
    }
    std::cout << **(gridPointers + k) << std::endl;

    return 0;
}
