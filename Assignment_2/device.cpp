#include "device.h"

/* Write your code here */

Device::Device(int id, const std::string& type, const std::string& brand)
    :device_id(id), device_type(type), brand(brand) {}

bool Device::operator==(const Device& other) const{ // Compare all of component in device class.
    if(this -> device_id == other.device_id) // Case 1. device_id, type, and brand are all same.
        if(this -> device_type.compare(other.device_type) == 0)
            if(this -> brand.compare(other.brand) == 0) // Reference : https://cplusplus.com/reference/string/string/compare/
                return true;
    // Case 2. If one of them are different.
    return false;
}
bool Device::operator<(const Device& other) const{ // Operator <, >, <=, >= compares only device id.
    if(this -> device_id < other.device_id)
        return true;
    else
        return false;
}

bool Device::operator>(const Device& other) const{
    if(this -> device_id > other.device_id)
        return true;
    else
        return false;
}

bool Device::operator<=(const Device& other) const{
    if(this -> device_id <= other.device_id)
        return true;
    else
        return false;
}

bool Device::operator>=(const Device& other) const{
    if(this -> device_id >= other.device_id)
        return true;
    else
        return false;
}