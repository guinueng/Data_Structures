/* add whatever you want*/
#include "dijkstra.h"

enum class INT { MAX = 2147483647 };

Dijkstra::Dijkstra(Graph* graph) :t_graph(graph) {}

// This prints each place in the fastest path sequentially, including the source and destination, separated by a single space (" "). If there are multiple shortest paths, you may print any one of them.
void Dijkstra::get_fastest_path(const std::string& source, const std::string& destination){
    int qty = t_graph -> v_qty, distance;
    std::string total_path, result_path;
    Heap heap(qty), result(qty);
    Graph::Vertex* tmp_vertex = t_graph -> v_list;

    while(tmp_vertex != nullptr){
        if(tmp_vertex -> content -> name == source){ // Set distance of source as 0 when name is same as source.
            distance = 0;
        }
        else{ // Otherwise, assign distance as infinite, assuming INT MAX value on here. (Defined above by using enum.)
            distance = int(INT::MAX);
        }

        heap.insert(distance, tmp_vertex -> content -> name); // Insert value and distance into heap.
        result.insert(distance, tmp_vertex -> content -> name); // Insert value and distance into heap.

        tmp_vertex = tmp_vertex -> next; // Keep loop until reached at the end of list of vertex.
    }

    while(!heap.empty()){
        int min_key = heap.heap_arr[1].key; // Bring minimum value.
        std::string min_value = heap.heap_arr[1].value;

        total_path += min_value; // Storing conquered path.
        total_path += " ";

        heap.remove_min(); // Remove minimum value on heap.

        Graph::Adjacent_List* adj_list;

        tmp_vertex = t_graph -> v_list;
        while(tmp_vertex != nullptr){ // Find adjacent list of minimum value of heap.
            if(tmp_vertex -> content -> name == min_value){
                adj_list = tmp_vertex -> content -> adj_list;
                break;
            }

            tmp_vertex = tmp_vertex -> next;
        }

        while(adj_list != nullptr){ // During all element in adjacent list, we evaluate all connected component due to greedy method.
            Graph::Edge_Container* edge = adj_list -> con_edge; // Bring current adjacent element's edge.

            std::string op_vertex; // Find edge's opposite vertex name.
            if(edge -> l_vertex -> name != min_value){
                op_vertex = edge -> l_vertex -> name;
            }
            else if(edge -> r_vertex -> name != min_value){
                op_vertex = edge -> r_vertex -> name;
            }

            if((min_key + edge -> weight) < result.heap_arr[result.find_index(op_vertex)].key){ /// If current evaluation path's distance is shorter than already calculated path one,
                result.replace_key(result.find_index(op_vertex), min_key + edge -> weight); // Update result and heap's key.

                if(heap.find_index(op_vertex) != int(INT::MAX)){ // During calculation, there is the case that current target element is not exist in heap's heap_array.
                    heap.replace_key(heap.find_index(op_vertex), min_key + edge -> weight); // Thus, update heap's heap_array only element exist in heap elem.
                }

                if(op_vertex == destination){ // Also, update result destination.
                    result_path = total_path + destination;
                }
            }
            // result.print_heap();
            adj_list = adj_list -> next; // Keep traverse until evaluating whole of current min_value's vertices connected component.
        }
    }

    std::cout << result_path << std::endl; // Print result path.

    return;
}

// This prints the sum of the distances of the fastest path.
void Dijkstra::get_fastest_distance(const std::string& source, const std::string& destination){
    int qty = t_graph -> v_qty, distance;
    Heap heap(qty), result(qty);
    Graph::Vertex* tmp_vertex = t_graph -> v_list;

    while(tmp_vertex != nullptr){
        if(tmp_vertex -> content -> name == source){ // Set distance of source as 0 when name is same as source.
            distance = 0;
        }
        else{ // Otherwise, assign distance as infinite, assuming INT MAX value on here. (Defined above by using enum.)
            distance = int(INT::MAX);
        }

        heap.insert(distance, tmp_vertex -> content -> name); // Insert value and distance into heap.
        result.insert(distance, tmp_vertex -> content -> name); // Insert value and distance into heap.

        tmp_vertex = tmp_vertex -> next; // Keep loop until reached at the end of list of vertex.
    }

    while(!heap.empty()){
        int min_key = heap.heap_arr[1].key; // Bring minimum value.
        std::string min_value = heap.heap_arr[1].value;

        heap.remove_min(); // Remove minimum value on heap.

        Graph::Adjacent_List* adj_list;

        tmp_vertex = t_graph -> v_list;
        while(tmp_vertex != nullptr){ // Find adjacent list of minimum value of heap.
            if(tmp_vertex -> content -> name == min_value){
                adj_list = tmp_vertex -> content -> adj_list;
                break;
            }

            tmp_vertex = tmp_vertex -> next;
        }

        while(adj_list != nullptr){ // During all element in adjacent list, we evaluate all connected component due to greedy method.
            Graph::Edge_Container* edge = adj_list -> con_edge; // Bring current adjacent element's edge.
            std::string op_vertex;
            if(edge -> l_vertex -> name != min_value){ // Find edge's opposite vertex name.
                op_vertex = edge -> l_vertex -> name;
            }
            else if(edge -> r_vertex -> name != min_value){
                op_vertex = edge -> r_vertex -> name;
            }

            if((min_key + edge -> weight) < result.heap_arr[result.find_index(op_vertex)].key){ // If current evaluation path's distance is shorter than already calculated path one,
                result.replace_key(result.find_index(op_vertex), min_key + edge -> weight); // Update result and heap's key.
                heap.replace_key(heap.find_index(op_vertex), min_key + edge -> weight);
            }

            adj_list = adj_list -> next; // Keep traverse until evaluating whole of current min_value's vertices connected component.
        }
    }

    std::cout << result.heap_arr[result.find_index(destination)].key << std::endl;

    return;
}