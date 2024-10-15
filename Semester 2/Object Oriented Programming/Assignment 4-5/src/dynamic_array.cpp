//#include "dynamic_array.h"
//#include <cassert>
//
///// Takes capacity as a parameter and constructs the DynamicVector with it
///// \param capacity - the capacity of the DynamicVector
//template<typename TElem>
//DynamicVector<TElem>::DynamicVector(int capacity) {
//    this->capacity = capacity;
//    this->length = 0;
//    this->elements = new TElem[this->capacity];
//
//}
//
///// Destructor for the DynamicVector
//template<typename TElem>
//DynamicVector<TElem>::~DynamicVector() {
//    delete[] this->elements;
//}
//
///// Returns the length of the DynamicVector
//template<typename TElem>
//int DynamicVector<TElem>::getLength() const{
//    return this->length;
//}
//
///// Takes elem as a parameter and adds it to the DynamicVector
///// \param elem - element to be added
//template<typename TElem>
//void DynamicVector<TElem>::add(TElem elem) {
//    if(this->length == this->capacity)
//        this->resize();
//    this->elements[this->length] = elem;
//    this->length++;
//}
//
///// Resizes the DynamicVector
//template<typename TElem>
//void DynamicVector<TElem>::resize() {
//    this->capacity *= 2;
//    TElem* array = new TElem[this->capacity];
//    for(int i = 0; i < this->length; i++)
//        array[i] = this->elements[i];
//    delete[] this->elements;
//    this->elements = nullptr;
//    this->elements = array;
//}
//
///// Takes elem as a parameter and removes it from the DynamicVector
///// \param elem - element to be removed
//template<typename TElem>
//void DynamicVector<TElem>::remove(TElem elem) {
//    for(int i = 0; i < this->length; i++){
//        if(this->elements[i] == elem){
//            for(int j = i ; j < this->length - 1; j++)
//                this->elements[j] = this->elements[j + 1];
//            this->length--;
//            return;
//        }
//    }
//}
//
///// Copy constructor for the DynamicVector
//template<typename TElem>
//DynamicVector<TElem>::DynamicVector(const DynamicVector& arr) {
//    this->capacity = arr.capacity;
//    this->length = arr.length;
//    this->elements = new TElem[this->capacity];
//    for(int i = 0; i < arr.length; i++)
//        this->elements[i] = arr.elements[i];
//}
//
///// Overloaded operator for the DynamicVector
//template<typename TElem>
//Movie &DynamicVector<TElem>::operator[](int index) {
//    if(index < 0 || index >= this->length)
//        throw std::runtime_error("Invalid index");
//    return this->elements[index];
//}
//
//template<typename TElem>
//void DynamicVector<TElem>::test_construct() {
//    DynamicVector vector;
//    assert(vector.getLength() == 0);
//}
//
//template<typename TElem>
//void DynamicVector<TElem>::test_add() {
//    DynamicVector vector;
//    Movie movie("Title", "Genre", 2004, 1000, "Trailer");
//    vector.add(movie);
//    assert(vector.getLength() == 1);
//}
//
//template<typename TElem>
//void DynamicVector<TElem>::test_remove(){
//    DynamicVector vector;
//    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
//    vector.add(movie1);
//    Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
//    vector.add(movie2);
//    assert(vector.getLength() == 2);
//    vector.remove(movie1);
//    assert(vector.getLength() == 1);
//}
//
//template<typename TElem>
//void DynamicVector<TElem>::test_size() {
//    DynamicVector vector;
//    for(int i = 0; i < 100; i++){
//        Movie movie("Title", "Genre", 2004, 1000, "Trailer");
//        vector.add(movie);
//    }
//    assert(vector.getLength() == 100);
//}
//
//template<typename TElem>
//void DynamicVector<TElem>::test_resize() {
//    DynamicVector vector(2);
//    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
//    vector.add(movie1);
//    Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
//    vector.add(movie2);
//    Movie movie3("Title2", "Genre2", 2004, 1002, "Trailer2");
//    vector.add(movie3);
//    assert(vector.getLength() == 3);
//}
//
//template<typename TElem>
//void DynamicVector<TElem>::test_copy_constructor() {
//    DynamicVector vector;
//    Movie movie1("Title", "Genre", 2004, 1000, "Trailer");
//    vector.add(movie1);
//    Movie movie2("Title1", "Genre1", 2004, 1001, "Trailer1");
//    vector.add(movie2);
//    DynamicVector copyVector(vector);
//    assert(copyVector.getLength() == vector.getLength());
//    for(int i = 0; i < vector.getLength(); i++)
//        assert(copyVector[i] == vector[i]);
//}
//
//
//
//
//
