#include <iostream>
#include <vector>

// Base class
class Animal
{
public:
    // Default constructor.
    Animal(){};
    // Constructor with parameter
    Animal(std::string name)
    {
        name_ = name;
    }
    // Pure virtual function
    virtual void make_sound() const = 0;
    // Abstract but not pure virtual function.
    virtual void hair() const {};
    virtual std::string get_name() const
    {
        return name_;
    }
    virtual ~Animal() = default;

private:
    std::string name_{};
};

/* Lizard inherits Animal
*/
class Lizard : public Animal
{
public:
    Lizard()
    {
        name_ = "Leevi";
    };
    Lizard(std::string name)
    {
        name_ = name;
    }

    void make_sound() const override
    {
        std::cout << "Zzzsssh\n";
    }

    std::string get_name() const override
    {
        return name_;
    }

private:
    std::string name_{};
};

/* Dog inherits Animal
*/
class Dog : public Animal
{
public:
    Dog()
    {
        name_ = "Tessu";
    };
    Dog(std::string name)
    {
        name_ = name;
    }
    void make_sound() const override
    {
        std::cout << "Wof, wof!\n";
    }
    void hair() const override
    {
        std::cout << "Fluffy\n";
    };

    std::string get_name() const override
    {
        return name_;
    }
    virtual ~Dog() = default;

private:
    std::string name_{};
};

/* Chihuahua inherits Dog
*/
class Chihuahua : public Dog
{
public:
    Chihuahua()
    {
        name_ = "Minni";
    };
    Chihuahua(std::string name)
    {
        name_ = name;
    }
    void make_sound() const final override
    {
        std::cout << "Wif wif\n";
    }
    void hair() const final override
    {
        std::cout << "Short hair.\n";
    }

    std::string get_name() const override
    {
        return name_;
    }

private:
    std::string name_{};
};

void demonstrate_animal(Animal &animal)
{
    std::cout << "Animal info:\n";
    animal.make_sound();
    animal.hair();
    std::cout << "name: " << animal.get_name() << "\n\n";
}

int main()
{
    Lizard lilli("Lilli");
    Dog rex("Rex");
    Chihuahua def_chihu;

    demonstrate_animal(lilli);
    demonstrate_animal(rex);
    demonstrate_animal(def_chihu);

    /* This will not work. can not allocate object of an abstract type "Animal"
     * because of pure virtual function.
     */

    /*std::vector<Animal> animals_vect;
    animals_vect.push_back(lilli);
    animals_vect.push_back(rex);
    animals_vect.push_back(def_chihu);

    for(auto elem : animals_vect)
    {
        demonstrate_animal(elem);
    }*/
}