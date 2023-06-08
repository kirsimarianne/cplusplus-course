#include <cassert>
#include <iostream>
#include <string>

std::string capitalize_string(std::string s)
{
    
    for(int i = 0; i < s.length(); i++)
    {
        if(i == 0)
        {
            s[i] = toupper(s[0]);
        }
        else if(s[i-1] == ' ')
        {
            s[i] = toupper(s[i]);
        }
        else
        {
            s[i] = tolower(s[i]);
        }

    }

    return s;
}


int main() {
    assert("The String Challenge" ==
    capitalize_string("the string challenge"));
    std::cout << "Test 1 passed" << std::endl;
    assert("This Is An Example, Should Work!" ==
    capitalize_string("THIS IS an ExamplE, should wORk!"));
    std::cout << "Test 2 passed" << std::endl;
}