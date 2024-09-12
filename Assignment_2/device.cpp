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

Device::~Device() {}

// Phone Class
Phone::Phone(int id, const std::string& brand, int data_usage)
    : Device(id, "Phone", brand), data_usage(data_usage) {}

void Phone::print_device() const{
    std::cout << "Phone [ID: " << this -> device_id << ", Brand: " << this -> brand
                << ", Data Usage: " << this -> data_usage << "GB]" << std::endl;
}

bool Phone::operator<(const Phone& other) const{ // Operator only exist in Phone and Watch class.
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

Phone::~Phone() {}

// Watch Class
Watch::Watch(int id, const std::string& brand, int step_count)
    : Device(id, "Watch", brand), step_count(step_count) {}

void Watch::print_device() const{
    std::cout << "Watch [ID: " << this -> device_id << ", Brand: " << this -> brand
                << ", Step Count: " << this -> step_count << "]" << std::endl;
}

bool Watch::operator<(const Watch& other) const{
    if(this -> step_count < other.step_count)
        return true; // Case 1. This step_count < other's step_count.
    else // Case 2. Else case.
        return false;
}

bool Watch::operator>(const Watch& other) const{ // Below operator are similar as operator < case.
    if(this -> step_count > other.step_count)
        return true;
    else
        return false;
}

bool Watch::operator<=(const Watch& other) const{
    if(this -> step_count <= other.step_count)
        return true;
    else
        return false;
}

bool Watch::operator>=(const Watch& other) const{
    if(this -> step_count >= other.step_count)
        return true;
    else
        return false;
}

Watch::~Watch() {}

//Ring Class
Ring::Ring(int id, const std::string& brand, bool sleep_tracking)
    : Device(id, "Ring", brand), sleep_tracking(sleep_tracking) {}

void Ring::print_device() const{
    if(this -> sleep_tracking) // Case 1. Sleep Tracking is enabled.
        std::cout << "Ring [ID: " << this -> device_id << ", Brand: " << this -> brand
                    << ", Sleep Tracking: Enabled]" << std::endl;
    else // Case 2. Sleep Tracking is disabled.
        std::cout << "Ring [ID: " << this -> device_id << ", Brand: " << this -> brand
                    << ", Sleep Tracking: Disabled]" << std::endl;
}

Ring::~Ring() {}

// Earbud Class
Earbud::Earbud(int id, const std::string& brand, bool noise_cancel)
    : Device(id, "Earbud", brand), noise_cancellation(noise_cancel) {}

void Earbud::print_device() const{
    if(this -> noise_cancellation) // Case 1. Sleep Tracking is enabled.
        std::cout << "Earbud [ID: " << this -> device_id << ", Brand: " << this -> brand
                    << ", Noise Cancellation: Enabled]" << std::endl;
    else // Case 2. Sleep Tracking is disabled.
        std::cout << "Earbud [ID: " << this -> device_id << ", Brand: " << this -> brand
                    << ", Noise Cancellation: Disabled]" << std::endl;
}

Earbud::~Earbud() {}