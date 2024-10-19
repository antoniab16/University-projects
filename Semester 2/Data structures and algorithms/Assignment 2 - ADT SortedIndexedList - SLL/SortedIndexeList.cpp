#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
SortedIndexedList::SortedIndexedList(Relation r) {
	this->relation = r;
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
int SortedIndexedList::size() const {
    return this->length;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
bool SortedIndexedList::isEmpty() const {
    return length == 0;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(n)
/// Total complexity : O(n)
TComp SortedIndexedList::getElement(int i) const{
	if(i < 0 || i >= length){
        throw std::exception();
    }
    Node* current = head;
    for(int j = 0; j < i; j++){
        current = current->next;
    }
    return current->value;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(n)
/// Total complexity : O(n)
TComp SortedIndexedList::remove(int i) {
	if(i < 0 || i >= length)
        throw std::exception();
    Node* current = head;
    for(int j = 0; j < i; j++)
        current = current->next;
    TComp value = current->value;
    if(current->previous != nullptr)
        current->previous->next = current->next;
    else
        head = current->next;
    if(current->next != nullptr)
        current->next->previous = current->previous;
    else
        tail = current->previous;
    delete current;
    length--;
    return value;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(n)
/// Total complexity : O(n)
int SortedIndexedList::search(TComp e) const {
	Node* current = head;
    int i = 0;
    while(current != nullptr){
        if(current->value == e)
            return i;
        current = current->next;
        i++;
    }
	return -1;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(n)
/// Total complexity : O(n)
void SortedIndexedList::add(TComp e) {
	Node* newNode = new Node(e);
    if(isEmpty())
        head = tail = newNode;
    else{
        Node* current = head;
        while(current != nullptr && relation(current->value, e)){
            current = current->next;
        }
        if (current == nullptr){
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        else if(current->previous == nullptr){
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
        else{
            newNode->next = current;
            newNode->previous = current->previous;
            current->previous->next = newNode;
            current->previous = newNode;
        }
    }
    length++;
}

ListIterator SortedIndexedList::iterator(){
	return ListIterator(*this);
}

/// Time complexities
/// Best case : 0(n)
/// Worst case : 0(n)
/// Total complexity : 0(n)
//destructor
SortedIndexedList::~SortedIndexedList() {
	while(head != nullptr){
        Node* next = head->next;
        delete head;
        head = next;
    }
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(n)
/// Total complexity : 0(n)
void SortedIndexedList::removeBetween(int start, int end){
    if(start < 0 || end >= length)
        throw std::exception();
    Node* current = head;
    int i = 0;
    while(i < start){
        current = current->next;
        i++;
    }
    Node* prevNode = current->previous;
    while(i <= end){
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
        i++;
        length--;
    }
    if (prevNode != nullptr)
        prevNode->next = current;
    else
        head = current;
    if(current != nullptr)
        current->previous = prevNode;
    else
        tail = prevNode;
}