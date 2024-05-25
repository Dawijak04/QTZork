#include "List.h"
#include "Item.h"
#include <QDebug>
// Constructor
template <typename T>
List<T>::List(int initialCapacity, const T& initialValue) : size(0), capacity(initialCapacity) {
    elements = new T[capacity];
    for (int i = 0; i < capacity; ++i) {
        elements[i] = initialValue;
    }
}

// Destructor
template <typename T>
List<T>::~List() {
    delete[] elements;
}

template <typename T>
List<T> List<T>::operator+(const T& element) {
    // Check if the capacity needs to be increased
    if (size >= capacity) {
        // Double the capacity
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_elements = new T[capacity];

        // Copy existing elements to the new array
        for (int i = 0; i < size; ++i) {
            new_elements[i] = elements[i];
        }

        // Update the elements pointer
        delete[] elements;
        elements = new_elements;
    }

    // Add the new element to the list
    elements[size++] = element;

    return *this; // Return the modified list
}


// Display the elements of the list
template <typename T>
void List<T>::display() {
    std::cout << "Elements of the list: ";
    for (int i = 0; i < size; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int List<T>::getSize() const {
    return size;
}

template <typename T>
T& List<T>::getElementAt(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}
template class List<Item>;
