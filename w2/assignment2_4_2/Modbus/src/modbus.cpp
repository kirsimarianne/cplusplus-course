#include "../includes/modbus.h"

#include <algorithm>

/* Function takes amount as a parameter and
 * creates sample data to register_vect as much as given amount,
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
DeviceMap create_devices()
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
        device_map.insert(std::pair<DeviceID, DeviceStruct>(id, device));
        id++;
    }
    return device_map;
}

/* Function finds device with given id and register of given address.
 * Function returns -1 if id or regsiter address is not found or device is master.
 * Function returns value of register if it is found.
*/
int read_register(const DeviceMap &device_map, DeviceID id, int register_address)
{
    // Check id can be found
    DeviceMap::const_iterator it_device = device_map.find(id);
    if (it_device != device_map.end())
    {
        // check device is slave
        if (it_device->second.master == 0)
        {
            for (const auto single_register : it_device->second.register_vector)
            {
                if (single_register.address == register_address)
                {

                    return single_register.value;
                }
            }
            return -1;
        }
        return -1;
    }
    return -1;
}

/* Function finds device with given id and register of given address.
 * Function returns -1 if id or register address is not found or device is master.
 * Function changes the value of given device with given register address and returns new value.
*/
int change_register_value(DeviceMap &devices_map, DeviceID id, int register_address, int new_value)
{
    DeviceMap::iterator it_device = devices_map.find(id);
    if (it_device != devices_map.end())
    {
        if (it_device->second.master == 0)
        {   
            for (auto& single_register : it_device->second.register_vector)
            {
                if (single_register.address == register_address)
                {
                    single_register.value = new_value;
                    return single_register.value;
                }
            }

            return -1;
        }
        return -1;
    }
    return -1;
}    