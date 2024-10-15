#pragma once
#include "movies.h"
#include <assert.h>
#include <vector>
#include <algorithm>

typedef Movie TElem;

template <typename TElem>
class DynamicVector {
private:
    std::vector<TElem> elements;

    /// Resizes the DynamicVector
    void resize() {
        this->capacity *= 2;
        TElem *array = new TElem[this->capacity];
        for (int i = 0; i < this->length; i++)
            array[i] = this->elements[i];
        delete[] this->elements;
        this->elements = nullptr;
        this->elements = array;
    }

public:
    typedef TElem value_type;

    DynamicVector() = default;

    ~DynamicVector() = default;

    size_t getLength() {
        return this->elements.size();
    }

    void add(TElem elem){
        this->elements.push_back(elem);
    }

    void push_back(const TElem& elem){
        this->add(elem);
    }

    void remove(TElem elem){
        this->elements.erase(std::remove(this->elements.begin(), this->elements.end(), elem), this->elements.end());
    }

    TElem& operator[](int index){
        if(index < 0 || index >= this->getLength())
            throw std::runtime_error("Invalid index");
        return this->elements[index];
    }

    const TElem& operator[](int index) const{
        if(index < 0 || index >= this->getLength())
            throw std::runtime_error("Invalid index");
        return this->elements[index];
    }

    typename std::vector<TElem>::iterator begin(){
        return elements.begin();
    }

    typename std::vector<TElem>::iterator end(){
        return elements.end();
    }

    void clear(){
        this->elements.clear();
    }

    Movie& at(int index){
        if(index <  0 || index >= this->getLength())
            throw std::out_of_range("out of range");
        return this->elements[index];
    }

    void test_construct() {
        DynamicVector vector;
        assert(vector.getLength() == 0);
    }

    void test_add() {
        DynamicVector vector;
        Movie movie("Title", "Genre", 2004, 1000, "Trailer");
        vector.add(movie);
        assert(vector.getLength() == 1);
    }

    void test_remove(){
        DynamicVector vector;
        Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
        vector.add(movie1);
        Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
        vector.add(movie2);
        assert(vector.getLength() == 2);
        vector.remove(movie1);
        assert(vector.getLength() == 1);
    }

    void test_size() {
        DynamicVector vector;
        for(int i = 0; i < 100; i++){
            Movie movie("Title", "Genre", 2004, 1000, "Trailer");
            vector.add(movie);
        }
        assert(vector.getLength() == 100);
    }

    void test_resize() {
        DynamicVector vector;
        Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
        vector.add(movie1);
        Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
        vector.add(movie2);
        Movie movie3("Title2", "Genre2", 2004, 1002, "Trailer2");
        vector.add(movie3);
        assert(vector.getLength() == 3);
    }

    void test_copy_constructor() {
        DynamicVector vector;
        Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
        vector.add(movie1);
        Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
        vector.add(movie2);
        DynamicVector copyVector(vector);
        assert(copyVector.getLength() == vector.getLength());
        for(int i = 0; i < vector.getLength(); i++)
            assert(copyVector[i] == vector[i]);
    }

    void test_operator_index() {
        DynamicVector vector;
        Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
        vector.add(movie1);
        Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
        vector.add(movie2);
        assert(vector[0] == movie1);
        assert(vector[1] == movie2);
        try {
            Movie moive = vector[2];
        }catch (const std::runtime_error &e) {
            assert(std::string(e.what()) == "Invalid index");
        }
    }
};