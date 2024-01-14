/* Exercise 3:
 * Create a vector of floating-point numbers and sort it. 
 * Experiment with different sizes of vectors and number ranges.
*/
#include <algorithm>
#include <iostream>
#include <vector>

void sort_vector(std::vector<float>& vect)
{
    std::sort(vect.begin(), vect.end());
}

/* Function to print vector
*/
void print_vector(const std::vector<float>& vect)
{
    for(auto element : vect)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<float> vect = {0, -100, 0.5, -1.77, -39.34878, 99.89, 6.0009};
    sort_vector(vect);
    print_vector(vect);
    vect = {0, 0.777, 0.34643875, -0.27316, 0.927};
    sort_vector(vect);
    print_vector(vect);
    vect = {0, 100000.777, 1239432898357.34643875, -800000092.9, 0.927,
            654.00, 100000.777, 1239432898357.34643875, -800000092.9, 0.927,
            600.98, 400.777, 1239432898357.34643875, -800000092.9, 0.927,
            4.5, 99.777, -120000000., -800000092.9, 0.927};
    sort_vector(vect);
    print_vector(vect);
}