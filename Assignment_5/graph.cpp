/* add whatever you want*/
#include "graph.h"

Graph::Graph(){ // Initialize init point as nullptr to ensure unexpected result.
    Graph::v_list = {.content = nullptr, .left = nullptr, .right = nullptr};
    Graph::e_list = {.content = nullptr, .next = nullptr};
}

Graph::~Graph(){

}

void Graph::insert_vertex(const std::string& place){
    Graph::Vertex* tmp_ptr = &(Graph::v_list);
    Graph::Vertex* l_tmp = tmp_ptr -> left;
    if(l_tmp == nullptr){
        
    }
    Graph::Vertex* r_tmp = tmp_ptr -> right;
    bool dir = false; // Check current direction of downwards. Choose 0 as left dir and 1 as right dir.
    while(tmp_ptr -> content != nullptr){
        
        
    }
    tmp_ptr -> content = new Graph::Vertex_Container;
    tmp_ptr -> content -> name = place;
    tmp_ptr -> content -> vertex = tmp_ptr;
    tmp_ptr -> content -> list = nullptr;
}

void Graph::insert_edge(const std::string& v, const std::string& w, int distance){

}

void Graph::erase_vertex(const std::string& place){

}

void Graph::erase_edge(const std::string& v, const std::string& w){

}

bool Graph::is_adjacent_to(const std::string& v, const std::string& w) const{

}

// This prints the structure of the graph.
// The format is as follows: for each line, print each edge in the format "node1 node2 weight of the edge," with each element separated by a single space.
void Graph::print_graph() const{

}