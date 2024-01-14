/* Create a calculator program that can do basic operations:
 * Addition, subtraction, multiplication and division.
 * In your program, create a user interface that asks for basic calculation operations.
 * All calculations should be executed in a utility library.
 */

#include <vector>
#include <iostream>

double add(const std::vector<double> &vect)
{
    double sum{};
    for (auto elem : vect)
    {
        sum += elem;
    }
    return sum;
}

double subtract(std::vector<double> &vect)
{
    std::vector<double>::iterator it = vect.begin();
    double difference = *it;

    for (it = vect.begin() + 1; it != vect.end(); it++)
    {
        difference -= *it;
    }

    return difference;
}

double multiply(const std::vector<double> &vect)
{
    double product{1};
    for (auto elem : vect)
    {
        product *= elem;
    }
    return product;
}

double divide(std::vector<double> &vect)
{
    std::vector<double>::iterator it = vect.begin();
    double division = *it;

    for (it = vect.begin() + 1; it != vect.end(); it++)
    {
        division /= *it;
    }
    return division;
}

std::string encrypt(std::string str, int key)
{
    std::string encrypted_text = "";
    for (char c : str)
    {
        if (isalpha(c))
        {
            char start = isupper(c) ? 'A' : 'a';
            int offset = c - start; 
            int shifted_offset = (offset + key) % 26;
            char encrypted_char = start + shifted_offset;
            encrypted_text += encrypted_char;
        }
        else
        {
            encrypted_text += c;
        }
    }
    return encrypted_text;
}

std::string decrypt(std::string str, int key)
{
    std::string decrypted_text = "";
    for (char c : str)
    {
        if (isalpha(c))
        {
            char start = isupper(c) ? 'A' : 'a';
            int offset = c - start; 
            int shifted_offset = (offset - key + 26) % 26;
            char decrypted_char = start + shifted_offset;
            decrypted_text += decrypted_char;
        }
        else
        {
            decrypted_text += c;
        }
    }
    return decrypted_text;
}