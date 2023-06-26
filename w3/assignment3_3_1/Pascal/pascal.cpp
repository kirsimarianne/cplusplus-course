#include "pascal.h"
#include <vector>
#include <iostream>

std::vector<std::vector<int>> create_pascal(int row)
{
    std::vector<std::vector<int>> vect(row);

    for (int i = 1; i < row; ++i)
    {
        int column = i;
        vect[i].resize(column);
        vect[i][0] = 1;
        vect[i][column - 1] = 1;
        for (int j = 1; j < column - 1; ++j)
        {

            vect[i][j] = vect[i - 1][j-1] + vect[i - 1][j];
        }
    }

    for (auto row : vect)
        {
            for (auto elem : row)
            {
                std::cout << elem<< " ";
            }
            std::cout << "\n\n";
        }

    return vect;
}
