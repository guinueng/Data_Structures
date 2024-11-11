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
        init_skip_list[0] = new Node{.student_id = -1, .score = -1, .up = nullptr, .down = nullptr, .prev = nullptr};
        init_skip_list[1] = new Node{.student_id = -1, .score = 101, .up = nullptr, .down = nullptr, .next = nullptr}; // special value for -1 to 101 is due to score is bounded to [0, 100].
        init_skip_list[0] -> next = init_skip_list[1];
        init_skip_list[1] -> prev = init_skip_list[0]; // Conect two special key.
        skip_list_qty = 0;
    }

    
    void add_student(int student_id, int score)  // do not change this line
    {
        /* implement this function*/
        int coin = 0; // Define coin toss qty as 0.
        while(std::rand() % 2 != 0){ // If value is 0, it denotes head. Else, it denotes tail.
            coin++; // If random value gives head, increase coin toss qty.
        }

        int height = (skip_list_qty <= coin)? (coin + 1) : skip_list_qty; // Calculate new height by using fact if(h <= coin),then h = coin + 1;
        bool inserted = false;

        Node* head = init_skip_list[0];
        Node* tail = init_skip_list[1];
        Node* before_elem;
        for(int i = 1; i <= height; i++){
            if(head -> down != nullptr){ // Not creating new skip list case.
                head = head -> down; // Set search list as below list.
                tail = tail -> down;
                if(i >= (height - coin)){ // If need to add existing list case, which is target skip list.
                    if(head -> next != tail){ // If there is inside value,
                        Node* cur_elem = head;
                        while(cur_elem -> next -> score < score){ // Search element which is bigger than insertion score value.
                            cur_elem = cur_elem -> next;
                        }

                        Node* next_elem = cur_elem -> next; // And put insertion value before it's position.
                        Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = cur_elem, .next = next_elem};
                        if(inserted){ // If value is already inserted, we need to connect between already and newly inserted one.
                            new_elem -> up = before_elem;
                            before_elem -> down = new_elem;
                        }
                        else{ // Else, it would be starting element.
                            inserted = true;
                        }

                        next_elem -> prev = new_elem; // Update next element's prev value and before element's next value to newly inserted one.
                        cur_elem -> next = new_elem;
                        before_elem = new_elem;
                    }
                    else{ // head -> next == tail case. Only special key remaining case. Then, put middle of it.
                        Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = head, .next = tail};
                        if(inserted){ // If it is inserted above, connect both of them.
                            new_elem -> up = before_elem;
                            before_elem -> down = new_elem;
                        }
                        else{ // If not, it will be starting element.
                            inserted = true;
                        }

                        before_elem = new_elem; // Update before element which will information of next element's above.
                        head -> next = new_elem; // Connect new element and head/tail.
                        tail -> prev = new_elem;
                    }
                }
                else{
                    // Nothing to do.
                    // Because we do not insert value due to it is not inserting list.
                }
            }
            else{ // New skip list is created case.
                head -> down = new Node{.student_id = -1, .score = -1, .up = head, .down = nullptr, .prev = nullptr}; // Create new below list's head/tail.
                tail -> down = new Node{.student_id = -1, .score = 101,.up = tail, .down = nullptr, .next = nullptr};
                Node* origin_elem = head -> next; // Pointing current list(exist list) element.
                head = head -> down; // Pointing head/tail of list has changed to new assigned one.
                tail = tail -> down;
                head -> next = tail; // Connect head and tail.
                tail -> prev = head;
                
                if(origin_elem == tail -> up){ // If above list has only two special key.
                    if(i >= (height - coin)){ // And if met writing list position,
                        Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = head, .next = tail};
                        head -> next = new_elem; // Put new elem and connect tail and head.
                        tail -> prev = new_elem;
                        if(inserted){ // If already inserted, connect both of them.
                            new_elem -> up = before_elem;
                            before_elem -> down = new_elem;
                        }
                        else{ // Else, it will be uppermost element.
                            inserted = true;
                        }
                        before_elem = new_elem; // Update upper element information.
                    }
                }
                else{ // Above list is not empty.
                    Node* cur_elem = head; // Pointing current list(new assigned list) element.
                    while(origin_elem != tail -> up){ // If above element cursor is not reached above list's end position,
                        if(!inserted && i >= (height - coin) && origin_elem -> score >= score){ // When inserting new element due to met of statement which it is target inserting list position,
                            // not inserted, and original element's value is bigger than inserting value.
                            Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = cur_elem, .next = cur_elem -> next};
                            cur_elem -> next -> prev = new_elem; // Then assign new value, and connect current position and current position's next position's element.
                            cur_elem -> next = new_elem;
                            cur_elem = cur_elem -> next;
                            inserted = true; // This should only happen when value is newly inserted which is uppermost value is inserted case, thus trigger inserted true.
                            before_elem = new_elem; // Update upper element location.
                        }
                        else{ // It will copy originally located values.
                            Node* new_elem = new Node{.student_id = origin_elem -> student_id, .score = origin_elem -> score,
                                .up = origin_elem, .down = nullptr, .prev = cur_elem, .next = cur_elem -> next}; // Thus, use hard copy.
                            origin_elem -> down = new_elem; // And connect above and below values.
                            cur_elem -> next -> prev = new_elem; // Update current element's next value and current element's next element's prev value.
                            cur_elem -> next = new_elem;
                            cur_elem = cur_elem -> next; // And need to update curent value to newly assigned one to copy next element.

                            if(origin_elem == before_elem){ // If it is same as before value,
                                before_elem = new_elem; // need to update upper element location to newly one.
                            }
                            origin_elem = origin_elem -> next; // Keep copying upper list's value until it fetches last element.
                        }
                    }
                }
            }
        }

        skip_list_qty = height; // Update skip_list_qty;
        return;
    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this function*/
        Node* cursor = init_skip_list[0]; // Get uppermost head and tail.
        Node* tail = init_skip_list[1];
        Node* head = cursor; // Store current head position.

        while(cursor != nullptr){ // Until cursor fetches lowermost skip list.
            while(cursor -> next != tail && cursor -> next -> student_id != student_id){ 
                cursor = cursor -> next; // Keep scan forward to find target student id.
            }
            if(cursor -> next -> student_id == student_id){ // If target found, break loop.
                cursor = cursor -> next;
                break;
            }

            head = head -> down; // Persue dropdown process
            cursor = head;
            tail = tail -> down;
        }

        if(cursor != nullptr){ // If target found, remove target score's elem and add target w/ new score.
            remove_student(student_id);
            add_student(student_id, new_score);
        }
        else{
            throw std::runtime_error("Student ID not found"); // Else, throw error.
            return;
        }
    }

    int get_student(int score) const // do not change this line
    {
        /* implement this function*/
        Node* head = init_skip_list[0]; // Get initial head an tail.
        Node* tail = init_skip_list[1];
        while(head != nullptr){ // Until fetching tail,
            Node* tmp = head;
            while(tmp -> next != tail && tmp -> next -> score < score){ // Scan forward.
                tmp = tmp -> next;
            }
            if(tmp -> next != tail && tmp -> next -> score == score){ // If found target value, return target's student id.
                return tmp -> next -> student_id;
            }

            head = head -> down; // Dropdown precess.
            tail = tail -> down;
        }
        throw std::runtime_error("Score not found"); // Throw if there is not exist value.
    }

    void remove_student(int student_id) // do not change this line
    {
        /* implement this function*/
        Node* cursor = init_skip_list[0]; // Get uppermost head and tail.
        Node* tail = init_skip_list[1];
        while(cursor -> down != nullptr){
            cursor = cursor -> down; // Fetch to bottom.
            tail = tail -> down;
        }

        while(cursor != tail && cursor -> student_id != student_id){
            cursor = cursor -> next; // Find target element is exist on bottom.
        }

        if(cursor == tail){ // If target not exist in bottom, no exist in entire skip list.
            throw std::runtime_error("Student ID not found"); // Thus, throw error.
        }
        else{ // If exist, delete target entirely.
            while(cursor != nullptr){
                Node* tmp = cursor -> up; // Temporarily store above pointer.
                cursor -> prev -> next = cursor -> next; // Connect deletion target's prev/next one.
                cursor -> next -> prev = cursor -> prev;
                delete cursor; // Delete target.
                cursor = tmp; // Update deletion target as above one.
                
            }

            cursor = init_skip_list[0]; // Get uppermost head and tail.
            tail = init_skip_list[1];            
            while(cursor -> down -> next == tail -> down){ // If 2+ list remains containing only two special keys,
                Node* down_head = cursor -> down; // Need to delete it until 1 list remain.
                Node* down_tail = tail -> down;
                delete init_skip_list[0];
                delete init_skip_list[1];
                init_skip_list[0] = down_head;
                init_skip_list[1] = down_tail;
                cursor = down_head;
                tail = down_tail;
                skip_list_qty--;
            }
        }

        return;
    }

    ~StudentOrderedMap()
    {
        /* implement this function*/
        Node* head = init_skip_list[0]; // Need to remove all the element in skipped list.
        Node* tail = init_skip_list[1]; // Thus, check 
        while(head != nullptr){
            Node* tmp_head = head -> down;
            Node* tmp_tail = tail -> down; // Get second uppermost head and tail.

            while(head != tail){ // Remove all the element in target skipped list.
                Node* tmp = head -> next;
                delete head;
                head = tmp;
            }
            delete tail;

            head = tmp_head; // Keep deleting until reached bottom nullptr value.
            tail = tmp_tail;
        }
    }

    /* add whatever you want*/
    private:
    Node* init_skip_list[2]; // List containing two initial list head and tail.
    int skip_list_qty; // Store skip_list quantity.

    public:
    int return_prev_score(int score, int dup) const{
        Node* head = init_skip_list[0]; // Get initial head an tail.
        Node* tail = init_skip_list[1];

        while(tail -> down != nullptr){
            head = head -> down;
            tail = tail -> down;
        }

        while(tail != head){

            if(tail -> score == score){
                for(int i = 0; i < dup; i++){
                    tail = tail -> prev;
                }
                std::cout << "Return target : " << tail -> student_id << ": " << tail -> score << std::endl;
                return tail -> score;
            }

            tail = tail -> prev;
        }


        /*
        if(score == 101){
            std::cout << "Score 101" << std::endl;
            if(tail -> prev != head){
                std::cout << "Found target" << std::endl;
                return tail -> prev -> score;
            }
        }
        else{
            while(tail != nullptr){ // Until fetching tail,
                std::cout << "Scan backward. w/ val score: " << score << "and dup: " << dup << std::endl;
                Node* tmp = tail;
                while(tmp -> prev != head && tmp -> prev -> score != score){ // Scan backward.
                    std::cout << "Keep Backtracking until smaller one found." << std::endl;
                    tmp = tmp -> prev;
                }
                std::cout << "cur score: " << tmp -> score << std::endl;
                if(tmp -> prev != head && tmp -> prev -> score == score){ // If found target value, return target's student id.
                    for(int i = 0; i < dup; i++){
                        std::cout << "Keep move backward based on dup #." << std::endl;
                        tmp = tmp -> prev;
                    }
                    std::cout << "Return value: " << tmp -> prev -> score << std::endl;
                    return tmp -> prev -> score;
                    std::cout << "Suspicious4" << std::endl;
                }

                head = head -> down; // Dropdown precess.
                tail = tail -> down;
            }
        }
        */
        std::cout << "Throw on return_prev_score" << std::endl;
        throw std::runtime_error("Score not found"); // Throw if there is not exist value.
    }
};

#endif