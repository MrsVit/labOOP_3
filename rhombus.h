#ifndef RHOMBUS_H
#define rhombus_H

#include <iostream>
#include "figure.h"

using namespace std;

class Rhombus : public Figure
{
private:
    Point p1, p2, p3, p4;
public:    
    Rhombus();
    Rhombus(istream& is);
    double Area();
    void Print(ostream& os);
    size_t VertexesNumber();
    virtual ~Rhombus();
};

#endif
