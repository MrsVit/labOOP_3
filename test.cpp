#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <iostream>

#include "rhombus.h"
#include "5-square.h"      
#include "6-square.h"      
#include "array.h"

// Вспомогательная функция: создаёт фигуру из строки и возвращает сырой указатель.
// Владение передаётся вызывающему коду (в данном случае — Array).
template<typename T>
Figure* createFigure(const std::string& input) {
    auto fig = std::make_unique<T>();
    std::istringstream iss(input);
    iss >> *fig;
    return fig.release(); // передаём владение
}

// --- ТЕСТЫ ДЛЯ Rhombus ---
TEST(RhombusTest, DefaultConstructor) {
    Rhombus r;
    Point c = r.Center();
    EXPECT_DOUBLE_EQ(c.getX(), 0.0);
    EXPECT_DOUBLE_EQ(c.getY(), 0.0);
}

TEST(RhombusTest, Center) {
    Figure* r = createFigure<Rhombus>("0 0 4 0 2 3 -2 3");
    Point c = r->Center();
    EXPECT_DOUBLE_EQ(c.getX(), 1.0);
    EXPECT_DOUBLE_EQ(c.getY(), 1.5);
    delete r; // освобождаем, так как Array не участвует
}

TEST(RhombusTest, Equality) {
    Figure* r1 = createFigure<Rhombus>("0 0 2 0 1 1.732 -1 1.732");
    Figure* r2 = createFigure<Rhombus>("0 0 2 0 1 1.732 -1 1.732");
    EXPECT_TRUE(*r1 == *r2);
    delete r1;
    delete r2;
}

// --- ТЕСТЫ ДЛЯ Fivesquere ---
TEST(FivesquereTest, InputAndArea) {
    Figure* p = createFigure<Fivesquere>("0 0 2 0 3 1 2 2 0 2");
    double area = p->Area();
    EXPECT_GT(area, 0.0);
    EXPECT_NEAR(area, 5.0, 0.5);
    delete p;
}

TEST(FivesquereTest, Center) {
    Figure* p = createFigure<Fivesquere>("0 0 2 0 2 2 1 3 0 2");
    Point c = p->Center();
    EXPECT_NEAR(c.getX(), 1.0, 0.1);
    EXPECT_NEAR(c.getY(), 1.4, 0.1);
    delete p;
}

// --- ТЕСТЫ ДЛЯ Sixsquere ---
TEST(SixsquereTest, InputAndArea) {
    Figure* h = createFigure<Sixsquere>("2 0 1 1.732 -1 1.732 -2 0 -1 -1.732 1 -1.732");
    double area = h->Area();
    EXPECT_NEAR(area, 10.392, 0.1); // (3*sqrt(3)/2)*2^2 ≈ 10.392
    delete h;
}

// --- ТЕСТЫ ДЛЯ Array ---
TEST(ArrayTest, AddAndSize) {
    Array arr;
    arr.Add(createFigure<Rhombus>("0 0 1 0 0 1 -1 0"));
    arr.Add(createFigure<Fivesquere>("0 0 1 0 1 1 0 1 0.5 1.5"));
    arr.Add(createFigure<Sixsquere>("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866"));
    EXPECT_GT(arr.TotalArea(), 0.0);
    // Деструктор Array должен удалить все фигуры
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    arr.Add(createFigure<Rhombus>("0 0 2 0 0 2 -2 0")); 
    arr.Add(createFigure<Sixsquere>("1 0 0.5 0.866 -0.5 0.866 -1 0 -0.5 -0.866 0.5 -0.866"));
    double total = arr.TotalArea();
    EXPECT_NEAR(total, 6.598, 0.1);
}

TEST(ArrayTest, Remove) {
    Array arr;
    Figure* r = createFigure<Rhombus>("0 0 1 0 0 1 -1 0");
    Figure* p = createFigure<Fivesquere>("0 0 1 0 1 1 0 1 0.5 1.5");
    arr.Add(r);
    arr.Add(p);

    EXPECT_NEAR(arr.TotalArea(), r->Area() + p->Area(), 1e-6);

    arr.Remove(0); // удаляет r; Array должен вызвать delete для r
    EXPECT_NEAR(arr.TotalArea(), p->Area(), 1e-6);
    // p будет удалён деструктором Array
}

TEST(ArrayTest, RemoveOutOfRange) {
    Array arr;
    arr.Add(createFigure<Rhombus>("0 0 1 0 0 1 -1 0"));
    EXPECT_THROW(arr.Remove(5), std::out_of_range);
}

TEST(ArrayTest, PrintOutput) {
    Array arr;
    arr.Add(createFigure<Rhombus>("0 0 1 0 0 1 -1 0"));

    testing::internal::CaptureStdout();
    arr.Print(); // должен выводить в std::cout через fig->Print(std::cout)
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());
    EXPECT_NE(output.find('('), std::string::npos);
}

TEST(ArrayTest, CentersOutput) {
    Array arr;
    // Квадрат: (0,0), (2,0), (2,2), (0,2) → центр (1,1)
    arr.Add(createFigure<Rhombus>("0 0 2 0 2 2 0 2"));

    testing::internal::CaptureStdout();
    arr.Centers(); // выводит центры в std::cout
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("1"), std::string::npos);
}

TEST(ArrayTest, PolymorphicBehavior) {
    Array arr;
    arr.Add(new Rhombus());        // конструктор по умолчанию
    arr.Add(new Fivesquere());
    arr.Add(new Sixsquere());

    double total = arr.TotalArea();
    EXPECT_GE(total, 0.0);
    // Array должен корректно удалить все объекты
}