#ifndef ANIMALS_H
#define ANIMALS_H
#include <string>
#include <iostream>

/* Base class
 */
class Animal
{
public:
    Animal()
    {
        std::cout << "Animal: default constructor" << "\n";
    }
    ~Animal()
    {
        std::cout << "Animal: destructor" << "\n";
    };
    void walk();

private:
};

/* Class has default constructor and constructor with parameters.
 * Created some own variables colour and size for testing and learning.
 */
class Eyes
{
public:
    Eyes();
    ~Eyes()
    {
        std::cout << "Eyes: destructor" << "\n";
    };
    Eyes(std::string colour, int size);
    std::string colour_;
    int size_;

private:
};

/* Class has default cosntructor and constructor with parameters.
 * Created own variable size for testing and learning.
 */
class Wings
{
public:
    // Default constructor
    Wings();
    ~Wings()
    {
        std::cout << "Wings: destructor" << "\n";
    };
    // Default constructor with parameters
    Wings(int size_);
    int size_;
private:
};

/* Dog class has following relations:
 * is-a animal
 * has-a eyes
 */
class Dog : public Animal
{
public:
    Eyes eyes_;
    // Default constructor
    Dog();
    ~Dog()
    {
        std::cout << "Dog: destructor" << "\n";
    };
    // Constructor with parameters
    Dog(Eyes eyes);
    void walk();

private:
};

/* Bird class has following relations:
 * is-a animal
 * has-a wings
 * has-a eyes
 */
class Bird : public Animal
{
public:
    Eyes eyes_;
    Wings wings_;
    // Default constructor
    Bird();
    ~Bird()
    {
        std::cout << "Bird: destructor" << "\n";
    };
    // Constructor with parameters
    Bird(Eyes eyes, Wings wings);

private:
};

/* Parrotclass has following relations:
 * is-a animal
 * has-a wings
 * has-a eyes
 */
class Parrot : public Bird
{
public:
    Eyes eyes_;
    Wings wings_;
    // Default constructor
    Parrot();
    ~Parrot()
    {
        std::cout << "Parrot: destructor" << "\n";
    };
    // Constructor with parameters
    Parrot(Eyes eyes, Wings wings);

private:
};

#endif