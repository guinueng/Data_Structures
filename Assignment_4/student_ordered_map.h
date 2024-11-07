#ifndef STUDENT_ORDERED_MAP_H
#define STUDENT_ORDERED_MAP_H

class StudentOrderedMap { // do not change this line
public:
    struct Node { // do not change this line
        int student_id; // do not change this line
        int score; // do not change this line

        /* add whatever you want */
    };

    StudentOrderedMap() 
    {
        /* implement this fucntion*/
    }

    
    void add_student(int student_id, int score)  // do not change this line
    {
        /* implement this fucntion*/
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
};

#endif