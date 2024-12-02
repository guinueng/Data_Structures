/* add whatever you want*/
#include "graph.h"

Graph::Graph(){ // Initialize init point as nullptr to ensure unexpected result.
    Graph::v_list = new Graph::Vertex{.content = nullptr, .next = nullptr};
    Graph::e_list = new Graph::Edge{.content = nullptr, .next = nullptr};
}

Graph::~Graph(){

}

void Graph::insert_vertex(const std::string& place){
    Graph::Vertex* v_ptr = Graph::v_list;
    
    while(v_ptr -> content != nullptr){ // Finding position which content has nothing.
        if(v_ptr -> next == nullptr){ // If next pointer of vertex is nullptr, create new vertex element.
            v_ptr -> next = new Graph::Vertex{.content = nullptr, .next = nullptr};
        }
        v_ptr = v_ptr -> next; // Keep traverse Vertex list until finding vertex which content is empty.
    }

    if(v_ptr -> content == nullptr){
        v_ptr -> content = new Graph::Vertex_Container{.name = place, .vertex = v_ptr, .adj_list = nullptr};
    }
}

void Graph::insert_edge(const std::string& v, const std::string& w, int distance){
    Graph::Edge* e_ptr = Graph::e_list;
    Graph::Vertex* v_ptr = Graph::v_list;
    Graph::Vertex_Container* l_vertex_ptr = nullptr;
    Graph::Vertex_Container* r_vertex_ptr = nullptr;

    while(e_ptr -> content != nullptr){ // Finding position which content has nothing.
        if(e_ptr -> next == nullptr){ // If next pointer of vertex is nullptr, create new vertex element.
            e_ptr -> next = new Graph::Edge{.content = nullptr, .next = nullptr};
        }
        e_ptr = e_ptr -> next; // Keep traverse Vertex list until finding edge which content is empty.
    }

    while(v_ptr != nullptr){ // Finding location of target vertices.
        if(v_ptr -> content -> name == v){ // If matching name found, update left or right vertex pointer to target vertex_container's address.
            l_vertex_ptr = v_ptr -> content;
        }

        if(v_ptr -> content -> name == w){
            r_vertex_ptr = v_ptr -> content;
        }

        v_ptr = v_ptr -> next; // Keep traverse until reaching end of vertex list.
    }

    if(l_vertex_ptr == nullptr || r_vertex_ptr == nullptr){ // If target vertices not found, raise exception handling.
        // Exception handle.
    }

    if(e_ptr -> content == nullptr){
        e_ptr -> content = new Graph::Edge_Container{.weight = distance, .l_adj = nullptr, .r_adj = nullptr, .l_vertex = l_vertex_ptr, .r_vertex = r_vertex_ptr};
    } // Create new edge container to store edge element detail.

    Graph::Adjacent_List* l_adj_ptr = l_vertex_ptr -> adj_list;
    Graph::Adjacent_List* r_adj_ptr = r_vertex_ptr -> adj_list;

    while(l_adj_ptr != nullptr){ // Find empty position of each adj list to store current edge to adj list.
        l_adj_ptr = l_adj_ptr -> next;
    }

    while(r_adj_ptr != nullptr){
        r_adj_ptr = r_adj_ptr -> next;
    }

    l_adj_ptr = new Graph::Adjacent_List{.con_edge = e_ptr -> content, .next = nullptr};
    r_adj_ptr = new Graph::Adjacent_List{.con_edge = e_ptr -> content, .next = nullptr}; // Create connection btw each adj list and cur edge container.

    e_ptr -> content -> l_adj = l_adj_ptr;
    e_ptr -> content -> r_adj = r_adj_ptr; // Update connection btw each adj list and cur edge container.
}

void Graph::erase_vertex(const std::string& place){
    Graph::Vertex* v_ptr = Graph::v_list;
    Graph::Vertex* before_v_ptr = nullptr;
    Graph::Vertex* target_v_ptr = nullptr;

    while(v_ptr != nullptr){ // Finding location of target vertices.
        if(v_ptr -> content -> name == place){ // If matching name found, remember before and target element's pointer address.
            target_v_ptr = v_ptr;
            break;
        }
        before_v_ptr = v_ptr; // Always mark before element for implementation preference. It will use at updating connection btw before and after deletion element.
        v_ptr = v_ptr -> next; // Keep traverse until reaching end of vertex list.
    }

    if(target_v_ptr == nullptr){ // If target not found, 
        // Raise Exception.
    }

    Graph::Vertex* next_v_ptr = target_v_ptr -> next; // Check next element of target element.

    Graph::Adjacent_List* tmp_adj = target_v_ptr -> content -> adj_list;
    while(tmp_adj != nullptr){
        if(tmp_adj -> con_edge -> l_adj == tmp_adj){ // For ensure mem address safety, erase 
            tmp_adj -> con_edge -> l_adj == nullptr;
        }
        else if(tmp_adj -> con_edge -> r_adj == tmp_adj){
            tmp_adj -> con_edge -> r_adj == nullptr;
        }


        
    }
    delete target_v_ptr -> content;
    delete target_v_ptr;

    if(before_v_ptr == nullptr){ // If deleting first vertex element.
        Graph::v_list = next_v_ptr;
    }

}

void Graph::erase_edge(const std::string& v, const std::string& w){

}

bool Graph::is_adjacent_to(const std::string& v, const std::string& w) const{

}

// This prints the structure of the graph.
// The format is as follows: for each line, print each edge in the format "node1 node2 weight of the edge," with each element separated by a single space.
void Graph::print_graph() const{

}