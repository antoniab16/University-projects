#pragma once
#include <iostream>
#include "schools.h"

template <typename TElem>
class DynamicVector
{
private:
    TElem* elements;
    int capacity;
    int size;

public:
    DynamicVector(){
        this->capacity = 10;
        this->size = 0;
        this->elements = new TElem[capacity];
    }

    ~DynamicVector(){
        delete[] this->elements;
    }

    void resize(){
        this->capacity *= 2;
        TElem* new_elements = new TElem[this->capacity];
        for (int i = 0; i < this->size; i++)
            new_elements[i] = this->elements[i];
        delete[] this->elements;
        this->elements = new_elements;
    }

    void add(TElem element){
        if(this->size == this->capacity)
            this->resize();
        this->elements[this->size] = element;
        this->size++;
    }

    void remove(TElem element){
        for (int i = 0; i < this->size; i++)
        {
            if(this->elements[i] == elements){
                for (int j = i; j < this->size - 1; j++)
                    this->elements[j] = this->elements[j + 1];
            }
        }
    }

    int get_size()const{
        return this->size;
    }

    TElem&  operator[](int index)const{
        if(index > this->size || index < 0)
            throw std::out_of_range("Index out of range");
        return this->elements[index];
    }

    DynamicVector(const DynamicVector& arr) {
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->elements = new TElem[this->capacity];
        for(int i = 0; i < arr.size; i++)
            this->elements[i] = arr.elements[i];
    }
};