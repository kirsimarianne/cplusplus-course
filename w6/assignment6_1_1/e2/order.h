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
    void current_status();
    void change_status();

private:
    Status status = Status::ordered;
};

#endif