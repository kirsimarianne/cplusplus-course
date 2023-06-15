/* Exercise 1:
 * Write a simple C++ program that takes a file name as a command-line argument 
 * and prints the contents of the file to the console. 
 * Make sure to handle errors, like if the file doesn't exist. Use CMake to build your program.
*/
#include <fstream>
#include <iostream>

#ifndef OPENFILE_H
#define OPENFILE_H

bool print_file_content(std::string filename);


#endif