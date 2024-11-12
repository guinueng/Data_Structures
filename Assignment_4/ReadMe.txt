ReadMe.txt for GwanUk Lee(20211216)

1. student_map
    Additionally implemented Node* HASH_TABLE[HASH_SIZE] to store hashed value into array,
    and added Node* next in struct Node to ensure that Node works as singly linked list.
    Specific implementation detail is on student_map.h file's comment.
    (Sorry for unkindness but due to quite long comment, please give me a favor. Thank you.)

2. student_ordered_map
    Additionally implemented Node* init_skip_list[2] to store toppest head and tail into array,
    and added Node* prev, next, up, down in struct Node to ensure that Node works as quad linked list.
    Also, Additionally implemented return_prev_score function to return previous value and get_student_dup
    to get student_id while considering dup qty.
    Specific implementation detail is on student_ordered_map.h file's comment.
    (Sorry for unkindness but due to quite long comment, please give me a favor. Thank you.)

3. student_database
    Additionally intiallized student_map and student_ordered_map to use internally.
    Specific implementation detail is on student_database.h file's comment.
    (Sorry for unkindness behavior but due to quite long comment, please give me a favor. Thank you.)

4. Makefile
    On my linux environment, CLANG is not installed.
    And due to environmental differences, I deleted CXX part to be ensure that CXX part will be filled with default values in each system.

5. Reference
    https://stackoverflow.com/questions/11516657/c-structure-initialization // Forgor to initialize new struct variable.
    https://modoocode.com/230 // Find how to throw runtime_error by using <stdexcept> library.