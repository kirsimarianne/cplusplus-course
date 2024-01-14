#include "character.h"
#include <iostream>
#include <cassert>

void Character::set_tag(Tag tag)
{
    this->tag = tag;
}

const Tag& Character::get_tag() const
{
    return tag;
}

const std::string Character::get_identity()
{
    if(tag == Tag::robot)
    {
        return std::to_string(id);
    }
    else if(tag == Tag::person)
    {
        return std::string{first_letter};
    }
    else if(tag == Tag::alien)
    {
        return std::to_string(wavelength);
    }
    else
    {
        return "Error: identity not found";
    }
}

void Character::set(int id)
{
    if(tag == Tag::robot)
    {
        this->id = id;
    }
    else
    {
        set_tag(Tag::not_found);
    }
}

void Character::set(char first_letter)
{
    if(tag == Tag::person)
    {
        this->first_letter = first_letter;
    }
    else
    {
        set_tag(Tag::not_found);
    }
}

void Character::set(float wavelength)
{
    if(tag == Tag::alien)
    {
        this->wavelength = wavelength;
    }
    else
    {
        set_tag(Tag::not_found);
    }
}

const int& Character::get_id() const
{
    return id;
}

const char& Character::get_first_letter() const
{
    return first_letter;
}

const float& Character::get_wavelength() const
{
    return wavelength;
}

int main()
{
    Character maija;
    maija.set_tag(Tag::person);
    maija.set('m');
    std::cout << "Maija: " << maija.get_identity() << "\n";
    assert(maija.get_tag() == Tag::person);
    assert(maija.get_identity() == "m");
    assert(maija.get_first_letter() == 'm');

    Character rolle;
    rolle.set_tag(Tag::robot);
    rolle.set(12);
    std::cout << "Rolle: " << rolle.get_identity() << "\n";
    assert(rolle.get_tag() == Tag::robot);
    assert(rolle.get_identity() == "12");
    assert(rolle.get_id() == 12);

    Character allu;
    allu.set_tag(Tag::alien);
    allu.set(12.92f);
    std::cout << "Allu: " << allu.get_identity() << "\n";
    assert(allu.get_tag() == Tag::alien);
    assert(allu.get_identity() == "12.920000");
    assert(allu.get_wavelength() == 12.92f);

    Character rex;
    rex.set_tag(Tag::alien);
    rex.set('a');
    std::cout << "Rex: " << rex.get_identity() << "\n";
    assert(rex.get_tag() == Tag::not_found);
    assert(rex.get_identity() == "Error: identity not found");
}