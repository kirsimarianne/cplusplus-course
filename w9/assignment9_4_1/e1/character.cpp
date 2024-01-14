/* Exercise 1
 * In exercise 6.1.2 we created a tagged union of our own.
 * Reimplement the same using a std::variant instead.
 * Use full name instead of the initial this time around.
 */

#include "character.hpp"
#include <iostream>
#include <cassert>

const Tag &Character::get_tag() const
{
    return tag_;
}

// Function returns tag in std::string type.
const std::string Character::get_identity()
{
    if (tag_ == Tag::robot)
    {
        return std::to_string(std::get<int>(badge_));
    }
    else if (tag_ == Tag::person)
    {
        return std::get<std::string>(badge_);
    }
    else if (tag_ == Tag::alien)
    {
        return std::to_string(std::get<float>(badge_));
    }
    else
    {
        return "Error: identity not found";
    }
}

/* Setters for changing value.
 */

void Character::set(int id)
{
    badge_ = id;
    tag_ = Tag::robot;
}

void Character::set(std::string name)
{
    badge_ = name;
    tag_ = Tag::person;
}

void Character::set(float wavelength)
{
    badge_ = wavelength;
    tag_ = Tag::alien;
}

/* Getters return the tag.
 * Asserts stops the program if trying to access wrong type tag.
 */
const int &Character::get_id() const
{
    assert(tag_ == Tag::robot && "Error: Tag is not robot.");
    return std::get<int>(badge_);
}

const char &Character::get_first_letter() const
{
    assert(tag_ == Tag::person && "Error: Tag is not person.");
    return std::get<std::string>(badge_);
}

const float &Character::get_wavelength() const
{
    assert(tag_ == Tag::alien && "Error: Tag is not alien.");
    return std::get<float>(badge_);
}

int main()
{
    Character maija;
    maija.set('m');
    std::cout << "Maija: " << maija.get_name() << ", "
              << maija.get_identity() << "\n";
    maija.set('a');
    std::cout << "Maija: " << maija.get_name() << ", "
              << maija.get_identity() << "\n";
    
    Character rolle;
    rolle.set(12);
    std::cout << "Rolle: " << rolle.get_id() << ", "
              << rolle.get_identity() << "\n";

    Character allu;
    allu.set(12.92f);
    std::cout << "Allu: " << allu.get_wavelength() << ", " << allu.get_identity() << "\n";

    Character rex;
    rex.set('a');
    std::cout << "Rex identity: " << rex.get_identity() << "\n";
    std::cout << "Rex identity: " << rex.get_identity() << "\n";
    std::cout << "Rex: " << rex.get_id() << "\n";
}