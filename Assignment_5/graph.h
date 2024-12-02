#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

// Do not change the class name
class Graph {
public:

    // Do not change the declaration of the function below
    Graph();

    // Do not change the declaration of the function below
    ~Graph();

    // Do not change the declaration of the function below
    void insert_vertex(const std::string& place);

    // Do not change the declaration of the function below
    void insert_edge(const std::string& v, const std::string& w, int distance);

    // Do not change the declaration of the function below
    void erase_vertex(const std::string& place);

    // Do not change the declaration of the function below
    void erase_edge(const std::string& v, const std::string& w);

    // Do not change the declaration of the function below
    bool is_adjacent_to(const std::string& v, const std::string& w) const;

    // Do not change the declaration of the function below
    // This prints the structure of the graph. The format is as follows: for each line, print each edge in the format "node1 node2 weight of the edge," with each element separated by a single space.
    void print_graph() const;

    /* add whatever you want*/

    private:
    struct Vertex_Container; // Contains vertex name and link to Vertex and Adjacent_List structure.

    struct Vertex{ // Singly linked list of vertex.
        Vertex_Container* content;
        Vertex* next;
    };

    struct Edge_Container; // Contains Edge name and link to Edge, Adjacent_List and Vertex_Container to connected component.

    struct Edge{ // Singly linked list of edge.
        Edge_Container* content;
        Edge* next;
    };

    struct Adjacent_List{ // Singly linked list of adjacency list.
        Edge_Container* con_edge;
        Adjacent_List* next;
    };

    struct Vertex_Container{ // Containing vertex value and information.
        std::string name;
        Vertex* vertex;
        Adjacent_List* adj_list;
    };

    struct Edge_Container{ // Containing edge value and informaiton.
        //std::string name;
        int weight;
        Edge* edge;
        Adjacent_List* l_adj;
        Adjacent_List* r_adj;
        Vertex_Container* l_vertex;
        Vertex_Container* r_vertex;
    };

    Vertex* v_list; // Init point of vertex's singly linked list entry.
    Edge* e_list; // Init point of edge's singly linked list entry.
};

/* add whatever you want*/

#endif // GRAPH_H