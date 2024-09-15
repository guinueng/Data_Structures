ReadMe.txt for GwanUk Lee(20211216)

1. Device class
    Constructor is used to put values in class member.
    Destructor is not used due to there is no dynamically allocated parts.
    For operator ==, I used compare function in <string>.
    Reference : https://cplusplus.com/reference/string/string/compare/
    And there is case when all member variable is same or not.
    In device class, there is operator >, <, <=, >= which compares device_id.

2. Phone / Watch class
    Constructor is used to put values in member variables and it also uses parent's constructor which is derived class.
    Destructor is not used due to there is no dynamically allocated parts.
    These class has operator <, >, <=, >=, which compares their own member variable(Phone : Data Usage, Watch : Step Count).
    And it has print_device function which allows to print each information.

3. Ring / Earbuds class
    It is same as Phone / Watch class, but does not have own operator <, >, <=, >=.
    It just inherits Device class.

4. Manager class
    In this class, it has two member variables which contains array of pointer to device class and device_count.
    During construction, we have to initialize device count to 0, but not need to assign specific value into pointer to device class.
    In add_device function, we get pointer to device. Check whether it is duplicated or not.
    If duplicate one is given, throw to DuplicateDevice to handle error which learned on class.
    Else, save it into array.
    It uses compare_device function which will discussed in below.
    We have compare_device and find_device function which use operator== of Device class.
    Former one gets compare target and certain position of array in member variable.
    It compares by using operator== function in device class. If operator== returns true, function returns true.
    Else, it returns false.
    Later one compares given device and array in class. If found, return target device's pointer.
    Else, return NULL pointer. In this way, we can distinguish given device is exist on member variable's array or not.
    In delete_device function, it use compare_device member function to find deleting target exist in devices array in member variable.
    If found delete it and change status of is_del variable in function true.
    Then, keep moving forward for later part of array.
    If we arrive at last part of array, decrease device_count. To be sure, make last part of array as NULL.
    In print_all_devices function, I use for loop and print_device function on device class.
    Finally for destructor, we have dynamically allocated part which is stored in devices array.
    Thus, by using for loop, we manually delete it's variable.
    Then, make each array as NULL and device_count to 0 not to access deleted parts.

5. Makefile
    On personal purpose, first I used address sanitizer to find memory leaks, heap-use-after-free, or other mistakes.
    Then, when complete assignment, I changed Makefile as given on skeleton-code files.