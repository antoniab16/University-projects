#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	this->capacity = 10;
    this->size_bag = 0;
    this->elements = new TElem[this->capacity];
    this->frequencies = new int[this->capacity];
}

/// Time complexities
/// Best case : O(1)
/// Worst case : O(n)
/// Total complexity : 0(n)
void Bag::add(TElem elem) {
    for(int i = 0; i < this->size_bag; i++) {
        if (this->elements[i] == elem) {
            this->frequencies[i]++;
            return;
        }
    }
    if(this->size_bag == this->capacity)
        this->resize();
    this->elements[this->size_bag] = elem;
    this->frequencies[this->size_bag] = 1;
    this->size_bag++;
}

/// Time complexities
/// Best case : O(1)
/// Worst case : O(n)
/// Total complexity : 0(n)
bool Bag::remove(TElem elem) {
    int index = -1;
    for(int i = 0; i < this->size_bag; i++){
        if(this->elements[i] == elem){
            index = i;
            break;
        }
    }
    if(index != -1){
        this->frequencies[index]--;
        if(this->frequencies[index] <= 0){
            for(int i = index; i < this->size_bag; i++){
                this->elements[i] = this->elements[i + 1];
                this->frequencies[i] = this->frequencies[i + 1];
            }
            this->size_bag--;
        }
        return true;
    }
    return false;
}

/// Time complexities
/// Best case : O(1)
/// Worst case : O(n)
/// Total complexity : 0(n)
bool Bag::search(TElem elem) const {
    for(int i = 0; i < this->size_bag; i++){
        if(this->elements[i] == elem)
            return true;
    }
	return false; 
}

/// Time complexities
/// Best case : O(1)
/// Worst case : O(n)
/// Total complexity : 0(n)
int Bag::nrOccurrences(TElem elem) const {
    int count = 0;
    for(int i = 0; i < this->size_bag; i++){
        if(this->elements[i] == elem){
            count += this->frequencies[i];
        }
    }
	return count;
}

/// Time complexities
/// Best case : O(n)
/// Worst case : O(n)
/// Total complexity : O(n)
int Bag::size() const {
    int total_size = 0;
    for(int i = 0; i < this->size_bag; i++)
        total_size += this->frequencies[i];
    return total_size;
}


bool Bag::isEmpty() const {
    return this->size_bag == 0;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	delete[] this->elements;
    delete[] this->frequencies;
}

/// Time complexities
/// Best case : O(n)
/// Worst case : O(n)
/// Total complexity : 0(n)
void Bag::resize() {
    if (this->size_bag == this->capacity) {
        this->capacity *= 2;
        TElem *new_elements = new TElem[this->capacity];
        int *new_frequencies = new int[this->capacity];
        for (int i = 0; i < this->size_bag; i++) {
            new_elements[i] = this->elements[i];
            new_frequencies[i] = this->frequencies[i];
        }
        delete[] this->elements;
        delete[] this->frequencies;
        this->elements = new_elements;
        this->frequencies = new_frequencies;
    }
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(n)
/// Total complexity : O(n)
int Bag::removeOccurances(int nr, TElem elem) {
    int index = -1;
    for(int i = 0; i < this->size_bag; i++){
        if(this->elements[i] == elem){
            index = i;
            break;
        }
    }
    if (nr < 0 || index == -1)
        throw exception();
    int count;
    if (index != -1){
        if(nrOccurrences(elem) < nr)
            nr = nrOccurrences(elem);
        this->frequencies[index] = this->frequencies[index] - nr;
        if(this->frequencies[index] <= 0)
            remove(elem);
        count = nr;
    }
    return count;
}

