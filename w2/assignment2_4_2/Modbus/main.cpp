#include "../includes/modbus.h"
#include <fstream>
#include <iostream>

/* Function gets string as a parameter,
 * converts string to int and returns integer.
 * Throws exception if converting fails.
 */
int string_to_int(std::string str)
{
    int integer{};
    try
    {
        integer = std::stoi(str);
    }
    catch (const std::invalid_argument &e)
    {
        throw e;
    }
    catch (const std::out_of_range &e)
    {
        throw e;
    }
    return integer;
}

/* Function opens a file, loops the devices_vect and register_vect
 * stores values to registers.csv file.
 * Function returns true if file created succesfully, and false if file could not be open.
 */
bool print_registers_to_file(const DeviceMap& device_map)
{
    std::ofstream registers_file("registers.csv");

    if (registers_file.is_open())
    {
        for (auto const device : device_map)
        {
            // Master device not printed
            if (device.second.master == 1)
            {
                continue;
            }
            registers_file << device.first << '\n';
            for (auto single_register : device.second.register_vector)
            {
                registers_file << single_register.address << ',' << single_register.value << '\n';
            }
        }
        registers_file.close();
        return true;
    }
    return false;
}

bool print_devices_to_file(const DeviceMap& devices_vect)
{
    std::ofstream devices_file("devices.csv");

    if (devices_file.is_open())
    {
        for (auto const device : devices_vect)
        {
            devices_file << device.first << ',' << device.second.master << '\n';
        }
        return true;
    }
    return false;
}

bool read_register(const DeviceMap& device_map, DeviceID id, int register_address)
{
    // Check id can be found
    DeviceMap::const_iterator it_device = device_map.find(id);
    if (it_device != device_map.end())
    {
        // check device is slave
        if (it_device->second.master == 0)
        {
            for(const auto single_register : it_device->second.register_vector)
            {
                if(single_register.address == register_address)
                {
                    std::cout << "Register found, value is " << single_register.value << "\n";
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    return false;
}

int main()
{
    DeviceMap device_map{create_devices()};

    if (print_devices_to_file(device_map))
    {
        std::cout << "File devices.csv created succesfully.\n";
    }
    else
    {
        std::cout << "Unable to open the file devices.csv.\n";
    }
    if (print_registers_to_file(device_map))
    {
        std::cout << "File registers.csv created succesfully.\n";
    }
    else
    {
        std::cout << "Unable to open the file registers.csv.\n";
    }

    std::cout << "Give id of the device: ";
    std::string input{};
    std::getline(std::cin, input);
    int id{};
    // Check input is int type
    try
    {
        id = string_to_int(input);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid id.\n\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Invalid id.\n\n";
    }

    std::cout << "Give register address: ";
    std::getline(std::cin, input);
    int register_address{};
    // Check input is int type
    try
    {
        register_address = string_to_int(input);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid register address.\n\n";
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Invalid register address.\n\n";
    }

    if(!read_register(device_map, id, register_address))
    {
        std::cout << "Could not found register address of given device id.\n";
    }
}

