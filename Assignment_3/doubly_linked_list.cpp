/* Write your code here */
#include "doubly_linked_list.h"
#include "container_exception.h"

DoublyLinkedList::DoublyLinkedList() : header(new Node), trailer(new Node){
    header -> next = trailer; // First, header and trailer must point each other.
    header -> prev = NULL; // Thus, header's next point trailer and
    trailer -> prev = header; // trailer's prev point header.
    trailer -> next = NULL; // Then, header's prev and trailer's next is not pointing something else,
} // so, put null pointer to indicate this is the end part.

DoublyLinkedList::~DoublyLinkedList(){
    while(!empty()) // If doubly linked list(will be talked as dll), has element, 
        remove_front(); // remove all that element.
    delete header; // Then remove header
    delete trailer; // and trailer.
}

int DoublyLinkedList::size() const{
    Node* tmp = header; // First assign temporary pointer to node to store pointer value header.
    int cnt = 0; // Then assign integer cnt to count how many element in there.
    if(!empty()) // Check empty.
        while(tmp -> next != trailer){ // Then, if next address is not trailer, which is not end part
            cnt++; // Increase count and change tmp value to next address.
            tmp = tmp -> next;
        }
    return cnt; // Return counted value.
}

bool DoublyLinkedList::empty() const{
    if(header -> next == trailer) // Using property of initializing dll, if header points trailer,
        return true; // return true.
    else // Else, return false.
        return false;
}

const std::string& DoublyLinkedList::front() const{
    if(empty()) // If fetching empty container,
        throw ContainerEmpty("Container is Empty."); // throw exception.
    return header -> next -> ele; // return front element by using element of header's next pointer.
}

const std::string& DoublyLinkedList::back() const{
    if(empty()) // If fetching empty container,
        throw ContainerEmpty("Container is Empty."); // throw exception.
    return trailer -> prev -> ele; // Similar as front(), but reaching from backwards.
}

void DoublyLinkedList::add_front(const std::string& e){
    Node* target = new Node; // Create new node.
    target -> ele = e; // Assign value into new node.
    target -> next = header -> next; // new element's next pointer will point current header is pointing next.
    target -> prev = header; // new element's previous pointer will point header.
    header -> next -> prev = target; // Current header's next element's previous pointer will point new element.
    header -> next = target; // header's next will point new element.
}

void DoublyLinkedList::add_back(const std::string& e){ // Similar as add_front.
    Node* target = new Node;
    target -> ele = e;
    target -> next = trailer;
    target -> prev = trailer -> prev;
    trailer -> prev -> next = target;
    trailer -> prev = target;
}

void DoublyLinkedList::remove_front(){
    if(empty()) // If fetching empty container,
        throw ContainerEmpty("Container is Empty."); // throw exception.
    Node* tmp = header -> next; 
    tmp -> next -> prev = header;
    header -> next = tmp -> next;
    delete tmp;
}

void DoublyLinkedList::remove_back(){
    if(empty()) // If fetching empty container,
        throw ContainerEmpty("Container is Empty."); // throw exception.
    Node* tmp = trailer -> prev;
    tmp -> prev -> next = trailer;
    trailer -> prev = tmp -> prev;
    delete tmp;
}