/* Exercise 1:
 * Write a simple C++ program that takes a file name as a command-line argument 
 * and prints the contents of the file to the console. 
 * Make sure to handle errors, like if the file doesn't exist. Use CMake to build your program.
*/
#ifndef PRINTLINES_H
#define PRINTLINES_H

#include <fstream>
#include <iostream>

void print_file_content(std::ifstream& input_file);

#endif