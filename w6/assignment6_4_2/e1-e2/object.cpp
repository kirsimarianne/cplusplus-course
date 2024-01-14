#include "object.hpp"
#include <cassert>
#include <charconv>
#include <string_view>

// Overloaded constructors with parameter
Object::Object(int id)
{
    id_ = id;
    tag_ = Tag::robot;
}

Object::Object(char first_letter)
{
    first_letter_ = first_letter;
    tag_ = Tag::person;
}
Object::Object(float wavelength)
{
    wavelength_ = wavelength;
    tag_ = Tag::alien;
}

// Function for testing purposes in future development
const Tag &Object::get_tag() const
{
    return tag_;
}

// Function returns tag in std::string type.
const std::string Object::get_identity()
{
    if (tag_ == Tag::robot)
    {
        return std::to_string(id_);
    }
    else if (tag_ == Tag::person)
    {
        return std::string{first_letter_};
    }
    else if (tag_ == Tag::alien)
    {
        return std::to_string(wavelength_);
    }
    else
    {
        return "Error: identity not found";
    }
}

/* Setters for changing value.
 * Future developemnt/ note to self: is previous value removed
 * automatically or does it need to be removed?
 */
void Object::set(int id)
{
    id_ = id;
    tag_ = Tag::robot;
}

void Object::set(char first_letter)
{
    first_letter_ = first_letter;
    tag_ = Tag::person;
}

void Object::set(float wavelength)
{
    wavelength_ = wavelength;
    tag_ = Tag::alien;
}

/* Getters return the tag.
 * Asserts stops the program if trying to access wrong type tag.
 */
const int &Object::get_id() const
{
    assert(tag_ == Tag::robot && "Error: Tag is not robot.");
    return id_;
}

const char &Object::get_first_letter() const
{
    assert(tag_ == Tag::person && "Error: Tag is not person.");
    return first_letter_;
}

const float &Object::get_wavelength() const
{
    assert(tag_ == Tag::alien && "Error: Tag is not alien.");
    return wavelength_;
}

// 
bool is_float(std::string_view input)
{
    double val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

bool is_int(std::string_view input)
{
    int val;
    auto [p, ec] = std::from_chars(input.data(), input.data() + input.size(), val);
    return ec == std::errc() && p == input.data() + input.size();
}

Object create_object(std::string identity)
{
    Object object;
    if(is_float(identity))
    {
        object.set(stof(identity));
    }
    else if(is_int(identity))
    {
        object.set(stoi(identity));
    }
    else{
        object.set(identity[0]);
    }

    return object;
}

int main()
{
    Object maija('m');
    std::cout << "maija: " << maija;
    maija.set('a');
    std::cout << "maija: " << maija;
   
    Object rolle(12);
    std::cout<< "rolle: " << rolle;

    Object allu(12.92f);
    std::cout << "allu: " << allu;

    Object rex('r');
    std::cout << "rex: " << rex;

    Object pekka {create_object("pekka")};
    std::cout << "pekka: " << pekka;

    Object hanna {create_object("h")};
    std::cout << "hanna: " << hanna;

    Object robo {create_object("12")};
    std::cout << "robo: " << robo;

    Object alien {create_object("1.999")};
    std::cout << "alien: " << alien;



}