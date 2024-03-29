#ifndef ORDER_H
#define ORDER_H

enum class Status
{
    ordered,
    packed,
    shipping,
    delivered,
    error,
};

class Order
{
public:
    Status current_status();
    void advance_status();
private:
    Status status = Status::ordered;
};

#endif