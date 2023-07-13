#ifndef STRING_UTILITY_H
#define STRING_UTILITY_h

#include <algorithm>
#include <cassert>
#include <string>

std::string reverse_string(std::string str);

std::string uppercase_string(std::string s);

std::string lowercase_string(std::string s);

bool is_palindrome(std::string str);

#endif