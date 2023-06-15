/* Exercise 2:
 * Add a new feature to your program. 
 * Add a command-line option "-l" or "--lines" to activate this feature. 
 * If this option is provided, instead of printing the file contents, 
 * your program prints the number of lines in the file. You can use the "cxxopts" library again.
*/

#ifndef COUNTLINES_H
#define COUNTLINES_H

#include <fstream>
#include <iostream>

void count_lines(std::ifstream & input_file);

#endif