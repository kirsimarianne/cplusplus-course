#include "../includes/interface.h"
#include "../includes/modbus.h"
#include "../includes/utility.h"
#include <iostream>

int main()
{
    DeviceMap devices_map{create_devices()};

    create_devices_file(devices_map);
    create_registers_file(devices_map);
    read_register_value(devices_map);
    new_register_value(devices_map);
}
