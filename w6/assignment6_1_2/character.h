#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

enum class Tag
{
    robot,
    person,
    alien,
    not_found,
};

class Character
{
    public:

    // check what type of object is stored
    void set_tag(Tag tag);
    const Tag& get_tag() const;

    // acess different value types
    const std::string get_identity();
    const int& get_id() const;
    const char& get_first_letter() const;
    const float& get_wavelength() const;

    // set stored value types
    void set(int id);
    void set(char first_letter);
    void set(float wavelength);

    private:
    Tag tag{};
    union
    {
        int id;
        char first_letter;
        float wavelength;
    };
    
};


#endif