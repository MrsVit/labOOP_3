#ifndef FiveSquere_H
#define FiveSquere_H

#include <iostream>
#include "figure.h"

using namespace std;

class FiveSquere : public Figure
{
private:
    Point p1, p2, p3, p4, p5;
public:    
    FiveSquere();
    FiveSquere(istream& is);
    double Area();
    void Print(ostream& os);
    size_t VertexesNumber();
    virtual ~FiveSquere();
};

#endif
