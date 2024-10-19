#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	this->current_element = 0;
    this->current_frequency = 0;
}

void BagIterator::first() {
    this->current_element = 0;
    this->current_frequency = 0;
}

void BagIterator::next() {
    if(this->valid()){
        if(this->current_frequency < this->bag.frequencies[this->current_element] - 1)
            this->current_frequency++;
        else {
            this->current_element++;
            this->current_frequency = 0;
        }
    }
    else
        throw exception();
}


bool BagIterator::valid() const {
    if(this->current_element < this->bag.size_bag)
        return true;
    return false;
}



TElem BagIterator::getCurrent() const
{
	if(this->valid())
        return this->bag.elements[current_element];
    else
        throw exception();
}
