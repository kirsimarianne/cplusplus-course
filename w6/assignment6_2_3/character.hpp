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

    Character() = default;
    Character(int id);
    Character(char first_letter);
    Character(float wavelength);

    const Tag& get_tag() const;

    const std::string get_identity();
    const int& get_id() const;
    const char& get_first_letter() const;
    const float& get_wavelength() const;

    void set(int id);
    void set(char first_letter);
    void set(float wavelength);

    private:
    union
    {
        int id_;
        char first_letter_;
        float wavelength_;
    };
    Tag tag_{};
    
};

#endif