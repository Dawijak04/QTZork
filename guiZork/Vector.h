#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector {
private:
    T* elements; // Pointer to dynamically allocated array
    int size;    // Size of the vector
    int capacity; // Capacity of the dynamically allocated array

public:
    // Constructor
    Vector();

    // Destructor
    ~Vector();

    // Overloaded + operator to add elements to the vector
    Vector<T> operator+(const T& element);

    // Display the elements of the vector
    void display();
};

#endif // VECTOR_H
