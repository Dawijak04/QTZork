#include "ArrayList.h"

template<typename T>
ArrayList<T>::ArrayList() : capacity(10), size(0) {
    data = new T[capacity];
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] data;
}

template<typename T>
void ArrayList<T>::add(const T& element) {
    if (size >= capacity) {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    data[size++] = element;
}

template<typename T>
int ArrayList<T>::getSize() const {
    return size;
}

template<typename T>
T& ArrayList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("out of bounds");
    }
    return data[index];
}

template<typename T>
const T& ArrayList<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("out of bounds");
    }
    return data[index];
}

template<typename T>
void ArrayList<T>::operator+(const T& element) {
    add(element);
}


template class ArrayList<int>;
template class ArrayList<std::string>;
template class ArrayList<Item>;
