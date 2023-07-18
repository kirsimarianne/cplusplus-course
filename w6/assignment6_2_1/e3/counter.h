#ifndef COUNTER_H
#define COUNTER_H

class Counter
{

private:
    static int count;

public:
    Counter();
    ~Counter();

    static int get()
    {
        return count;
    }
};

#endif
