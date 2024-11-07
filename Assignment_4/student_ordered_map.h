#ifndef STUDENT_ORDERED_MAP_H
#define STUDENT_ORDERED_MAP_H
#include <exception>
#include <cstdlib>
#include <string>
#include <iostream>

class StudentOrderedMap { // do not change this line
public:
    struct Node { // do not change this line
        int student_id; // do not change this line
        int score; // do not change this line

        /* add whatever you want */
        Node* up;
        Node* down;
        Node* prev;
        Node* next;
    };

    StudentOrderedMap() 
    {
        /* implement this fucntion*/
        init_skip_list[0] = new Node{.student_id = NULL, .score = -1, .up = nullptr, .down = nullptr, .prev = nullptr};
        init_skip_list[1] = new Node{.student_id = NULL, .score = 101, .up = nullptr, .down = nullptr, .next = nullptr};
        init_skip_list[0] -> next = init_skip_list[1];
        init_skip_list[1] -> prev = init_skip_list[0];
        skip_list_qty = 0;
    }

    
    void add_student(int student_id, int score)  // do not change this line
    {
        /* implement this function*/
        int coin = 0; // Define coin toss qty as 0.
        while(std::rand() % 2 != 0){ // If value is 0, it denotes head. Else, it denotes tail.
            coin++; // If random value gives head, increase coin toss qty.
        }
        std::cout << "Coin: " << coin << std::endl;
        std::cout << "skip_list_qty: " << skip_list_qty << std::endl;

        int height = (skip_list_qty <= coin)? (coin + 1) : skip_list_qty;
        std::cout << "updated height: " << height << std::endl;
        bool inserted = false;


        Node* head = init_skip_list[0];
        Node* tail = init_skip_list[1];
        Node* before_elem;
        for(int i = 1; i <= height; i++){
            if(head -> down != nullptr){
                std::cout << "Not newly created case." << std::endl;
                head = head -> down;
                tail = tail -> down;
                if(i >= (height - coin)){
                    std::cout << "But need to add existing list case." << std::endl;
                    if(head -> next != tail){
                        Node* cur_elem = head;
                        while(cur_elem -> next -> score < score){
                            cur_elem = cur_elem -> next;
                        }
                        Node* next_elem = cur_elem -> next;
                        Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = cur_elem, .next = next_elem};
                        if(inserted){
                            new_elem -> up = before_elem;
                            before_elem -> down = new_elem;
                        }
                        else{
                            inserted = true;
                        }
                        next_elem -> prev = new_elem;
                        cur_elem -> next = new_elem;
                        before_elem = new_elem;
                    }
                    else{ // head -> next == tail case.
                        Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = head, .next = tail};
                        if(inserted){
                            new_elem -> up = before_elem;
                            before_elem -> down = new_elem;
                        }
                        else{
                            inserted = true;
                        }
                        before_elem = new_elem;
                        head -> next = new_elem;
                        tail -> prev = new_elem;
                    }
                }
                else{
                    // Nothing to do.
                }
            }
            else{
                std::cout << "Newly created case." << std::endl;
                head -> down = new Node{.student_id = NULL, .score = -1, .up = head, .down = nullptr, .prev = nullptr};
                tail -> down = new Node{.student_id = NULL, .score = 101,.up = tail, .down = nullptr, .next = nullptr};
                Node* origin_elem = head -> next; // Pointing current list(exist list) element.
                head = head -> down; // Pointing head/tail of list has changed to new assigned one.
                tail = tail -> down;
                head -> next = tail;
                tail -> prev = head;
                std::cout << "FIN assign part." << std::endl;
                
                if(origin_elem == tail -> up){ // If above list has only two special key.
                    std::cout << "Above list is empty." << std::endl;
                    if(i >= (height - coin)){
                        Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = head, .next = tail};
                        head -> next = new_elem;
                        tail -> prev = new_elem;
                        if(inserted){
                            new_elem -> up = before_elem;
                            before_elem -> down = new_elem;
                        }
                        else{
                            inserted = true;
                        }
                        before_elem = new_elem;
                    }
                }
                else{
                    std::cout << "Above list is not empty." << std::endl;
                    Node* cur_elem = head; // Pointing current list(new assigned list) element.
                    while(origin_elem != tail -> up){
                        if(!inserted && i >= (height - coin) && origin_elem -> score >= score){ // When inserting new element.
                            Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = cur_elem, .next = cur_elem -> next};
                            cur_elem -> next -> prev = new_elem;
                            cur_elem -> next = new_elem;
                            cur_elem = cur_elem -> next;
                            inserted = true;
                            before_elem = new_elem;
                        }
                        else{
                            Node* new_elem = new Node{.student_id = origin_elem -> student_id, .score = origin_elem -> score,
                                .up = origin_elem, .down = nullptr, .prev = cur_elem, .next = cur_elem -> next};
                            origin_elem -> down = new_elem;
                            cur_elem -> next -> prev = new_elem;
                            cur_elem -> next = new_elem;
                            cur_elem = cur_elem -> next;
                            if(origin_elem == before_elem){
                                before_elem -> down = new_elem;
                                new_elem -> up = before_elem;
                                before_elem = new_elem;
                            }
                            origin_elem = origin_elem -> next;
                        }
                    }
                }
            }
        }
        std::cout << "Finish insertion" << std::endl;
        skip_list_qty = height; // Update skip_list_qty;
        return;
    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this function*/

    }

    int get_student(int score) const // do not change this line
    {
        /* implement this function*/
        Node* head = init_skip_list[0] -> down;
        Node* tail = init_skip_list[1] -> down;
        while(head != tail){
            while(head -> next -> score < score){ // Scan forward.
                head = head -> next;
            }
            if(head -> next -> score == score){ // If found target value, return target's student id.
                return head -> next -> student_id;
            }
            head = head -> down; // Dropdown precess.
            tail = tail -> down;
        }
        throw std::runtime_error("Student ID not found"); // Throw if there is not exist value.
    }

    void remove_student(int student_id) // do not change this line
    {
        /* implement this function*/
        Node* cursor = init_skip_list[0];
        Node* tail = init_skip_list[1];
        std::cout << "first" << std::endl;
        while(cursor -> down != nullptr){
            std::cout << "In list" << std::endl;
            Node* tmp = cursor;
            while(cursor != tail){
                std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
                cursor = cursor -> next;
            }
            std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
            std::cout << "End list" << std::endl << std::endl;
            cursor = tmp;
            cursor = cursor -> down; // Fetch to bottom.
            tail = tail -> down;
        }

        std::cout << "In last list" << std::endl;
        while(cursor != tail){
            std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
            cursor = cursor -> next;
        }
        std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
        std::cout << "End list" << std::endl << std::endl;
        cursor = init_skip_list[0] -> down;
        while(cursor -> down != nullptr){
            cursor = cursor -> down; // Fetch to bottom.
        }

        while(cursor != tail && cursor -> student_id != student_id){
            std::cout << "Cur: " << cursor -> student_id << ": " << cursor -> score << std::endl;
            cursor = cursor -> next; // Find target element is exist on bottom.
            std::cout << "Next : " << cursor -> student_id << ": " << cursor -> score << std::endl << std::endl;
        }
        //cursor = cursor -> next;
        std::cout << "END" << std::endl << cursor -> student_id << ": " << cursor -> score << std::endl;
        if(cursor == tail){ // If target not exist in bottom, no exist in entire skip list.
            throw std::runtime_error("Student ID not found"); // Thus, throw error.
        }
        else{ // If exist, delete target entirely.
            std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
            while(cursor -> up != nullptr){
                Node* tmp = cursor -> up; // Temporarily store above pointer.
                std::cout << "above : " << cursor -> up -> student_id << ": " << cursor -> up -> score << std::endl;
                cursor -> prev -> next = cursor -> next; // Connect deletion target's prev/next one.
                cursor -> next -> prev = cursor -> prev;
                delete cursor; // Delete target.
                cursor = tmp; // Update deletion target as above one.
            }

            cursor = init_skip_list[0];
            tail = init_skip_list[1];
            std::cout << "After removal first" << std::endl;
            while(cursor -> down != nullptr){
                std::cout << "In list" << std::endl;
                Node* tmp = cursor;
                while(cursor != tail){
                    std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
                    cursor = cursor -> next;
                }
                std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
                std::cout << "End list" << std::endl << std::endl;
                cursor = tmp;
                cursor = cursor -> down; // Fetch to bottom.
                tail = tail -> down;
            }

            cursor = init_skip_list[0];
            tail = init_skip_list[1];
            while(cursor -> down -> next == tail -> down){ // If 2+ list remains containing only two special keys,
                Node* down_head = cursor -> down; // Need to delete it until 1 list remain.
                Node* down_tail = tail -> down;
                delete init_skip_list[0];
                delete init_skip_list[1];
                init_skip_list[0] = down_head;
                init_skip_list[1] = down_tail;
            }
        }


        cursor = init_skip_list[0];
        tail = init_skip_list[1];
        std::cout << "After removal and remove special case first" << std::endl;
        while(cursor -> down != nullptr){
            std::cout << "In list" << std::endl;
            Node* tmp = cursor;
            while(cursor != tail){
                std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
                cursor = cursor -> next;
            }
            std::cout << cursor -> student_id << ": " << cursor -> score << std::endl;
            std::cout << "End list" << std::endl << std::endl;
            cursor = tmp;
            cursor = cursor -> down; // Fetch to bottom.
            tail = tail -> down;
        }



        std::cout << "Returning" << std::endl;
        return;
    }

    ~StudentOrderedMap()
    {
        /* implement this fucntion*/
        Node* head = init_skip_list[0];
        Node* tail = init_skip_list[1];
        Node* down_head = head -> down;
        Node* down_tail = tail -> down;
        while(down_head != nullptr){
            Node* tmp_head = down_head -> down;
            Node* tmp_tail = down_tail -> down;

            while(down_head != down_tail){
                Node* tmp = down_head -> next;
                delete down_head;
                down_head = tmp;
            }
            delete down_tail;

            down_head = tmp_head;
            down_tail = tmp_tail;
        }
    }

    /* add whatever you want*/
    private:
    Node* init_skip_list[2];
    int skip_list_qty;
};

#endif