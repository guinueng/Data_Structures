/* add whatever you want*/
#include "dijkstra.h"

enum class INT { MAX = 2147483647 };

Dijkstra::Dijkstra(Graph* graph) :t_graph(graph) {}

// This prints each place in the fastest path sequentially, including the source and destination, separated by a single space (" "). If there are multiple shortest paths, you may print any one of them.
void Dijkstra::get_fastest_path(const std::string& source, const std::string& destination){
    int qty = t_graph -> v_qty, distance;
    Heap heap(qty);
    Graph::Vertex* tmp_vertex = t_graph -> v_list;

    while(tmp_vertex != nullptr){
        if(tmp_vertex -> content -> name == source){ //Set distance of source
            distance = 0;
        }
        else{
            distance = int(INT::MAX);
        }

        heap.insert(distance, tmp_vertex -> content -> name);

        tmp_vertex = tmp_vertex -> next;
    }
}

// This prints the sum of the distances of the fastest path.
void Dijkstra::get_fastest_distance(const std::string& source, const std::string& destination){

}