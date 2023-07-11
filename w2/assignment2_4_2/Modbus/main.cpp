#include "../includes/modbus.h"
#include <fstream>
#include <iostream>

/* Function opens a file, loops the devices_vect and register_vect
 * stores values to registers.csv file.
 * Function returns true if file created succesfully, and false if file could not be open.
 */
bool print_registers_to_file(const std::vector<Device> &devices_vect)
{
    std::ofstream registers_file("registers.csv");

    if (registers_file.is_open())
    {
        for (auto const device : devices_vect)
        {
            // Master device not printed
            if (device.master == 1)
            {
                continue;
            }
            registers_file << device.id << '\n';
            for (auto single_register : device.register_vector)
            {
                registers_file << single_register.address << ',' << single_register.value << '\n';
            }
        }
        registers_file.close();
        return true;
    }
    return false;
}

bool print_devices_to_file(const std::vector<Device> devices_vect)
{
    std::ofstream devices_file("devices.csv");

    if (devices_file.is_open())
    {
        for (auto const device : devices_vect)
        {
            devices_file << device.id << ',' << device.master << '\n';
        }
        return true;
    }
    return false;
}

int main()
{
    std::vector<Device> devices_vect{create_devices()};

    if (print_devices_to_file(devices_vect))
    {
         std::cout << "File devices.csv created succesfully.\n";
    }
    else
    {
        std::cout << "Unable to open the file devices.csv.\n";
    }
    if (print_registers_to_file(devices_vect))
    {
        std::cout << "File registers.csv created succesfully.\n";
    }
    else
    {
        std::cout << "Unable to open the file registers.csv.\n";
    }
}