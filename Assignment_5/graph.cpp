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
    std::string target_name = target_v_ptr -> content -> name;
    while(tmp_adj != nullptr){ // For ensure mem address safety, erase target's connected adjacency list and update connected part of vertex container as nullptr.
        // if(tmp_adj -> con_edge -> l_adj == tmp_adj){ // Check left edge has same value.
        //     tmp_adj -> con_edge -> l_adj == nullptr; // If does, update as nullptr.
        // }
        // else if(tmp_adj -> con_edge -> r_adj == tmp_adj){ // Check right edge has same value.
        //     tmp_adj -> con_edge -> r_adj == nullptr; // If does, update as nullptr.
        // } Need to delete connected edge.
        tmp_adj = tmp_adj -> next;
        Graph::erase_edge(tmp_adj -> con_edge -> l_vertex -> name, tmp_adj -> con_edge -> r_vertex -> name); // Erase connected edge on adjacent list.
        // Adjacent list is automatically deleted on erase_edge function.

        // Graph::Adjacent_List* erase_target = tmp_adj; // Assign temporary pointer to store current adjacent edge.
        // tmp_adj = tmp_adj -> next; // Update to next adjacent edge.
        // delete erase_target; // Delete current pointer.
    }

    delete target_v_ptr -> content; // Delete current vertex's container element.
    delete target_v_ptr;

    if(before_v_ptr == nullptr){ // Case 1. If deleting first vertex element.
        Graph::v_list = next_v_ptr; // Update starting vertex list to current one.
    }
    else{ // Case 2. If deleting location 2+ vertex element.
        before_v_ptr -> next = next_v_ptr; // Connect prev element and next element.
    }

}

void Graph::erase_edge(const std::string& v, const std::string& w){
    Graph::Edge* e_tmp = e_list;
    Graph::Edge* prev_e_tmp = nullptr;
    Graph::Edge* target_e_tmp = nullptr;

    while(e_tmp != nullptr){
        if(e_tmp->content->l_vertex->name == v && e_tmp->content->r_vertex->name == w){ // Finding two target vertices connection is exist or not.
            target_e_tmp = e_tmp;
            break;
        }
        else if(e_tmp->content->l_vertex->name == w && e_tmp->content->r_vertex->name == v){
            target_e_tmp = e_tmp;
            break;
        }

        prev_e_tmp = e_tmp; // Assign prev position to pointer.
        e_tmp = e_tmp -> next; // Traverse until reaching end of list.
    }

    if(e_tmp == nullptr){ // If target edge is not found.
        // Raise Exception.
    }

    if(prev_e_tmp == nullptr){ // Case 1. If target edge is first element of edge list.
        e_list = target_e_tmp; // Then, update starting point of edge list into 2nd one.
    }
    else{ // Case 2. Target edge is exist in 2+ position of edge list.
        prev_e_tmp -> next = target_e_tmp -> next; // Connect prev and next elem.
    }

    Graph::Edge_Container* target_container = target_e_tmp -> content;
    // Need to delete adjacent edge.
    Graph::Adjacent_List* l_prev_adj = target_container -> l_vertex -> adj_list;
    Graph::Adjacent_List* r_prev_adj = target_container -> r_vertex -> adj_list;

    while(l_prev_adj -> next != nullptr && l_prev_adj -> next != target_container -> l_adj){ // Finding prev adj list.
        l_prev_adj = l_prev_adj -> next;
    }

    if(l_prev_adj == target_container -> l_vertex -> adj_list){ // Case 1. Removing first element of adjacent list.
        // if(l_prev_adj -> next == nullptr){ // Case 1-1. Existing only one element in adjacent list.
        //     target_container -> l_vertex -> adj_list = nullptr;
        //     delete target_container -> l_adj;
        // }
        // else{ // Case 1-2. 2+ element exist in adjacent list.
        //     target_container -> l_vertex -> adj_list = target_container -> l_adj -> next;
        //     delete target_container -> l_adj;
        // }
        // Case 1-1. Existing only one element in adjacent list. In this case, current adjacent element has nullptr on next element.
        // Case 1-2. 2+ element exist in adjacent list. In this case, current adjacent element has pointer to next element.
        // Thus in which case, we need to update entry of adjacent list located on Vertex_Container element.
        // It works same as above commented code.
        target_container -> l_vertex -> adj_list = target_container -> l_adj -> next; // Update adjacent list entry.
        delete target_container -> l_adj; // Delete current adjacent list.
    }
    else{ // Case 2. Deleting middle element in adjacent list. We just connect prev element and next element of current target on adjacent list.
        l_prev_adj -> next = target_container -> l_adj -> next; // Connect prev adjacent element's next to next adjacent element to target element.
        delete target_container -> l_adj; // Delete target element.
    }

    while(r_prev_adj -> next != nullptr && r_prev_adj -> next != target_container -> r_adj){ // Finding prev adj list. Similar to above case.
        r_prev_adj = r_prev_adj -> next;
    }

    if(r_prev_adj == target_container -> r_vertex -> adj_list){ // Case 1. Removing first element of adjacent list.
        target_container -> r_vertex -> adj_list = target_container -> r_adj -> next; // Update adjacent list entry.
        delete target_container -> r_adj; // Delete current adjacent list.
    }
    else{ // Case 2. Deleting middle element in adjacent list. We just connect prev element and next element of current target on adjacent list.
        r_prev_adj -> next = target_container -> r_adj -> next; // Connect prev adjacent element's next to next adjacent element to target element.
        delete target_container -> r_adj; // Delete target element.
    }

    // Do not need to delete vertex.

    delete target_container; // Delete edge container.
    delete target_e_tmp; // Delete edge.
}

bool Graph::is_adjacent_to(const std::string& v, const std::string& w) const{

}

// This prints the structure of the graph.
// The format is as follows: for each line, print each edge in the format "node1 node2 weight of the edge," with each element separated by a single space.
void Graph::print_graph() const{

}