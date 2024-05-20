#include "Vector.h"

// Constructor
template <typename T>
Vector<T>::Vector() : elements(nullptr), size(0), capacity(0) {}

// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete[] elements;
}

// Overloaded + operator to add elements to the vector
template <typename T>
Vector<T> Vector<T>::operator+(const T& element) {
    // Check if the capacity needs to be increased
    if (size >= capacity) {
        // Double the capacity
        capacity = (capacity == 0) ? 1 : capacity * 2;
        T* new_elements = new T[capacity];

        // Copy existing elements to the new array
        for (int i = 0; i < size; ++i) {
            new_elements[i] = elements[i];
        }

        // Delete the old array and update the pointer
        delete[] elements;
        elements = new_elements;
    }

    // Add the new element to the vector
    elements[size++] = element;

    return *this; // Return the modified vector
}

// Display the elements of the vector
template <typename T>
void Vector<T>::display() {
    std::cout << "Elements of the vector: ";
    for (int i = 0; i < size; ++i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}
