#include "ArrayList.h"
#include "Item.h"
#include <iostream>

//namespace declaration
using namespace std;

//Debug macro
#define DEBUG
#ifdef DEBUG
#define DEBUG_MSG(msg) \
cerr << "Debug: " << msg << endl;
#else
#define DEBUG_MSG(msg)
#endif

//constructor
template<typename T>
ArrayList<T>::ArrayList() : capacity(10), size(0) {
    data = new T[capacity]; //allocates memory for initial capacity
}


//destructor
template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

//adding new elements
template<typename T>
void ArrayList<T>::add(const T& element) {
    if (size >= capacity) {
        capacity *= 2;
        T* newData = new T[capacity]; //allocates more memory for new array
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = element;
}

//size getter
template<typename T>
int ArrayList<T>::getSize() const {
    return size;
}

//method to access individual elements
template<typename T>
T& ArrayList<T>::operator[](int index) { //overloaded subscript operator
    if (index < 0 || index >= size) {
        DEBUG_MSG("out of bounds");
    }
    return data[index];
}

//method to add new items
template<typename T>
void ArrayList<T>::operator+(const T& element) { //overloaded + operator
    add(element);
}

//template instatiations for each type
template class ArrayList<int>;
template class ArrayList<std::string>;
template class ArrayList<Item>;
