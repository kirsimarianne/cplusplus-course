#include "animals.h"
#include <string>
#include <iostream>

void Animal::walk()
{
    std::cout << "Animal walking" << "\n";
}

void Dog::walk()
{
    std::cout << "Dog walking" << "\n";
}

Eyes::Eyes()
{
    std::cout << "Eyes: default constructor" << "\n";
    colour_ = "";
    size_ = 0;
}

Eyes::Eyes(std::string colour, int size)
{
    std::cout << "Eyes: constructor called with parameters: " 
    << colour << " "
    << size << "\n";
    colour_ = colour;
    size_ = size;
}

Wings::Wings()
{
    std::cout << "Wings: default constructor" << "\n";
    size_ = 0;
}

Wings::Wings(int size)
{
     std::cout << "Wing: constructor called with paramer: " 
    << size << "\n";
    size_ = size;
}

// Dog has brown eyes and size 5 as a default.
Dog::Dog() : eyes_("brown", 5){
    std::cout << "Dog: default constructor" << "\n";
};

Dog::Dog(Eyes eyes)
{
    std::cout << "Dog: constructor with parameters called" << "\n";
    eyes_ = eyes;
}

// Bird has blue and size 1 eyes and size 5 wings as a default
Bird::Bird() : eyes_("blue", 1), wings_(5){
    std::cout << "Bird: default constructor" << "\n";
};

Bird::Bird(Eyes eyes, Wings wings)
{
    std::cout << "Bird: constructor with parameters called" << "\n";
    eyes_ = eyes;
    wings_ = wings;
}

// Parrot has green and size 2 eyes and size 3 wings as a default
Parrot::Parrot() : eyes_("green", 2), wings_(3){
    std::cout << "Parrot: default constructor" << "\n";
};

Parrot::Parrot(Eyes eyes, Wings wings)
{
    std::cout << "Parrot: constructor with parameters called" << "\n";
    eyes_ = eyes;
    wings_ = wings;
}


int main()
{
    std::cout << "Create an animal and dog\n";
    Animal my_first_animal;
    Dog my_first_dog;
    std::cout << "\nCall both creators' walk function\n";
    my_first_animal.walk();
    my_first_dog.walk();
    std::cout << "\nDestroy animal and dog\n";
    my_first_animal.~Animal();
    my_first_dog.~Dog();

    std::cout << "\nMY OWN TESTING" << "\n";
    Dog default_dog;
    std::cout << "Default dog: " 
    << default_dog.eyes_.colour_ << " " 
    << default_dog.eyes_.size_ << "\n\n";

    Eyes big_blue_eyes("blue", 10);
    Dog my_dog(big_blue_eyes);
    std::cout << "My dog: " 
    << my_dog.eyes_.colour_ << " " 
    << my_dog.eyes_.size_ << "\n\n";    

    Bird default_bird;
    std::cout << "Default bird: " 
    << default_bird.eyes_.colour_ << " " 
    << default_bird.eyes_.size_ << " "
    << default_bird.wings_.size_ << "\n\n";

    Parrot default_parrot;
    std::cout << "Default parrot: " 
    << default_parrot.eyes_.colour_ << " " 
    << default_parrot.eyes_.size_ << " "
    << default_parrot.wings_.size_ << "\n\n";

    Wings big_wings = 15;
    Parrot my_parrot(big_blue_eyes, big_wings);
    std::cout << "My parrot: " 
    << my_parrot.eyes_.colour_ << " " 
    << my_parrot.eyes_.size_ << " "
    << my_parrot.wings_.size_ << "\n\n";
}