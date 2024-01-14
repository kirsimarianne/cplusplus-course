/* Exercise 1:
 * Overload the << operator for the class so you can directly output it's contents
 * with std::cout
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include <iostream>

enum class Tag
{
    robot,
    person,
    alien,
    not_found,
};

class Object
{
public:
    Object() = default;
    Object(int id);
    Object(char first_letter);
    Object(float wavelength);

    const Tag &get_tag() const;

    const std::string get_identity();
    const int &get_id() const;
    const char &get_first_letter() const;
    const float &get_wavelength() const;

    void set(int id);
    void set(char first_letter);
    void set(float wavelength);

    friend std::ostream &operator<<(std::ostream &os, const Object &obj);

private:
    union
    {
        int id_;
        char first_letter_;
        float wavelength_;
    };
    Tag tag_{};
};

std::ostream &operator<<(std::ostream &os, const Object &obj)
{
    if (obj.tag_ == Tag::robot)
    {
        os << obj.get_id() << ", robot\n";
    }
    else if (obj.tag_ == Tag::person)
    {
        os <<  obj.get_first_letter() << ", person\n";
    }
    else if (obj.tag_ == Tag::alien)
    {
        os <<  obj.get_wavelength() << ", alien\n";
    }
    else
    {
        os << "Error: identity not found\n";
    }

    return os;
}


#endif