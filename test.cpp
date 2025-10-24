#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include <stdexcept>

#include "rhombus.h"
#include "5-square.h"      // Fivesquere
#include "6-square.h"      // Sixsquere
#include "array.h"

// Вспомогательная функция для создания фигуры из строки
template<typename T>
std::shared_ptr<T> makeFigure(const std::string& input) {
    auto fig = std::make_shared<T>();
    std::istringstream iss(input);
    iss >> *fig;  // вызывает operator>> -> fig->Read()
    return fig;
}

// --- ТЕСТЫ ДЛЯ Rhombus ---
TEST(RhombusTest, DefaultConstructor) {
    Rhombus r;
    auto c = r.Center();
    EXPECT_DOUBLE_EQ(c.getX(), 0.0);
    EXPECT_DOUBLE_EQ(c.getY(), 0.0);
}

TEST(RhombusTest, Center) {
    auto r = makeFigure<Rhombus>("0 0 4 0 2 3 -2 3");
    Point c = r->Center();
    EXPECT_DOUBLE_EQ(c.getX(), 1.0);
    EXPECT_DOUBLE_EQ(c.getY(), 1.5);
}

TEST(RhombusTest, Equality) {
    auto r1 = makeFigure<Rhombus>("0 0 2 0 1 1.732 -1 1.732");
    auto r2 = makeFigure<Rhombus>("0 0 2 0 1 1.732 -1 1.732");
    EXPECT_TRUE(*r1 == *r2);
}

// --- ТЕСТЫ ДЛЯ Fivesquere ---
TEST(FivesquereTest, InputAndArea) {
    // Простой выпуклый пятиугольник
    auto p = makeFigure<Fivesquere>("0 0 2 0 3 1 2 2 0 2");
    double area = p->Area();
    EXPECT_GT(area, 0.0);
    EXPECT_NEAR(area, 5.0, 0.5); // приблизительно
}

TEST(FivesquereTest, Center) {
    auto p = makeFigure<Fivesquere>("0 0 2 0 2 2 1 3 0 2");
    Point c = p->Center();
    EXPECT_NEAR(c.getX(), 1.0, 0.1);
    EXPECT_NEAR(c.getY(), 1.4, 0.1);
}

// --- ТЕСТЫ ДЛЯ Sixsquere ---
TEST(SixsquereTest, InputAndArea) {
    // Правильный шестиугольник (приблизительно)
    auto h = makeFigure<Sixsquere>("2 0 1 1.732 -1 1.732 -2 0 -1 -1.732 1 -1.732");
    double area = h->Area();
    EXPECT_NEAR(area, 10.392, 0.1); // (3*sqrt(3)/2)*2^2 ≈ 10.392
}

// --- ТЕСТЫ ДЛЯ Array ---
TEST(ArrayTest, AddAndSize) {
    Array arr;
    arr.Add(makeFigure<Rhombus>("0 0 1 0 0 1 -1 0"));
    arr.Add(makeFigure<Fivesquere>("0 0 1 0 1 1 0 1 0.5 1.5"));
    arr.Add(makeFigure<Sixsquere>("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866"));
    // Нет метода Size(), но можно проверить через TotalArea и побочные эффекты
    // Лучше добавить Size() в Array, но раз его нет — проверим через TotalArea > 0
    EXPECT_GT(arr.TotalArea(), 0.0);
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    arr.Add(makeFigure<Rhombus>("0 0 2 0 0 2 -2 0")); // площадь = 4
    arr.Add(makeFigure<Sixsquere>("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866")); // ≈2.598
    double total = arr.TotalArea();
    EXPECT_NEAR(total, 6.598, 0.1);
}

TEST(ArrayTest, Remove) {
    Array arr;
    auto r = makeFigure<Rhombus>("0 0 1 0 0 1 -1 0");
    auto p = makeFigure<Fivesquere>("0 0 1 0 1 1 0 1 0.5 1.5");
    arr.Add(r);
    arr.Add(p);

    EXPECT_NEAR(arr.TotalArea(), r->Area() + p->Area(), 1e-6);

    arr.Remove(0);
    EXPECT_NEAR(arr.TotalArea(), p->Area(), 1e-6);
}

TEST(ArrayTest, RemoveOutOfRange) {
    Array arr;
    arr.Add(makeFigure<Rhombus>("0 0 1 0 0 1 -1 0"));
    EXPECT_THROW(arr.Remove(5), std::out_of_range);
}

TEST(ArrayTest, PrintOutput) {
    Array arr;
    arr.Add(makeFigure<Rhombus>("0 0 1 0 0 1 -1 0"));

    testing::internal::CaptureStdout();
    arr.Print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(output.find('(') != std::string::npos);
}

TEST(ArrayTest, CentersOutput) {
    Array arr;
    arr.Add(makeFigure<Rhombus>("0 0 2 0 2 2 0 2")); // квадрат → центр (1,1)

    testing::internal::CaptureStdout();
    arr.Centers();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("1") != std::string::npos); // x=1
    EXPECT_TRUE(output.find("1") != std::string::npos); // y=1
}

// --- ПОЛИМОРФИЗМ ---
TEST(ArrayTest, PolymorphicBehavior) {
    Array arr;
    arr.Add(std::make_shared<Rhombus>());
    arr.Add(std::make_shared<Fivesquere>());
    arr.Add(std::make_shared<Sixsquere>());

    // Проверим, что Area() вызывается виртуально
    double total = arr.TotalArea();
    EXPECT_GE(total, 0.0);
}