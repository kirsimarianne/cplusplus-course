/* Exercise 5:
 * Add a function that can calculate the size of the text files in a directory.
 */

#ifndef COUNTCHARS_H
#define COUNTCHARS_H

#include <fstream>
#include <iostream>

void count_chars(std::ifstream & input_file);

#endif