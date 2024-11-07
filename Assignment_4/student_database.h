#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H

class StudentDatabase {// do not change this line

    void add_student(int student_id, int score) // do not change this line
    {
        /* implement this fucntion*/
    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this fucntion*/
    }

    int get_score(int student_id) const // do not change this line
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

    // this returns a 2D integer array = an array of k [student_id, score] pairs.
    int** get_top_k_students(int k) // do not change this line
    {
        /* implement this fucntion*/
    }

    int get_rank(int score) const // do not change this line
    {
        /* implement this fucntion*/
    }

    /* add whatever you want*/
};

#endif