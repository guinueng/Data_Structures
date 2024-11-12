#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H
#include "student_map.h"
#include "student_ordered_map.h"

class StudentDatabase {// do not change this line
    public: // Can we add this?
    void add_student(int student_id, int score) // do not change this line
    {
        /* implement this function*/
        student_map.add_student(student_id, score); // Add new student in student map.
        student_ordered_map.add_student(student_id, score); // Add new student in student ordered map.
    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this function*/
        student_map.update_score(student_id, new_score); // Update score in student map.
        student_ordered_map.update_score(student_id, new_score); // Update score in student ordered map.
    }

    int get_score(int student_id) const // do not change this line
    {
        /* implement this function*/
        return student_map.get_score(student_id); // Get score of given student id in student map.
    }

    int get_student(int score) const // do not change this line
    {
        /* implement this function*/
        return student_ordered_map.get_student(score); // Get student id of score by using student ordered map.
    }

    void remove_student(int student_id) // do not change this line
    {
        /* implement this function*/
        student_map.remove_student(student_id); // Remove student in student map.
        student_ordered_map.remove_student(student_id); // Remove student in student ordered map.
    }

    // this returns a 2D integer array = an array of k [student_id, score] pairs.
    int** get_top_k_students(int k) // do not change this line
    {
        /* implement this function*/
        int score = 101, input_elem = 0, dup = 1; // Set init score 101 as we considered it as plus infinity value.
        // 
        int** array = new int* [k]; // Assign 2D array to store value.
        for(int i = 0; i < k; i++){
            array[i] = new int [2]; // Assign pair and score it into 2D array.
            array[i][0] = -1; // And initialize value w/ -1 which regarded as no value.
            array[i][1] = -1;
        }

        for(int i = 0; i < k; i++){
            try{
                int new_score = student_ordered_map.return_prev_score(score, dup); // Find prev score of current score.
                if(new_score == score){ // If returned value is same, inc dup val.
                    dup++;
                }
                else{ // If not, refresh dup to 1 and update score.
                    dup = 1;
                    score = new_score;
                }
                int student_id = student_ordered_map.get_student_dup(score, dup); // Get student id for assigned value, and need to consider it is dup or not.
                array[i][0] = student_id; // Assign student_id value to desire array[0].
                array[i][1] = score; // Assign student's score into desire array[1].
                input_elem++; // Inc input elem qty.
            }
            catch(const std::exception& e){
                break; // If nothing value found, get exception and do not throw it into main.cc(or .cpp) file.
            }
        }

        int i = 0; // Need to mod below func and get biased sorting pos.
        for(int i = 0; i < input_elem; i++){ // Use inefficient sorting method.
            for(int j = i + 1; j < input_elem; j++){
                if(array[i][1] == array[j][1]){
                    if(array[i][0] > array[j][0]){
                        int tmp = array[i][0];
                        array[i][0] = array[j][0];
                        array[j][0] = tmp;
                    }
                }
            }
        }

        return array;
    }

    int get_rank(int score) const // do not change this line
    {
        int find_value = 101, rank = 0, dup = 1; // Set init value as left due to we need to search first highest elem first. 
        while(find_value != score){ // We need to find all elem in student_ordered_map.
            try{
                int new_find_value = student_ordered_map.return_prev_score(find_value, dup); //  Init new value as value returned in find_prev_score.
                if(new_find_value == find_value){ // If same value found, inc dup val.
                    dup++;
                }
                else{ // If fresh value found, reset dup qty = 1, update find_value to ensure we need to find new prev val, and inc rank.
                    dup = 1;
                    find_value = new_find_value;
                    rank++;
                }
            }
            catch(const std::exception& e){ // If prev_score finding function reached to head of list, it will give exception, and to ensure that, get exception and throw new exception.
                throw std::runtime_error("Score not found"); // Throw if there is not exist score.
            }
        }
        return rank; // If found, return rank that we calculated.
    }

    /* add whatever you want*/
    private:
    StudentMap student_map; // Need to contain student_map and student_ordered_map.
    StudentOrderedMap student_ordered_map;
};

#endif