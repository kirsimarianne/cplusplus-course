#include "order.h"
#include <iostream>

/* Function prints the current status of the order
*/
void print(const Status& status)
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
        {
            std::cout << "Could not found status.\n";
            break;
        }
    }
}

/* Function returns current status;
*/
Status Order::current_status()
{
    return status;
}

/* Function changes the status to next state
*/
void Order::advance_status()
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
    print(order.current_status());
    order.advance_status();
    print(order.current_status());
    order.advance_status();
    print(order.current_status());
    order.advance_status();
    print(order.current_status());
    order.advance_status();
    print(order.current_status());
    order.advance_status();
}
