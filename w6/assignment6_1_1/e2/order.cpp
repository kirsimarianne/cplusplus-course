#include "order.h"
#include <iostream>

void Order::current_status()
{
    switch (status)
    {
    case Status::ordered:
    {
        std::cout << "Ordered\n";
        break;
    }
    case Status::packed:
    {
        std::cout << "Packed\n";
        break;
    }
    case Status::shipping:
    {
        std::cout << "Shipping\n";
        break;
    }
    case Status::delivered:
    {
        std::cout << "Delivered\n";
        break;
    }
    case Status::error:
        std::cout << "Could not found status.\n";
    }
}

void Order::change_status()
{
    if (status == Status::ordered)
    {
        status = Status::packed;
    }
    else if (status == Status::packed)
    {
        status = Status::shipping;
    }
    else if (status == Status::packed)
    {
        status = Status::shipping;
    }
    else if ((status == Status::shipping) || (status == Status::delivered))
    {
        status = Status::delivered;
    }
    else
    {
        status = Status::error;
    }
}

int main()
{
    Order order{};
    order.current_status();
    order.change_status();
    order.current_status();
    order.change_status();
    order.current_status();
    order.change_status();
    order.current_status();
    order.change_status();
    order.current_status();
    order.change_status();
}
