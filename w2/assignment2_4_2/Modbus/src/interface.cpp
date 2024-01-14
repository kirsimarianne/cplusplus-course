#include "../includes/modbus.h"
#include "../includes/utility.h"
#include <fstream>
#include <iostream>

/* Function opens a file, loops the devices_map and register_vect
 * stores values to registers.csv file.
 * Function returns true if file created succesfully, and false if file could not be open.
 */
void create_registers_file(const DeviceMap &devices_map)
{
    std::ofstream registers_file("registers.csv");

    if (registers_file.is_open())
    {
        for (auto const device : devices_map)
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
        std::cout << "File registers.csv created succesfully.\n";
    }
    else
    {
        std::cout << "Unable to open the file registers.csv.\n";
    }
}

/* Function opens a file, loops the devices_map and stores values to devices.csv file.
 */
void create_devices_file(const DeviceMap &devices_map)
{
    std::ofstream devices_file("devices.csv");

    if (devices_file.is_open())
    {
        for (auto const device : devices_map)
        {
            devices_file << device.first << ',' << device.second.master << '\n';
        }
        std::cout << "File devices.csv created succesfully.\n";
    }
    else
    {
        std::cout << "Unable to open the file devices.csv.\n";
    }
}

/* Function calls get_int_input function.
 * Prints error message if needed.
 * Calls read_register function and prints new value.
 */
void read_register_value(const DeviceMap &device_map)
{
    int device_id = get_int_input("Give device id: ");
    int register_address = get_int_input("Give register address: ");
    if ((device_id == -1) || (register_address == -1))
    {
        std::cout << "Invalid input.\n";
    }
    else
    {
        int register_value = read_register(device_map, device_id, register_address);
        if (register_value == -1)
        {
            std::cout << "Could not found register address of given device id.\n";
        }
        else
        {
            std::cout << "Register found, value is " << register_value << "\n";
        }
    }
}

/* Function calls get_int_input function.
 * Prints error message if needed.
 * Calls change_register_value function
 * and create_registers_file function to update the file.
 */

void new_register_value(DeviceMap devices_map)
{
    int device_id = get_int_input("Give id of the device: ");
    int register_address = get_int_input("Give register address: ");
    int new_value = get_int_input("Give new value: ");
    if ((device_id == -1) || (register_address == -1) || (new_value == -1))
    {
        std::cout << "Invalid input.\n";
    }
    else
    {
        int updated_value = change_register_value(devices_map, device_id, register_address, new_value);
        if (updated_value == -1)
        {
            std::cout << "Changing value failed.\n";
        }
        else
        {
            std::cout << "Value changed succesfully.\n";
            create_registers_file(devices_map);
        }
    }
}