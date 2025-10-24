#include "rhombus.h"
#include "5-square.h"     // или pentagon.h
#include"6-square.h"     // или hexagon.h
#include "array.h"

#include <gtest/gtest.h>
#include <sstream>
#include <memory>

// Тест Rhombus
TEST(RhombusTest, AreaAndCenter) {
    std::istringstream input("0 0 2 0 3 1 1 1"); // точки ромба
    auto rh = std::make_shared<Rhombus>();
    input >> *rh;

    double area = rh->Area();
    auto center = rh->Center();

    // Площадь ромба по формуле: |d1 × d2| / 2
    // Диагонали: d1 = (0,0)-(3,1) → длина sqrt(10), d2 = (2,0)-(1,1) → sqrt(2)
    // Но проще проверить через векторное произведение или известные координаты.
    // Для ромба с вершинами (0,0), (2,0), (3,1), (1,1) площадь = 2.0
    EXPECT_NEAR(area, 2.0, 1e-6);
    EXPECT_NEAR(center.getX(), 1.5, 1e-6);
    EXPECT_NEAR(center.getY(), 0.5, 1e-6);
}

// Тест Pentagon (Fivesquere)
TEST(PentagonTest, InputAndArea) {
    // Правильный пятиугольник с центром в (0,0) и радиусом 1 — площадь ≈ 2.37764
    std::istringstream input(
        "1 0 "
        "0.309 0.951 "
        "-0.809 0.588 "
        "-0.809 -0.588 "
        "0.309 -0.951"
    );
    auto pent = std::make_shared<Fivesquere>();
    input >> *pent;

    double area = pent->Area();
    EXPECT_GT(area, 2.3);
    EXPECT_LT(area, 2.5);
}

// Тест Hexagon (Sixsquere)
TEST(HexagonTest, RegularHexagonArea) {
    // Правильный шестиугольник со стороной 1: площадь = (3√3)/2 ≈ 2.598
    std::istringstream input(
        "1 0 "
        "0.5 0.866 "
        "-0.5 0.866 "
        "-1 0 "
        "-0.5 -0.866 "
        "0.5 -0.866"
    );
    auto hex = std::make_shared<Sixsquere>();
    input >> *hex;

    double area = hex->Area();
    EXPECT_NEAR(area, 2.598076, 1e-5);
}

// Тест Array
TEST(ArrayTest, AddAndTotalArea) {
    Array arr;

    auto rh = std::make_shared<Rhombus>();
    std::istringstream in1("0 0 2 0 2 2 0 2"); // квадрат 2x2 → площадь = 4
    in1 >> *rh;
    arr.Add(rh);

    auto pent = std::make_shared<Fivesquere>();
    std::istringstream in2("0 0 1 0 1.309 0.951 0.5 1.538 -0.309 0.951");
    in2 >> *pent;
    arr.Add(pent);

    double total = arr.TotalArea();
    EXPECT_NEAR(total, 4.0 + pent->Area(), 1e-5);
}
