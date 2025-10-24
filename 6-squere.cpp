#include "6-square.h"
#include <vector>
#include <numeric>

Sixsquere::Sixsquere() : count(6) {
    points = new Point[count];
}

Sixsquere::Sixsquere(const Sixsquere& other) : count(6) {
    points = new Point[count];
    for (int i = 0; i < count; ++i) {
        points[i] = other.points[i];
    }
}

Sixsquere::Sixsquere(Sixsquere&& other) noexcept : points(other.points), count(other.count) {
    other.points = nullptr;
    other.count = 0;
}

Sixsquere& Sixsquere::operator=(const Sixsquere& other) {
    if (this == &other) return *this;

    delete[] points;

    count = 6;
    points = new Point[count];
    for (int i = 0; i < count; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}

Sixsquere& Sixsquere::operator=(Sixsquere&& other) noexcept {
    if (this == &other) return *this;

    delete[] points;

    points = other.points;
    count = other.count;

    other.points = nullptr;
    other.count = 0;

    return *this;
}

void Sixsquere::Print(std::ostream& os) const {
    for (int i = 0; i < count; ++i) {
        os << points[i] << " ";
    }
}

void Sixsquere::Read(std::istream& is) {
    for (int i = 0; i < count; ++i) {
        is >> points[i];
    }
}

Point Sixsquere::Center() const {
    double x0 = 0.0, y0 = 0.0;
    for (int i = 0; i < count; ++i) {
        x0 += points[i].getX();
        y0 += points[i].getY();
    }
    return Point{x0 / count, y0 / count};
}

double Sixsquere::Area() const {
    double area = 0.0;
    for (int i = 0; i < count; ++i) {
        int j = (i + 1) % count;
        area += points[i].getX() * points[j].getY();
        area -= points[j].getX() * points[i].getY();
    }
    return std::abs(area) / 2.0;
}

Sixsquere::operator double() const {
    return Area();
}

bool Sixsquere::operator==(const Figure& other) const {
    if (typeid(*this) != typeid(other)) return false;
    const Sixsquere& that = static_cast<const Sixsquere&>(other);
    if (count != that.count) return false;
    for (int i = 0; i < count; ++i) {
        if (!(points[i].getX() == that.points[i].getX() && 
              points[i].getY() == that.points[i].getY())) 
            return false;
    }
    return true;
}

Sixsquere::~Sixsquere() {
    delete[] points;
}