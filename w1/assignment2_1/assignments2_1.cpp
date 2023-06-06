#include <string>
#include <iostream>

std::string reverseString(std::string str)
{
    for(int i = 0; i < str.length()/2; i++){
        std::swap(str[i], str[str.length()-i-1]);
    }
    return str;
}

int main()
{
    std::cout << "Enter a string: " << std::endl;
    std::string userinput;
    std:: cin >> userinput;
    std::cout << "Reverse string: "<< reverseString(userinput) << std::endl;
    return 0;

}