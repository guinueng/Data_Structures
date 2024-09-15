#include "manager.h"

/* Write your code here */

// Manager Class
Manager::Manager() : device_count(0) {}

void Manager::add_device(Device* device){
    if(find_device(*device) == NULL) // Case 1. Non-Duplicated case.
        this -> devices[device_count++] = device;
    else // Case 2. Duplicated case.
        throw DuplicateDevice(device);
}

bool Manager::compare_device(int index, const Device& other) const{
    if(*(this -> devices[index]) == other) // Case 1. If given device is same as given index's device.
        return true; // former use * notation due to it is pointer to device class, but later one does not use it because it if reference to device class.
    else // Case 2. Else case.
        return false;
}

Device* Manager::find_device(const Device& search_device) const{
    for(int i = 0; i < this -> device_count; i++){ // Search given device is in Manager's device array.
        if(this -> compare_device(i, search_device)) // Compare it and if found same one,
            return this -> devices[i]; // return target's pointer value.
            // Using return is to give pointer value to whom called, and also ensures that
            // it is first time because function breaks(stops?) after return.
    }
    return NULL; // For nothing found case, return null pointer;
}

void Manager::delete_device(const Device& device){
    bool is_del = false;

    for(int i = 0; i < this -> device_count; i++){
        if(is_del == false && this -> compare_device(i, device)){ // Case 1. When finding deleting device.
            delete this -> devices[i]; // If found, delete that device.
            is_del = true; // Then, change status of is_del true.
        }
        else if(is_del == true && i < this -> device_count - 1){ // Case 2. If target deleted but remaining one left.
            this -> devices[i - 1] = this -> devices[i]; // Move remaining one to forward.
        }
        else if(is_del == true && i == this -> device_count - 1){ // Case 3. If target deleted and fetched on last part of array(value is valid).
            this -> devices[i - 1] = this -> devices[i]; // Move last one to before array position.
            this -> devices[i] = NULL; // Ensure that no duplicated value is locate in array.
            this -> device_count--; // Decrease device count 1 ensure that other function can't fetch into that position.
        }
    }
}

void Manager::print_all_devices() const{
    for(int i = 0; i < this -> device_count; i++)
        this -> devices[i] -> print_device(); // Using print_device function, we can print all of type's function due to virtual.
}

Manager::~Manager(){
    for(int i = 0; i < this -> device_count; i++)
        delete devices[i];
    this -> device_count = 0;
    // During destructing, we have to delete dynamically allocated ones.
}