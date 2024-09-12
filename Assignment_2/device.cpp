#include "device.h"

/* Write your code here */

//Device Class.
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
        return true; // Case 1. This device id < other device id.
    else // Case 2. Else
        return false;
}

bool Device::operator>(const Device& other) const{ // Below operator are similar as operator < case.
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

// Phone Class
Phone::Phone(int id, const std::string& brand, int data_usage)
    : Device(id, "Phone", brand), data_usage(data_usage) {}

void Phone::print_device() const{
    std::cout << "Phone[ID: " << this -> device_id << ", Brand: " << this -> brand
                << ", Data Usage: " << this -> data_usage << "GB]" << std::endl;
}

bool Phone::operator<(const Phone& other) const{
    if(this -> data_usage < other.data_usage)
        return true; // Case 1. This data usage < other's data usage.
    else // Case 2. Else case.
        return false;
}

bool Phone::operator>(const Phone& other) const{ // Below operator are similar as operator < case.
    if(this -> data_usage > other.data_usage)
        return true;
    else
        return false;
}

bool Phone::operator<=(const Phone& other) const{
    if(this -> data_usage <= other.data_usage)
        return true;
    else
        return false;
}

bool Phone::operator>=(const Phone& other) const{
    if(this -> data_usage >= other.data_usage)
        return true;
    else
        return false;
}

// Watch Class
