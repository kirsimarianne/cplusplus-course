#include "character.hpp"
#include <iostream>
#include <cassert>

// Overloaded constructors with parameter
Character::Character(int id)
{
    id_ = id;
    tag_ = Tag::robot;
}

Character::Character(char first_letter)
{
    first_letter_ = first_letter;
    tag_ = Tag::person;
}
Character::Character(float wavelength)
{
    wavelength_ = wavelength;
    tag_ = Tag::alien;
}

// Function for testing purposes in future development
const Tag &Character::get_tag() const
{
    return tag_;
}

// FUnction returns tag in std::string type.
const std::string Character::get_identity()
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
void Character::set(int id)
{
    id_ = id;
    tag_ = Tag::robot;
}

void Character::set(char first_letter)
{
    first_letter_ = first_letter;
    tag_ = Tag::person;
}

void Character::set(float wavelength)
{
    wavelength_ = wavelength;
    tag_ = Tag::alien;
}

/* Getters return the tag.
 * Asserts stops the program if trying to access wrong type tag.
 */
const int &Character::get_id() const
{
    assert(tag_ == Tag::robot && "Error: Tag is not robot.");
    return id_;
}

const char &Character::get_first_letter() const
{
    assert(tag_ == Tag::person && "Error: Tag is not person.");
    return first_letter_;
}

const float &Character::get_wavelength() const
{
    assert(tag_ == Tag::alien && "Error: Tag is not alien.");
    /*if(tag_ != Tag::alien)
    {
        throw std::logic_error("Faulty tag");
    }*/
    return wavelength_;
}

int main()
{
    Character maija('m');
    std::cout << "Maija: " << maija.get_first_letter() << ", "
              << maija.get_identity() << "\n";
    maija.set('a');
    std::cout << "Maija: " << maija.get_first_letter() << ", "
              << maija.get_identity() << "\n";

    Character rolle(12);
    std::cout << "Rolle: " << rolle.get_id() << ", "
              << rolle.get_identity() << "\n";

    Character allu(12.92f);
    std::cout << "Allu: " << allu.get_wavelength() << "\n";

    Character rex('r');
    std::cout << "Rex identity: " << rex.get_identity() << "\n";
    //std::cout << "Rex: " << rex.get_id() << "\n";

    rex.set(12);
    std::cout << "Rex identity: " << rex.get_identity() << "\n";
    std::cout << "Rex: " << rex.get_id() << "\n";
}