#ifndef INTERFACE_H
#define INTERFACE_H

#include "../includes/modbus.h"

void create_registers_file(const DeviceMap& devices_map);
void create_devices_file(const DeviceMap& devices_vect);
void read_register_value(const DeviceMap& device_map);
void new_register_value(DeviceMap devices_map);

#endif