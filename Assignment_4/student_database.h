#ifndef STUDENT_DATABASE_H
#define STUDENT_DATABASE_H
#include "student_map.h"
#include "student_ordered_map.h"

class StudentDatabase {// do not change this line
    public: // Can we add this?
    void add_student(int student_id, int score) // do not change this line
    {
        /* implement this fucntion*/
        student_map.add_student(student_id, score);
        student_ordered_map.add_student(student_id, score);
    }

    void update_score(int student_id, int new_score) // do not change this line
    {
        /* implement this fucntion*/
        student_map.update_score(student_id, new_score);
        student_ordered_map.update_score(student_id, new_score);
    }

    int get_score(int student_id) const // do not change this line
    {
        /* implement this fucntion*/
        return student_map.get_score(student_id);
    }

    int get_student(int score) const // do not change this line
    {
        /* implement this fucntion*/
        return student_ordered_map.get_student(score);
    }

    void remove_student(int student_id) // do not change this line
    {
        /* implement this fucntion*/
        student_map.remove_student(student_id);
        student_ordered_map.remove_student(student_id);
    }

    // this returns a 2D integer array = an array of k [student_id, score] pairs.
    int** get_top_k_students(int k) // do not change this line
    {
        /* implement this fucntion*/

        //std::cout << "GET TOP K" << std::endl;
        int score = 101, input_elem = 0, dup = 1;
        int** array = new int* [k];
        for(int i = 0; i < k; i++){
            array[i] = new int [2];
            array[i][0] = -1;
            array[i][1] = -1;
        }

        for(int i = 0; i < k; i++){
            //std::cout << array[i][0] << ": "<< array[i][1] << std::endl;
        }

        for(int i = 0; i < k; i++){
            try{
                //std::cout << i << "th Try find prev score: " << score << std::endl;
                int new_score = student_ordered_map.return_prev_score(score, dup);
                if(new_score == score){
                    dup++;
                    //std::cout << "Found dup" << dup << std::endl;
                    
                }
                else{
                    //std::cout << "Not dup" << std::endl;
                    dup = 1;
                    score = new_score;
                }
                //std::cout << "Score: " << score << std::endl;
                int student_id = student_ordered_map.get_student_dup(score, dup); // Get student id for assigned value.
                //std::cout << student_id << std::endl;
                array[i][0] = student_id;
                array[i][1] = score;
                input_elem++;
            }
            catch(const std::exception& e){
                //std::cout << "Throw" << std::endl;
                break;
            }
            //std::cout << "Suspicious End" << std::endl;


            //std::cout << "Cur array info" << std::endl;
            for(int i = 0; i < k; i++){
                //std::cout << array[i][0] << ": "<< array[i][1] << std::endl;
            }
        }

        //std::cout << "Cur array info" << std::endl;
            for(int i = 0; i < k; i++){
                //std::cout << array[i][0] << ": "<< array[i][1] << std::endl;
            }

        //std::cout << "END array input" << std::endl;

        int i = 0; // Need to mod below func and get biased sorting pos.
        for(int i = 0; i < input_elem; i++){
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
        int find_value = 101, rank = 0, dup = 1;
        while(find_value != score){
            try{
                int new_find_value = student_ordered_map.return_prev_score(find_value, dup);
                if(new_find_value == find_value){
                    dup++;
                }
                else{
                    dup = 1;
                    find_value = new_find_value;
                    rank++;
                }
            }
            catch(const std::exception& e){
                throw std::runtime_error("Score not found"); // Throw if there is not exist score.
            }
        }
        return rank;
    }

    /* add whatever you want*/
    private:
    StudentMap student_map;
    StudentOrderedMap student_ordered_map;
};

#endif