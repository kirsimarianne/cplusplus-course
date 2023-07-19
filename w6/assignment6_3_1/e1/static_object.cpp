#include "static_object.h"
#include <iostream>

StaticObject StaticObject::init()
{
    std::cout << "Inited here!" << "\n";
    return StaticObject();
}

int main()
{
    StaticObject object = StaticObject::init();
}