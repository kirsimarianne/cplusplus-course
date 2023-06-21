#include "string_utility.h"

std::string reverse_string(std::string str)
{
    std::reverse(str.begin(), str.end());
    return str;
}


std::string uppercase_string(std::string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

std::string lowercase_string(std::string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

bool is_palindrome(std::string str)
{
    std::string reversed_str = str;
    
    std::reverse(reversed_str.begin(), reversed_str.end());
    if(reversed_str == str)
    {
        return true;
    }
    else{
        return false;
    }
}



