/* Exercise 3:
 * Add a word counter. 
 * Extend your program to count the number of words in the file. 
 * Add a command-line option "-w" or "--words".
*/
#ifndef COUNTSTRINGS_H
#define COUNTSTRINGS_H

#include <fstream>
#include <iostream>

void count_strings(std::ifstream& input_file);

#endif