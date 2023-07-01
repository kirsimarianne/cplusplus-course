/* The program returns reversed string.
*/
#include <string>
#include <iostream>

std::string reverse_string(std::string str)
{
    for(int i{0}; i < str.length()/2; i++){
        std::swap(str[i], str[str.length()-i-1]);
    }
    return str;
}

std::string get_string_from_user()
{
    std::cout << "Enter a string: " << std::endl;
    std::string userinput{};
    std:: cin >> userinput;
    return userinput;

}

int main()
{
    std::cout << "Reverse string\n"<< reverse_string(get_string_from_user()) << std::endl;
    return 0;

}