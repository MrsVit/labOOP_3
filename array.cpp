#include "array.h"

#include <iostream>
#include <stdexcept>

void Array::Add(std::shared_ptr<Figure> fig) {
    data.push_back(std::move(fig));
}

void Array::Remove(size_t index) {
    if (index >= data.size()) 
        throw std::out_of_range("Invalid index");
    data.erase(data.begin() + index);
}

double Array::TotalArea() const { 
    double total = 0;
    for (const auto& f : data) {
        total += f->Area();  
    }
    return total;
}

void Array::Print() const {
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << i << ':';
        data[i]->Print(std::cout);
        std::cout << " | Area = " << data[i]->Area() << "\n";
    }
}

void Array::Centers() const {
    for (size_t i = 0; i < data.size(); ++i) {
        auto c = data[i]->Center();
        std::cout << i << ": Center = (" << c.getX() << ", " << c.getY() << ")\n";
    }
}

