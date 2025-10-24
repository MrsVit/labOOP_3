#pragma once
#include <iostream>
#include <string.h>
#include "dot.h"

using namespace std;

class Figure
{
    friend ostream& operator<<(ostream& os, const Figure& f);
    friend istream& operator>>(istream& is, Figure& f);
public:
    Figure() = default;
    virtual void Print(ostream& os) const = 0;
    virtual ~Figure() = default;
    virtual Point Center() const = 0;
    virtual double Area() const = 0;
    virtual void Read(istream& is) = 0;
    virtual operator double() const = 0;
    virtual bool operator==(const Figure& other) const = 0;
};

inline ostream& operator<<(ostream& os, const Figure& area) {
    area.Print(os);
    return os;
}

inline istream& operator>>(istream& is, Figure& area) {
    area.Read(is);
    return is;
}

