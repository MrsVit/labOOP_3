#include "rhombus.h"
#include <cmath>

Rhombus::Rhombus() {
    points = new Point[count];
}

Rhombus::Rhombus(const Rhombus& other) : count(other.count) {
    points = new Point[count];
    for (int i = 0; i < count; ++i){
        points[i] = other.points[i];
    }
}

Rhombus::Rhombus(Rhombus&& other) noexcept : points(other.points), count(other.count) {
    other.points = nullptr;
    other.count= 0;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this == &other) return*this;

    delete[] points;

    count = other.count;
    points = new Point[count];
    for (int i = 0; i < count; ++i){
        points[i] = other.points[i];
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this == &other) return *this;

    delete[] points;

    count = other.count;
    points = other.points;

    other.points = nullptr;
    other.count = 0;

    return *this;
}

void Rhombus::Print(std::ostream& os) const {
    for (int i = 0; i < count; ++i){
        os << points[i] << " ";
}
}

void Rhombus::Read(std::istream& is) {
    for (int i = 0; i < count; ++i) is >> points[i];
}

Point Rhombus::Center() const {
    double x0{0.0}, y0 {0.0};
    for (int i = 0; i < count; ++i) {
        x0 += points[i].getX();
        y0 += points[i].getY();
    }
    return Point{x0 / count, y0 / count};
}

double Rhombus::Area() const {
    double d1 = points[0].dist(points[1]);
    double d2 = points[2].dist(points[3]);
    return d1 * d2 / 2.0;
}

Rhombus::operator double() const {
    return Area();
}

bool Rhombus::operator==(const Figure& other) const {
    if (typeid(*this) != typeid(other)) return false;
    return *this == static_cast<const Rhombus&>(other);
}

Rhombus::~Rhombus() {
    delete[] points;
}