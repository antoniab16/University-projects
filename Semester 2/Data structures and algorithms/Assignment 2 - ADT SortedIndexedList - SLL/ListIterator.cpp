#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	current = list.head;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
void ListIterator::first(){
	current = list.head;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
void ListIterator::next(){
	if(current != nullptr){
        current = current->next;
    }
    else
        throw std::exception();
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
bool ListIterator::valid() const{
	return current != nullptr;
}

/// Time complexities
/// Best case : 0(1)
/// Worst case : 0(1)
/// Total complexity : 0(1)
TComp ListIterator::getCurrent() const{
	if(current != nullptr)
        return current->value;
	return NULL_TCOMP;
}


