#include <cmath>
#include <vector>
#include "5-square.h"

using namespace std;

FiveSquere::FiveSquere(istream& is) {
    is >> p1 >> p2 >> p3 >> p4 >> p5;
}
FiveSquere::~FiveSquere() = default;
void FiveSquere::Print(ostream& os) {
    os << "FiveSquere: " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << endl;
}

double FiveSquere::Area() {
    Point points[5] = {p1, p2, p3, p4, p5};
    double sum = 0.0;
    for (int i = 0; i < 5; ++i) {
        int j = (i + 1) % 5;
        sum += points[i].getX() * points[j].getY() - points[j].getX() * points[i].getY();
    }
    return std::abs(sum) * 0.5;
}

size_t FiveSquere::VertexesNumber() {
    return 5;
}