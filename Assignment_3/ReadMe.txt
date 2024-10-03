ReadMe.txt for GwanUk Lee(20211216)

1. doubly_linked_list
    During destruction, we have to remove dynamically allocated part which is header and trailer.
    And if we have to update doubly_linked_list(e.g. add_front/back, remove_front/back),
    we have to update not only header and trailer but also originally next/prev part's prev/next pointer.
    If not, we can't assure that if header -> next = trailer condition is initial condition which element is 0 state.

2. stack
    During destruction, we have to remove dynamically allocated part which is array of string.
    Due to index of capacity and top, we can easily add element into dynamically allocated given capacity size.

3. deque
    Use doubly_linked_list to make deque.

4. reverse func of deque
    First, store deque's value into temporary stack and delete it.
    Then, pop temporary stack's value and store it into deque.
    Due to LIFO property of deque and FIFO property of stack, we can reverse deque.

5. Makefile
    On my linux environment, CLANG is not installed.
    And due to environmental differences, I deleted CXX part to be ensure that CXX part will be filled with default values in each system.