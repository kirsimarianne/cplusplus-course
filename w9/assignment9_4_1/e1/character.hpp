#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <variant>

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

    const Tag &get_tag() const;

    // acess different value types
    const std::string get_identity();
    const int& get_id() const;
    const std::string& get_name() const;
    const float& get_wavelength() const;

    // set stored value types
    void set(int id);
    void set(std::string name);
    void set(float wavelength);


    private:
    Tag tag_{};
    std::variant<int, std::string, float> badge_;
};


#endif