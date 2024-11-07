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
        Node* next;
    };

    static const int TABLE_SIZE = 1000; // do not change this line

    StudentMap() 
    {
        /* implement this fucntion*/
        for(int i = 0; i < TABLE_SIZE; i++)
            HASH_TABLE[i] == nullptr;
    }

    void add_student(int student_id, int score) // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE;
        if(HASH_TABLE[HASH_VALUE] == nullptr){
            HASH_TABLE[HASH_VALUE] = new Node{.student_id = student_id, .score = score, nullptr};
        }
        else{
            Node* pos = HASH_TABLE[HASH_VALUE];
            Node* last_pos = HASH_TABLE[HASH_VALUE];
            while(pos != nullptr){
                pos = pos -> next;
                if(pos != nullptr)
                    last_pos = pos;
            }
            last_pos -> next = new Node{.student_id = student_id, .score = score, nullptr};
        }
    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE;
        Node* pos = HASH_TABLE[HASH_VALUE];
        while(pos -> student_id != student_id && pos != nullptr){
            pos = pos -> next;
        }
        if(pos == nullptr)
            throw std::runtime_error("Student ID not found");
        else
            pos -> score = new_score;
        return;
    }

    int get_score(int student_id) const  // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE;
        Node* pos = HASH_TABLE[HASH_VALUE];
        while(pos -> student_id != student_id && pos != nullptr){
            pos = pos -> next;
        }
        if(pos == nullptr)
            throw std::runtime_error("Student ID not found");
        else
            return pos -> score;
    }

    void remove_student(int student_id)  // do not change this line
    {
        /* implement this function*/
        int HASH_VALUE = student_id % TABLE_SIZE;
        Node* pos = HASH_TABLE[HASH_VALUE];
        bool prev_data = false;
        while(pos -> student_id != student_id && pos != nullptr){ // Need to modify it.
            if(pos -> next -> student_id == student_id){
                prev_data = true;
                break;
            }
            pos = pos -> next;
        }
        if(pos == nullptr)
            throw std::runtime_error("Student ID not found");
        else if(pos == HASH_TABLE[HASH_VALUE] && prev_data == false){
            Node* next_elem = pos -> next;
            delete pos;
            HASH_TABLE[HASH_VALUE] = next_elem;
        }
        else{
            Node* next_elem = pos -> next -> next;
            delete pos -> next;
            pos -> next = next_elem;
        }
        return;
    }
    
    ~StudentMap() 
    {
        /* implement this function*/
        for(int i = 0; i < TABLE_SIZE; i++){
            Node* target_ptr = HASH_TABLE[i];
            while(target_ptr != nullptr){
                Node* tmp = target_ptr -> next;
                delete target_ptr;
                target_ptr = tmp;
            }
        }
    }

    /* add whatever you want */
    private:
    Node* HASH_TABLE[TABLE_SIZE];
};

#endif