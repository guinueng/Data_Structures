/* add whatever you want*/
#include "heap.h"

enum class INT { MAX = 2147483647 };

Heap::Heap(int capacity){
    heap_arr = new heap_elem[capacity + 1]; // Assign new heap array.
    qty = 0; // Initialize tot qty as 0.
    max = capacity; // Check max capacity.
}

Heap::~Heap(){
    delete[] heap_arr; // Delete heap array during destruction.
}

bool Heap::empty() const{
    if(qty == 0){ // If quantity is 0, return true.
        return true;
    }
    else{ // Otherwise, return false.
        return false;
    }
}

void Heap::insert(int key, const std::string& value){
    if(empty()){ // If heap array is empty,
        heap_arr[1].key = key; // assign key, position and value into first position.
        heap_arr[1].position = 1;
        heap_arr[1].value = value;

        qty++; // Inc qty.
    }
    else{ // Else, to ensure complete binary tree property,
        qty++; // Inc qty first to assign new value into next position of last element.
        heap_arr[qty].key = key; // assign key, position and value in the next to last position.
        heap_arr[qty].position = qty;
        heap_arr[qty].value = value;

        int parent_key = qty / 2; // To ensure heap-order property, we need to pursue upheap.
        int child_key = qty;
        while(child_key > 0){ // Until reaching to root, check parent and child keeps heap order property which key(child) >= key(parent).
            if(heap_arr[parent_key].key > heap_arr[child_key].key){ // If heap-order property violation found,
                int tmp_key = heap_arr[parent_key].key; // first temporarily store parent's key and value.
                std::string tmp_value = heap_arr[parent_key].value;

                heap_arr[parent_key].key = heap_arr[child_key].key; // Then, update parent key and value into child's one.
                heap_arr[parent_key].value = heap_arr[child_key].value;

                heap_arr[child_key].key = tmp_key; // Finally, update child's key and value into parent one which is temporarily stored above.
                heap_arr[child_key].value = tmp_value;
                // Did not have to modify two element's position value due to they just exchanged location.
            }

            parent_key = parent_key / 2; // Update parent key and child key into it's parent one.
            child_key = child_key / 2;
        }
    }
}

void Heap::remove_min(){
    heap_arr[1].key = heap_arr[qty].key; // assign last position's key and value into root of heap.
    heap_arr[1].value = heap_arr[qty].value;

    heap_arr[qty].key = -1; // To prevent mistake, due to assumption given in description, fill last elem as key = -1, position = -1 and value = " ".
    heap_arr[qty].position = -1;
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
        if(heap_arr[parent_key].key > heap_arr[child_key].key){ // If heap-order property violation found,
            int tmp_key = heap_arr[parent_key].key; // first temporarily store parent's key and value.
            std::string tmp_value = heap_arr[parent_key].value;

            heap_arr[parent_key].key = heap_arr[child_key].key; // Then, update parent key and value into child's one.
            heap_arr[parent_key].value = heap_arr[child_key].value;

            heap_arr[child_key].key = tmp_key; // Finally, update child's key and value into parent one which is temporarily stored above.
            heap_arr[child_key].value = tmp_value;
            // Did not have to modify two element's position value due to they just exchanged location.
        }

        parent_key = child_key; // Update parent key to child key.
        if(qty > (2 * parent_key + 1) && heap_arr[2 * parent_key].key > heap_arr[2 * parent_key + 1].key){ // To prevent double downheap, update child as smaller child.
            child_key = 2 * parent_key + 1;
        }
        else{
            child_key = 2 * parent_key;
        }        
    }

    qty--;
}

// This assumes that it's a vector-based heap implementation. Here, "index" means the rank in the vector-based heap implementation, and it starts from 1 (root).
void Heap::replace_key(int index, int new_key){
    heap_arr[index].key = new_key; // update key in the given index position.

    int parent_key = index / 2; // To ensure heap-order property, we need to upheap
    int child_key = index;
    while(child_key > 0){ // Until reaching to root, check parent and child keeps heap order property which key(child) >= key(parent).
        if(heap_arr[parent_key].key > heap_arr[child_key].key){ // If heap-order property violation found,
            int tmp_key = heap_arr[parent_key].key; // first temporarily store parent's key and value.
            std::string tmp_value = heap_arr[parent_key].value;

            heap_arr[parent_key].key = heap_arr[child_key].key; // Then, update parent key and value into child's one.
            heap_arr[parent_key].value = heap_arr[child_key].value;

            heap_arr[child_key].key = tmp_key; // Finally, update child's key and value into parent one which is temporarily stored above.
            heap_arr[child_key].value = tmp_value;
            // Did not have to modify two element's position value due to they just exchanged location.
        }

        parent_key = parent_key / 2; // Update parent key and child key into it's parent one.
        child_key = child_key / 2;
    }
}

// This prints the keys in the heap. For each line, print the keys at the same depth, from left to right, separated by a single space (" "). It starts with the root node and proceeds to the deepest nodes, increasing the depth by one for each line.
void Heap::print_heap() const{
    int display_qty = 1;
    bool state = true;

    while (state){
        for(int i = display_qty; i < 2 * display_qty; i++){ // Loop display qty to double of it's value to print display quantity of key element in heap.
            if(i == (max + 1) || heap_arr[i].key == -1){ // If exceed array range or meaningless value contained found,
                state = false; // Change while statement as false.
                break; // Break loop.
            }

            std::cout << heap_arr[i].key << " ";
        }
        std::cout << std::endl; // Print line change.

        display_qty *= 2; // Double quantity of printing one line.
    }
}

int Heap::find_index(const std::string& value){
    for(int i = 1; i <= qty; i++){
        if(heap_arr[i].value == value){
            return heap_arr[i].position;
        }
    }

    return int(INT::MAX); // Return INT_MAX value to notify there is no element of given string.
    // If reached at end of this function, need to raise Exception. Case: Element not found.
    // But due to assumption given in description, we do not need to raise it.
}