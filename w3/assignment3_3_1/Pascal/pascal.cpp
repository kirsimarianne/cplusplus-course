#include "pascal.h"
#include <vector>
#include <iostream>

std::vector<std::vector<int>> create_pascal(int row)
{
    // row and column sizes, i and j indexes
    std::vector<std::vector<int>> vect(row);
    for (int i = 0; i < row; ++i)
    {
        int column = i+1;
        vect[i].resize(column);
        vect[i][0] = 1;
        vect[i][column - 1] = 1;
        for (int j = 1; j < column - 1; ++j)
        {

            vect[i][j] = vect[i - 1][j - 1] + vect[i - 1][j];
        }
    }

    return vect;
}
