#include <string>
#include <iostream>



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

/*bool contains_uppercase()
{

}

bool contains_lowercase()
{

}

bool contains_digit()
{

}

bool contains_special()
{

}*/

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

    if(length_valid(password))
    {
        std::cout << "Password is strong." << std::endl;
    }
    
    return 0;

}