#include <string>
#include <iostream>
#include <cctype>


bool length_valid(const std::string &str)
{
    if(str.length() < 8)
    {
        return false;
    }
    else{
        return true;
    }
}

bool contains_uppercase(const std::string &str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(std::isupper(str[i]))
        {
            return true;
        }
    }
    return false;
}

bool contains_lowercase(const std::string &str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(std::islower(str[i]))
        {
            return true;
        }
    }
    return false;
}


bool contains_digit(const std::string &str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(std::isdigit(str[i]))
        {
            return true;
        }
    }
    return false;
}

bool contains_punct(const std::string &str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if(std::ispunct(str[i]))
        {
            return true;
            
        }
    }
    return false;
}


std::string set_password()
{
    std::cout << "Enter a password: " << std::endl;
    std::string password;
    std:: cin >> password;
    return password;

}

int main()
{
    std::string password {set_password()};

    contains_punct(password);

    if(length_valid(password) && contains_uppercase(password) && contains_lowercase(password)
        && contains_digit(password) && contains_punct(password))
    {
        std::cout << "Password is strong." << std::endl;
    }
    else{
        std::cout << "Password is weak." << std::endl;
    }
    
    return 0;

}