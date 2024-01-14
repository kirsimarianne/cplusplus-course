#ifndef ANIMALS_HPP
#define ANIMALS_HPP

/* Exercise 2
 * In Ex. 7.4.1 we created a animals using virtual inheritance.  Recreate the same animals without using virtual, and then create a std::variant of the animals and fill a vector with those.
 * Look at documentation of std::visit, https://en.cppreference.com/w/cpp/utility/variant/visitLinks to an external site.
 * Using the "void visitor", call the demonstration function of each animal entry.
 * Using one of the type-matching visitors, print some text relating to the animal matched
 */

#include <iostream>

class Lizard
{
public:
    Lizard() { name_ = "Leevi"; };
    Lizard(std::string name) { name_ = name; }

    std::string make_sound() const { return sound_;}
    std::string get_name() const { return name_; }

private:
    std::string name_{};
     std::string sound_{"Zzzsssh\n"};
};


class Dog 
{
public:
    Dog() { name_ = "Tessu"; };
    Dog(std::string name) { name_ = name; }

    std::string make_sound() const { return sound_;}

    std::string get_name() const { return name_; }

    virtual ~Dog() = default;

private:
    std::string name_{};
    std::string sound_ = "Wuf, wuf\n";
};


class Pig
{
public:
    Pig() { name_ = "Nasu"; };
    Pig(std::string name) { name_ = name; }

    std::string make_sound() const { return sound_;}

    std::string get_name() const { return name_; }

private: 
    std::string name_{};
    std::string sound_ = "Nöf nöf\n";
};


#endif