/* Write your code here */
#include "deque.h"
#include "stack.h"
#include "container_exception.h"

bool Deque::empty() const{
    if(list.empty()) // If list is empty, deque also empty,
        return true; // thus return true.
    return false; // Else, return false.
}

int Deque::size() const{
    return list.size(); // Get size of list.
}

const std::string& Deque::front() const{
    return list.front(); // Get front value of list.
}

const std::string& Deque::back() const{
    return list.back(); // Get back value of list.
}

void Deque::push_front(const std::string& e){
    list.add_front(e); // Add element in the front of list.
}

void Deque::push_back(const std::string& e){
    list.add_back(e); // Add element in the back of list.
}

void Deque::pop_front(){
    list.remove_front(); // Remove element in the front of list.
}

void Deque::pop_back(){
    list.remove_back(); // Remove element in the back of list.
}
// Exception of empty container in above will be handled in function of list.

void Deque::reverse(){
    Stack tmp(size()); // Create stack as size of current deque size.
    while(!empty()){ // During not empty, put current front to last element into stack.
        tmp.push(front());
        pop_front(); // Then, remove pushed element into deque.
    }
    while(!tmp.empty()){ // Then during not empty of stack, push back top element of stack into deque.
        push_back(tmp.top());
        tmp.pop(); // Then, remove pushed element into stack.
    }
}
