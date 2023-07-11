#include <vector>

struct Register
{
    int address {};
    int value {};
};

struct Device
{
    int id {};
    bool master {0};
    std::vector<Register> register_vector {};
};


std::vector<Register> create_register(int amount);
std::vector<Device> create_devices();

