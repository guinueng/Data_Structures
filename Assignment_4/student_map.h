#ifndef STUDENT_MAP_H
#define STUDENT_MAP_H
#include <exception>
#include <cstdlib>
#include <string>
#include <iostream>

class StudentMap { // do not change this line
public:
    struct Node // do not change this line
    {
        int student_id; // do not change this line
        int score; // do not change this line
        /* add whatever you want */
        Node* next; // To make Node as singly linked list due to implement separate chaining for collision handling method.
    };

    static const int TABLE_SIZE = 1000; // do not change this line

    StudentMap() 
    {
        /* implement this function*/
        for(int i = 0; i < TABLE_SIZE; i++){
            HASH_TABLE[i] = nullptr; // Initialize hash table by nullptr.
        }
    }

    void add_student(int student_id, int score) // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE; // Calc hash value by modular 1000 calculation which is size of table.

        if(HASH_TABLE[HASH_VALUE] == nullptr){ // If given elem is first,
            HASH_TABLE[HASH_VALUE] = new Node{.student_id = student_id, .score = score, nullptr}; // assign new value and store into hash table.
        }
        else{ // If not, assign new element from last element's next element.
            Node* pos = HASH_TABLE[HASH_VALUE];
            Node* last_pos = HASH_TABLE[HASH_VALUE];
            while(pos -> next != nullptr) // We need to find last element. Check current position's next is not null ptr,
                pos = pos -> next; // Then update position to next.
            pos -> next = new Node{.student_id = student_id, .score = score, nullptr}; // If found last elem, update last elem's next to new elem.
        }

        return;
    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE; // Calc hash value by modular 1000 calculation which is size of table.
        Node* pos = HASH_TABLE[HASH_VALUE]; // Get first separate chaining element position by using hash table.

        while(pos != nullptr && pos -> student_id != student_id){ // Check hash table value is non exist(in first execution) or target position is not exist
            pos = pos -> next; // and if current position value is not matched with target student id, update position to next.
        }

        if(pos == nullptr){
            throw std::runtime_error("Student ID not found"); // Throw if there is not exist value.
        }
        else{
            pos -> score = new_score; // If exist, update score to new score.
        }

        return;
    }

    int get_score(int student_id) const  // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE; // Calc hash value by modular 1000 calculation which is size of table.
        Node* pos = HASH_TABLE[HASH_VALUE]; // Get first separate chaining element position by using hash table.

        while(pos != nullptr && pos -> student_id != student_id){ // Check hash table value is non exist(in first execution) or target position is not exist
            pos = pos -> next; // and if current position value is not matched with target student id, update position to next.
        }

        if(pos == nullptr){
            throw std::runtime_error("Student ID not found"); // Throw if there is not exist value.
        }
        else{
            return pos -> score; // If exist, return score value.
        }
    }

    void remove_student(int student_id)  // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE; // Calc hash value by modular 1000 calculation which is size of table.
        Node* pos = HASH_TABLE[HASH_VALUE]; // Get first separate chaining element position by using hash table.
        bool prev_data = false; // Set prev_data false to ensure that first value is not pointing previous value, which denotes it is first value.

        while(pos != nullptr && pos -> student_id != student_id){ // Check hash table value is non exist(in first execution) or target position is not exist.
            // and check current position's student id is not matched target student id.
            if(pos -> next != nullptr && pos -> next -> student_id == student_id){ // Then, check next element of target has target student id and before to do that,
                // we need to consider next elem has proper value or empty.
                prev_data = true; // If true, change prev_data to true to ensure that this value refers prev value of target for deletion.
                break; // Then, exit loop.
            }

            pos = pos -> next; // If not, keep tracking to next element.
        }

        if(pos == nullptr){ // If target does not exist, throw exception.
            throw std::runtime_error("Student ID not found");
        }
        else if(pos == HASH_TABLE[HASH_VALUE] && prev_data == false){ // If position is same as hash table value and it is not previous data, we can ensure that
            Node* next_elem = pos -> next; // this value is first element. Then, store next element pointer temporary.
            delete pos; // Then delete current position which is first elem.
            HASH_TABLE[HASH_VALUE] = next_elem; // Then, update hash table as next elem which now it is first elem.
        }
        else{ // Else, get target's next elem and store temporarily.
            Node* next_elem = pos -> next -> next;
            delete pos -> next; // Then, delete target.
            pos -> next = next_elem; // Finally, connect target's prev elem and next elem.
        }

        return;
    }
    
    ~StudentMap() 
    {
        /* implement this function*/
        for(int i = 0; i < TABLE_SIZE; i++){
            Node* target_ptr = HASH_TABLE[i]; // Assign target value by using hash table.

            while(target_ptr != nullptr){ // Check target is exist or not.
                Node* tmp = target_ptr -> next; // Assign next element to temporary.
                delete target_ptr; // Delete existing element.
                target_ptr = tmp; // Update target pointer to next element.
            }
        }
    }

    /* add whatever you want */
    private:
    Node* HASH_TABLE[TABLE_SIZE]; // Hash table container.
};

#endif