#include "pascal.h"
#include <vector>
#include <iostream>

std::vector<std::vector<int>> create_pascal(int row)
{
    std::vector<std::vector<int>> vect(row);

    for (int i = 0; i < row; ++i)
    {
        int column = i + i - 1;
        vect[i].resize(column);
        // rivin pituus kasvaa joka rivillä kahdella
        vect[i][0] = 1;
        vect[i][column-1] = 1;
        for (int j = 1; j < column-1; ++j)
        {
            if (j % 2 != 0)
            {
                vect[i][j] = vect[i-1][j-2] + vect [i-1][j];
            }
            else
            {
                vect[i][j] = 7;
            }
        }

        for(auto row : vect)
        {
            for(auto elem : row)
            {
                std::cout << elem;
            }
            std::cout << "\n";
        }
    }

    return vect;
}