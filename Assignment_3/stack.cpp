/* Write your code here */
#include "stack.h"
#include "container_exception.h"

Stack::Stack(int size) : capacity(size), top_index(-1), data(new std::string[100]) {}

Stack::~Stack(){
    delete[] data; // Deleting dynamically allocated string array.
}

bool Stack::empty() const{
    if(top_index == -1) // If top_index == -1, which is empty state
        return true; // return true.
    return false; // Else, return false.
}

const std::string& Stack::top() const{
    if(empty()) // If stack is empty state, throw exception.
        throw ContainerEmpty("Container is empty");
    return data[top_index]; // Else, return element of target index.
}

void Stack::push(const std::string& e){
    data[++top_index] = e; // Put data into desired position.
}

void Stack::pop(){
    if(empty()) // If stack is empty,
        throw ContainerEmpty("Container is empty"); // throw exception.
    top_index--; // Else, decrease top_index which works as deleting element.
}

int Stack::size() const{
    return top_index + 1; // Due to top_index start w/ -1 but it's state is 0,
    // return +1 value of top_index to get real value.
}
