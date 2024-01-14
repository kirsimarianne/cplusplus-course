#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

// Useful to the situation when cinstructor needs to return something.

class StaticObject
{
private:
    StaticObject(){}

public:
    static StaticObject init();
};

#endif