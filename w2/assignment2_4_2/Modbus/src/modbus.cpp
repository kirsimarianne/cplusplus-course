#include "../includes/modbus.h"

/* Function takes amount as a parameter and
 * creates sample data to regicter_vect as much as given amount,
 * Function returns created register_vect.
 */
std::vector<Register> create_register(int amount)
{
    std::vector<Register> register_vect{};
    Register register_struct{};
    static int address{100};
    static int value{10};
    for (int i = 0; i < amount; i++)
    {
        register_struct.address = address;
        register_struct.value = value;
        register_vect.push_back(register_struct);
        address++;
        value++;
    }
    return register_vect;
}

/* Function creates one master and 10 slave devices.
 * Calls create_register function.
 * Stores devices to vector and returns vector.
 */
std::unordered_map<DeviceID, DeviceStruct> create_devices()
{
    DeviceMap device_map{};
    DeviceStruct device{};
    static int id{0};
    for (int i = 0; i < 11; i++)
    {
        if (i == 0)
        {
            device.master = 1;
        }
        else
        {
            device.master = 0;
        }
        device.register_vector = create_register(5);
        device_map.insert(std::pair<DeviceID,DeviceStruct>(id, device));
        id++;
    }
    return device_map;
}
