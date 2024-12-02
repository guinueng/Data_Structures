ReadMe.txt for GwanUk Lee(20211216)

1. Graph
    Additionally implemented struct element would be Vertex, Vertex_Container, Edge, Edge_Container and Adjacent_List.
    Vertex denotes vertex list, and it is implemented by utilizing singly linked list(sll) which contains Vertex_Container and Vertex pointer.
    Formal one(pointer to Vertex_Container) is used to point vertex's information element, and later one(pointer to Vertex) is used to connect next element of Vertex which will work as sll.
    In Vertex_Container, it contains information of vertex.
    So, it contains name of vertex, pointer to Vertex which points target position of vertex sll, and pointer to Adjacent_List which point current vertex's connection list.
    In Edge, it is also implementation by utilizing sll.
    Similar to Vertex, Edge contains pointer to Edge_Container which points edge information element, and pointer to Edge which makes Edge work as sll.
    In Edge_Container, it contains information of edge which is similar to Vertex_Container.
    So, it contains name of edge, weight of edge, two pointer to Vertex_Container which points each connected vertices information, and two pointer to Adjacent_List which points each vertices connected on edge's connection list.
    In Adjacent_List, which is briefly mentioned above, which works as list of pointer to Edge_Container which connected to target vertex.
    It is also implemented based on sll.
    Also, Vertex pointer and Edge pointer is used to starting point to each sll.
    And v_qty and e_qty is used to store total vertex and edge quantity.
    Additional information for each function or element in Graph class, please refer comment at header file and corresponding cpp file.
    Sorry for inconvenience, but due to quite long code and complex behavior, please give me a favor.

2. Heap
    Additionally implemented struct element would be heap_elem.
    It is implemented to store information and utilized by making that element into array to make vector(array) based heap.
    Also, heap_arr is used to starting point of array, and qty is used to denote current element on array, and max is used to denote maximal element array can store.
    Additional information for each function or element in Heap class, please refer comment at header file and corresponding cpp file.
    Sorry for inconvenience, but due to quite long code and complex behavior, please give me a favor.

3. Dijkstra
    Additionally implemented element is t_graph, which stores pointer to Graph which will utilize to calculate shortest path.
    Additional information for each function or element in Dijkstra class, please refer comment at header file and corresponding cpp file.
    Sorry for inconvenience, but due to quite long code and complex behavior, please give me a favor.

4. Makefile
    On my linux environment, CLANG is not installed.
    And due to environmental differences, I deleted CXX part to be ensure that CXX part will be filled with default values in each system.

5. Reference
    https://learn.microsoft.com/en-us/cpp/cpp/integer-limits?view=msvc-170 // To find maximum value of type int.
    https://learn.microsoft.com/ko-kr/cpp/cpp/enumerations-cpp?view=msvc-170 // Forgot to utilize enum class learned in Advanced Programming Lecture.