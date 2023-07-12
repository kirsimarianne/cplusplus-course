#ifndef MODBUS_H
#define MODBUS_H

#include <unordered_map>
#include <vector>

struct Register
{
    int address {};
    int value {};
};

struct DeviceStruct
{
    bool master {0};
    std::vector<Register> register_vector {};
};

using DeviceID = int;
using DeviceMap = std::unordered_map<DeviceID, DeviceStruct>;

std::vector<Register> create_register(int amount);
DeviceMap create_devices();
int read_register(const DeviceMap& device_map, DeviceID id, int register_address);
int change_register_value(DeviceMap &devices_map, DeviceID id, int register_address, int new_value);

#endif