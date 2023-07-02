/* Create a calculator program that can do basic operations: 
* Addition, subtraction, multiplication and division. 
* In your program, create a user interface that asks for basic calculation operations. 
* All calculations should be executed in a utility library.
*/

#ifndef UTILS_H
#define UTILS_H

#include <vector>

double add(const std::vector<double>& vect);
double subtract(std::vector<double>& vect);
double multiply(const std::vector<double>& vect);
double divide(std::vector<double>& vect);

std::string encrypt(std::string str, int key);
std::string decrypt(std::string str, int key);

#endif