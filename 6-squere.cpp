#include <cmath>
#include "6-square.h"

using namespace std;

SixSquere::SixSquere(istream& is) {
    is >> p1 >> p2 >> p3 >> p4 >> p5 >> p6;
}
SixSquere::~SixSquere() = default;
void SixSquere::Print(ostream& os) {
    os << "SixSquere: " << p1 << " " << p2 << " " << p3 << " " << p4
       << " " << p5 << " " << p6 << endl;
}

double SixSquere::Area() {
    Point points[6] = {p1, p2, p3, p4, p5, p6};
    double sum = 0.0;
    for (int i = 0; i < 6; ++i) {
        int j = (i + 1) % 6;
        sum += points[i].getX() * points[j].getY() - points[j].getX() * points[i].getY();
    }
    return std::abs(sum) * 0.5;
}

size_t SixSquere::VertexesNumber() {
    return 6;
}