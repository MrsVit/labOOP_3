#ifndef SixSquere_H
#define SixSquere_H

#include <iostream>
#include "figure.h"

using namespace std;

class SixSquere : public Figure
{
private:
    Point p1, p2, p3, p4, p5, p6;
public:    
    SixSquere();
    SixSquere(istream& is);
    double Area();
    void Print(ostream& os);
    size_t VertexesNumber();
    virtual ~SixSquere();
};

#endif
