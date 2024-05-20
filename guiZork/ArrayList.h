#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include "Item.h"

template<typename T>
class ArrayList {
private:
    T* data;
    int capacity;
    int size;

public:
    ArrayList();
    ~ArrayList();
    void add(const T& element);
    int getSize() const;
    T& operator[](int index);
    const T& operator[](int index) const;
    void operator+(const T& element);
};

#endif // ARRAYLIST_H
