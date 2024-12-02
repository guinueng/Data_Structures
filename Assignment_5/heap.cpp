/* add whatever you want*/
#include "heap.h"

Heap::Heap(int capacity){
    heap_arr = new heap_elem[capacity + 1]; // Assign new heap array.
    qty = 0; // Initialize tot qty as 0.
    max = capacity; // Check max capacity.
}

Heap::~Heap(){
    delete[] heap_arr; // Delete heap array during destruction.
}

bool Heap::empty() const{
    if(qty == 0){
        return true;
    }
    else{
        return false;
    }
}

void Heap::insert(int key, const std::string& value){
    if(empty()){ // If heap array is empty,
        heap_arr[1].key = key; // assign key and value into first position.
        heap_arr[1].value = value;
        qty++;
    }
    else{ // Else, to ensure complete binary tree property,
        qty++;
        heap_arr[qty].key = key; // assign key and value in the last position.
        heap_arr[qty].value = value;

        int parent_key = qty / 2; // To ensure heap-order property, we need to upheap
        int child_key = qty;
        while(child_key > 0){ // Until reaching to root, check parent and child keeps heap order property which key(child) >= key(parent).
            // std::cout << "parent key: " << parent_key << " child key: " << child_key << std::endl;
            if(heap_arr[parent_key].key > heap_arr[child_key].key){ // If heap-order property violation found,
                // std::cout << "Violate!" << std::endl;
                int tmp_key = heap_arr[parent_key].key; // first temporarily store parent's key and value.
                std::string tmp_value = heap_arr[parent_key].value;
                heap_arr[parent_key].key = heap_arr[child_key].key; // Then, update parent key and value into child's one.
                heap_arr[parent_key].value = heap_arr[child_key].value;
                heap_arr[child_key].key = tmp_key; // Finally, update child's key and value into parent one which is temporarily stored above.
                heap_arr[child_key].value = tmp_value;
            }

            parent_key = parent_key / 2;
            child_key = child_key / 2;
        }
    }

    // std::cout << "qty: " << qty << std::endl;
    // print_heap();
    // std::cout << std::endl;
}

void Heap::remove_min(){
    heap_arr[1].key = heap_arr[qty].key; // assign last position's key and value into root of heap.
    heap_arr[1].value = heap_arr[qty].value;
    heap_arr[qty].key = -1; // To prevent mistake, due to assumption given in description, fill last elem as key = -1, value = " ".
    heap_arr[qty].value = "";
    

    int parent_key = 1; // To ensure heap-order property, we need to upheap
    int child_key;
    if(heap_arr[2].key > heap_arr[3].key){ // To prevent double downheap, choose smaller child.
        child_key = 3;
    }
    else{
        child_key = 2;
    }

    while(child_key < qty){ // Until reaching end of tree,
        // std::cout << "parent key: " << parent_key << " child key: " << child_key << std::endl;
        if(heap_arr[parent_key].key > heap_arr[child_key].key){ // If heap-order property violation found,
            // std::cout << "Violate!" << std::endl;
            int tmp_key = heap_arr[parent_key].key; // first temporarily store parent's key and value.
            std::string tmp_value = heap_arr[parent_key].value;
            heap_arr[parent_key].key = heap_arr[child_key].key; // Then, update parent key and value into child's one.
            heap_arr[parent_key].value = heap_arr[child_key].value;
            heap_arr[child_key].key = tmp_key; // Finally, update child's key and value into parent one which is temporarily stored above.
            heap_arr[child_key].value = tmp_value;
        }

        parent_key = child_key; // Update parent key to child key.
        if(heap_arr[2 * parent_key].key > heap_arr[2 * parent_key + 1].key){ // To prevent double downheap, update child as smaller child.
            child_key = 2 * parent_key + 1;
        }
        else{
            child_key = 2 * parent_key;
        }
        
        print_heap();
        std::cout << std::endl;
    }
}

// This assumes that it's a vector-based heap implementation. Here, "index" means the rank in the vector-based heap implementation, and it starts from 1 (root).
void Heap::replace_key(int index, int new_key){
    heap_arr[index].key = new_key; // update key in the given index position.

    int parent_key = index / 2; // To ensure heap-order property, we need to upheap
    int child_key = index;
    while(child_key > 0){ // Until reaching to root, check parent and child keeps heap order property which key(child) >= key(parent).
        // std::cout << "parent key: " << parent_key << " child key: " << child_key << std::endl;
        if(heap_arr[parent_key].key > heap_arr[child_key].key){ // If heap-order property violation found,
            // std::cout << "Violate!" << std::endl;
            int tmp_key = heap_arr[parent_key].key; // first temporarily store parent's key and value.
            std::string tmp_value = heap_arr[parent_key].value;
            heap_arr[parent_key].key = heap_arr[child_key].key; // Then, update parent key and value into child's one.
            heap_arr[parent_key].value = heap_arr[child_key].value;
            heap_arr[child_key].key = tmp_key; // Finally, update child's key and value into parent one which is temporarily stored above.
            heap_arr[child_key].value = tmp_value;
        }

        parent_key = parent_key / 2;
        child_key = child_key / 2;
    }
}

// This prints the keys in the heap. For each line, print the keys at the same depth, from left to right, separated by a single space (" "). It starts with the root node and proceeds to the deepest nodes, increasing the depth by one for each line.
void Heap::print_heap() const{
    int display_qty = 1;
    bool state = true;

    while (state){
        for(int i = display_qty; i < 2 * display_qty; i++){
            if(heap_arr[i].key == -1){
                state = false;
                break;
            }
            std::cout << heap_arr[i].key << " ";
        }
        std::cout << std::endl;

        display_qty *= 2;
    }
}