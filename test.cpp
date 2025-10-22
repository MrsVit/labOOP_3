#include <gtest/gtest.h>
#include <sstream>
#include "rhombus.h"
#include "5-square.h"
#include "6-square.h"

// Тесты для Rhombus
TEST(RhombusTest, VertexCount) {
    std::istringstream input("0 0 1 1 0 2 -1 1");
    Rhombus r(input);
    EXPECT_EQ(r.VertexesNumber(), 4);
}

TEST(RhombusTest, AreaSquareRhombus) {
    std::istringstream input("0 0 1 1 0 2 -1 1");
    Rhombus r(input);
    EXPECT_NEAR(r.Area(), 2.0, 1e-6);
}

TEST(RhombusTest, DegenerateRhombus) {
    std::istringstream input("0 0 0 0 0 0 0 0");
    Rhombus r(input);
    EXPECT_NEAR(r.Area(), 0.0, 1e-6);
}

// Тесты для Pentagon (FiveSquere)
TEST(PentagonTest, VertexCount) {
    std::istringstream input(
        "1 0 "
        "0.309 0.951 "
        "-0.809 0.588 "
        "-0.809 -0.588 "
        "0.309 -0.951"
    );
    FiveSquere p(input);
    EXPECT_EQ(p.VertexesNumber(), 5);
}

TEST(PentagonTest, AreaRegularPentagonUnitCircle) {
    std::istringstream input(
        "1 0 "
        "0.309016994 0.951056516 "
        "-0.809016994 0.587785252 "
        "-0.809016994 -0.587785252 "
        "0.309016994 -0.951056516"
    );
    FiveSquere p(input);
    EXPECT_NEAR(p.Area(), 2.37764, 1e-4);
}

// Тесты для Hexagon (SixSquere)
TEST(HexagonTest, VertexCount) {
    std::istringstream input(
        "1 0 "
        "0.5 0.866 "
        "-0.5 0.866 "
        "-1 0 "
        "-0.5 -0.866 "
        "0.5 -0.866"
    );
    SixSquere h(input);
    EXPECT_EQ(h.VertexesNumber(), 6);
}

TEST(HexagonTest, AreaRegularHexagonUnitCircle) {
    // Правильный шестиугольник в единичной окружности (3√3)/2 ≈ 2.59808
    std::istringstream input(
        "1 0 "
        "0.5 0.8660254038 "
        "-0.5 0.8660254038 "
        "-1 0 "
        "-0.5 -0.8660254038 "
        "0.5 -0.8660254038"
    );
    SixSquere h(input);
    EXPECT_NEAR(h.Area(), 2.598076211, 1e-5);
}

TEST(HexagonTest, DegenerateHexagon) {
    std::istringstream input("0 0 0 0 0 0 0 0 0 0 0 0");
    SixSquere h(input);
    EXPECT_NEAR(h.Area(), 0.0, 1e-6);
}
