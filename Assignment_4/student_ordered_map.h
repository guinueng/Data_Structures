#ifndef STUDENT_ORDERED_MAP_H
#define STUDENT_ORDERED_MAP_H

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
        init_skip_list[0] = new Node{.up = nullptr, .down = nullptr, .prev = nullptr};
        init_skip_list[1] = new Node{.up = nullptr, .down = nullptr, .next = nullptr};
        init_skip_list[0] -> next = init_skip_list[1];
        init_skip_list[1] -> prev = init_skip_list[0];
        skip_list_qty = 1;
    }

    
    void add_student(int student_id, int score)  // do not change this line
    {
        /* implement this fucntion*/
        int coin = 0; // Define coin toss qty as 0.
        while(std::rand() % 2 == 0){ // If value is 0, it denotes head. Else, it denotes tail.
            coin++; // If random value gives head, increase coin toss qty.
        }

        int tot_h = coin + 1;
        for(int i = skip_list_qty; i < tot_h; i++){ // skip_list_qty <= tot_h case.
            Node* head = init_skip_list[0];
            Node* tail = init_skip_list[1];
            if(head -> down != nullptr){
                if(head -> next != tail){
                    Node* cur_elem = head;
                    while(cur_elem -> next -> score < score){
                        cur_elem = cur_elem -> next;
                    }
                    Node* next_elem = cur_elem -> next;
                    Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = cur_elem, .next = next_elem};
                    cur_elem -> next = new_elem;
                    next_elem -> prev = new_elem;
                    while(cur_elem != nullptr){
                        cur_elem = cur_elem -> down;
                        next_elem = next_elem -> down;
                        Node* new_elem = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = cur_elem, .next = next_elem};
                        i++;
                    }

                }
                else{
                    head -> next = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = head, .next = tail};
                    tail -> prev = head -> next;
                }
            }
            else{
                head -> down = new Node{.up = head, .down = nullptr, .prev = nullptr};
                tail -> down = new Node{.up = tail, .down = nullptr, .next = nullptr};
                Node* origin_elem = head -> next; // Pointing current list(exist list) element.
                head = head -> down; // Pointing head/tail of list has changed to new assigned one.
                tail = tail -> down;
                if(origin_elem == tail){ // If above list has only two special key.
                    head -> next = new Node{.student_id = student_id, .score = score, .prev = head, .next = tail};
                    tail -> prev = head -> next;
                }
                else{
                    bool inserted = false;
                    Node* cur_elem = head; // Pointing current list(new assigned list) element.
                    while(origin_elem != tail){
                        if(!inserted && origin_elem -> score > score){
                            cur_elem -> next = new Node{.student_id = student_id, .score = score, .up = nullptr, .down = nullptr, .prev = cur_elem, .next = nullptr};
                            cur_elem = cur_elem -> next;
                            inserted = true;
                        }
                        else{
                            cur_elem -> next = new Node{.student_id = origin_elem -> student_id, .score = origin_elem -> score,
                                .up = origin_elem, .down = nullptr, .prev = cur_elem, .next = nullptr};
                            cur_elem = cur_elem -> next;
                            origin_elem = origin_elem -> next;
                        }
                    }
                    cur_elem -> next = tail;
                    tail -> prev = cur_elem;
                }
            }
        }

    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this fucntion*/
    }

    int get_student(int score) const // do not change this line
    {
        /* implement this fucntion*/
    }

    void remove_student(int student_id) // do not change this line
    {
        /* implement this fucntion*/
    }

    ~StudentOrderedMap()
    {
        /* implement this fucntion*/
    }

    /* add whatever you want*/
    private:
    Node* init_skip_list[2];
    static int skip_list_qty;
};

#endif