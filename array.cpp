#include "array.h"
#include <iostream>
#include <stdexcept>

Array::Array(): data(nullptr), size(0), capacity(0) 
{}

void Array::Add(Figure* figure) {
    if (size >= capacity) {
        Resize();  
    }
    data[size++] = figure;
}

void Array::Resize() {  
    size_t next_capacity = (capacity == 0) ? 1 : capacity * 2;
    Figure** new_data = new Figure*[next_capacity];

    for (size_t i = 0; i < size; ++i) {
        new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = next_capacity;
}

void Array::Remove(size_t i) {
    if (i >= size) {
        throw std::out_of_range("Out_of_range");
    }

    delete data[i];  
    for (size_t j = i; j < size - 1; ++j) {
        data[j] = data[j + 1];
    }
    --size;
}

double Array::TotalArea() const {
    double total = 0;
    for (size_t i = 0; i < size; ++i) {
        total += data[i]->Area();
    }
    return total;
}

void Array::Print() const {
    for (size_t i = 0; i < size; ++i) {
        data[i]->Print(std::cout); 
    }
}

void Array::Centers() const {
    for (size_t i = 0; i < size; ++i) {
        data[i]->Center();  
    }
}

Array::~Array() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
}