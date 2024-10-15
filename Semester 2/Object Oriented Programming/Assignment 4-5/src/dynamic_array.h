#pragma once
#include "movies.h"
#include <assert.h>

typedef Movie TElem;

template <typename TElem>
class DynamicVector{
private:
    int length;
    int capacity;
    TElem* elements;

    /// Resizes the DynamicVector
    void resize() {
        this->capacity *= 2;
        TElem* array = new TElem[this->capacity];
        for(int i = 0; i < this->length; i++)
            array[i] = this->elements[i];
        delete[] this->elements;
        this->elements = nullptr;
        this->elements = array;
    }

public:
/// Takes capacity as a parameter and constructs the DynamicVector with it
/// \param capacity - the capacity of the DynamicVector
    DynamicVector() {
        this->capacity = 10;
        this->length = 0;
        this->elements = new TElem[this->capacity];

    }

/// Destructor for the DynamicVector
    ~DynamicVector() {
        delete[] this->elements;
    }

/// Returns the length of the DynamicVector
    int getLength() const{
        return this->length;
    }

/// Takes elem as a parameter and adds it to the DynamicVector
/// \param elem - element to be added
    void add(TElem elem) {
        if(this->length == this->capacity)
            this->resize();
        this->elements[this->length] = elem;
        this->length++;
    }

/// Takes elem as a parameter and removes it from the DynamicVector
/// \param elem - element to be removed
    void remove(TElem elem) {
        for(int i = 0; i < this->length; i++){
            if(this->elements[i] == elem){
                for(int j = i ; j < this->length - 1; j++)
                    this->elements[j] = this->elements[j + 1];
                this->length--;
                return;
            }
        }
    }

/// Copy constructor for the DynamicVector
    DynamicVector(const DynamicVector& arr) {
        this->capacity = arr.capacity;
        this->length = arr.length;
        this->elements = new TElem[this->capacity];
        for(int i = 0; i < arr.length; i++)
            this->elements[i] = arr.elements[i];
    }

/// Overloaded operator for the DynamicVector
    TElem& operator[](int index) {
        if(index < 0 || index >= this->length)
            throw std::runtime_error("Invalid index");
        return this->elements[index];
    }

    const TElem& operator[](int index) const {
        if(index < 0 || index >= this->length)
            throw std::runtime_error("Invalid index");
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

    void test_operator_index(){
        DynamicVector vector;
        Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
        vector.add(movie1);
        Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
        vector.add(movie2);
        assert(vector[0] == movie1);
        assert(vector[1] == movie2);
        try{
            Movie moive = vector[2];
        } catch(const std::runtime_error& e){
            assert(std::string(e.what()) == "Invalid index");
        }
    }

};

