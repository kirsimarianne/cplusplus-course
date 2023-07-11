/* Exercise 2:
 * Create two std::vector<int> and fill them with random amount of random numbers. 
 * Use std::set_intersection to find common elements between them
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

// Function fills vector with random integers
void generate_random_vector(std::vector<int>& v, const std::size_t& size)
{
    // seed source for random number engine
    std::random_device rd; 
    // marsenne_twister engine seeded with rd()
    std::mt19937 gen(rd()); 
    // prduce random integer values
    std::uniform_int_distribution<> distrib(1, 100);

    for (int n {0}; n != int(size); ++n)
    {
         v.push_back(int(distrib(gen)));
    }
}

size_t generate_random_value()
{
    // seed source for random number engine
    std::random_device rd; 
    // marsenne_twister engine seeded with rd()
    std::mt19937 gen(rd()); 
    // prduce random integer values
    std::uniform_int_distribution<> distrib(1, 10);

    return size_t(distrib(gen));

}

void print(const std::vector<int>& v)
{
    for(auto element : v)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}


void find_intersection(std::vector<int>& v1, std::vector<int>& v2)
{
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::vector<int> v_intersection {};
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), 
    std::back_inserter(v_intersection));

    if(v_intersection.empty())
    {
        std::cout << "No common elements found." << '\n';
    }
    else{
        std::cout << "Common values found: " << '\n';
        print(v_intersection);
    } 
}


int main()
{
    std::vector<int> vect1 {};
    std::vector<int> vect2 {};

    generate_random_vector(vect1, generate_random_value());
    generate_random_vector(vect2, generate_random_value());

    print(vect1);
    print(vect2);

    find_intersection(vect1, vect2);

    return 0;
}