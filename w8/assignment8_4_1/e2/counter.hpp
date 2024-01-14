#ifndef COUNT_HPP
#define COUNT_HPP


class Counter
{

public:
    Counter();
    ~Counter();

    Counter(const Counter &) = delete;

    Counter(Counter &&other);
    Counter &operator=(Counter &&other);

    int static count;

private:
    bool is_moved{false};
};

#endif