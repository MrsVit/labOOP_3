#pragma once

#include "figure.h"
#include <vector>
#include <memory>

class Array {
public:
    Array();
    void Add(Figure* fig);
    void Remove(size_t index);
    void Print() const;
    double TotalArea() const;
    void Centers() const;
    ~Array();

private:
    Figure** data;     
    size_t size;       
    size_t capacity;
    void Resize();

};