#include "5-square.h" 
#include <cmath>
#include <iostream>

Fivesquere::Fivesquere() : count(5) {
    points = new Point[count];
}

Fivesquere::Fivesquere(const Fivesquere& other) : count(5) {
    points = new Point[count];
    for (int i = 0; i < count; ++i) {
        points[i] = other.points[i];
    }
}

Fivesquere::Fivesquere(Fivesquere&& other) noexcept : points(other.points), count(other.count) {
    other.points = nullptr;
    other.count = 0;
}

Fivesquere& Fivesquere::operator=(const Fivesquere& other) {
    if (this == &other) return *this;

    delete[] points;

    count = 5;
    points = new Point[count];
    for (int i = 0; i < count; ++i) {
        points[i] = other.points[i];
    }
    return *this;
}

Fivesquere& Fivesquere::operator=(Fivesquere&& other) noexcept {
    if (this == &other) return *this;

    delete[] points;

    points = other.points;
    count = other.count;

    other.points = nullptr;
    other.count = 0;

    return *this;
}

void Fivesquere::Print(std::ostream& os) const {
    for (int i = 0; i < count; ++i) {
        os << points[i] << " ";
    }
}

void Fivesquere::Read(std::istream& is) {
    for (int i = 0; i < count; ++i) {
        is >> points[i];
    }
}

Point Fivesquere::Center() const {
    double x0 = 0.0, y0 = 0.0;
    for (int i = 0; i < count; ++i) {
        x0 += points[i].getX();
        y0 += points[i].getY();
    }
    return Point{x0 / count, y0 / count};
}

double Fivesquere::Area() const {
    // Формула площади многоугольника на самом деле одинакова для всех правильных многоугольников
    //поэтому реализации Center и Area совпадают
    double area = 0.0;
    for (int i = 0; i < count; ++i) {
        int j = (i + 1) % count;
        area += points[i].getX() * points[j].getY();
        area -= points[j].getX() * points[i].getY();
    }
    return std::abs(area) / 2.0;
}

Fivesquere::operator double() const {
    return Area();
}

bool Fivesquere::operator==(const Figure& other) const {
    if (typeid(*this) != typeid(other)) return false;
    const Fivesquere& that = static_cast<const Fivesquere&>(other);
    if (count != that.count) return false;
    for (int i = 0; i < count; ++i) {
        if (!(points[i].getX() == that.points[i].getX() && points[i].getY() == that.points[i].getY())) return false;
    }
    return true;
}

Fivesquere::~Fivesquere() {
    delete[] points;
}