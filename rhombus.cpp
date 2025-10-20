#include <cmath>
#include "rhombus.h"

using namespace std;

Rhombus::Rhombus(istream& is)
{
    is >> p1 >> p2 >> p3 >> p4;
}
Rhombus::~Rhombus() = default;
void Rhombus::Print(ostream& os)
{
    os << "Rhombus: " << p1 << " " << p2 << " " << p3 << " " << p4 << endl;
}

double Rhombus::Area() //лёгкий способ, необходимо заставить пользователя вводить верщины по порядку A-B-C-D (двигаясь по рёбрам)
{
    return 0.5 * p1.dist(p3) * p2.dist(p4);
}
size_t Rhombus::VertexesNumber()
{
    return 4;
}
