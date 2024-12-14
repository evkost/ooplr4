#include <gtest/gtest.h>
#include "Array.h"
#include "Trapezoid.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Point.h"

TEST(PointTest, DefaultConstructor) {
    Point<int> p;
    EXPECT_EQ(p.x, 0);
    EXPECT_EQ(p.y, 0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point p(1.5, 2.5);
    EXPECT_DOUBLE_EQ(p.x, 1.5);
    EXPECT_DOUBLE_EQ(p.y, 2.5);
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid t(
        Point(0, 0),
        Point(4, 0),
        Point(3, 3),
        Point(1, 3)
    );
    EXPECT_DOUBLE_EQ(t.getArea(), 9.0);
}

TEST(RhombusTest, GeometricCenterCalculation) {
    Rhombus r(
        Point(0, 0),
        Point(2, 1),
        Point(0, 2),
        Point(-2, 1)
    );
    Point center = r.getGeometricCenter();
    EXPECT_DOUBLE_EQ(center.x, 0.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon p(
        Point(0, 0),
        Point(2, 0),
        Point(2, 2),
        Point(1, 3),
        Point(0, 2)
    );
    EXPECT_DOUBLE_EQ(p.getArea(), 5.0);
}

TEST(PentagonTest, GeometricCenterCalculation) {
    Pentagon pentagon(
        Point(0.0, 0.0),
        Point(2.0, 0.0),
        Point(2.0, 2.0),
        Point(1.0, 3.0),
        Point(0.0, 2.0)
    );
    Point center = pentagon.getGeometricCenter();
    EXPECT_NEAR(center.y, 1.4, 1e-9);
}

TEST(ArrayTest, AddAndRemoveElements) {
    Array<Figure<int> > arr;

    auto trapezoid = std::make_shared<Trapezoid<int> >(
        Point(0, 0),
        Point(4, 0),
        Point(3, 3),
        Point(1, 3)
    );
    arr.addElement(trapezoid);
    EXPECT_EQ(arr.size(), 1);

    auto rhombus = std::make_shared<Rhombus<int> >(
        Point(0, 0),
        Point(2, 1),
        Point(0, 2),
        Point(-2, 1)
    );
    arr.addElement(rhombus);
    EXPECT_EQ(arr.size(), 2);

    auto pentagon = std::make_shared<Pentagon<int> >(
        Point(0, 0),
        Point(2, 0),
        Point(2, 2),
        Point(1, 3),
        Point(0, 2)
    );
    arr.addElement(pentagon);
    EXPECT_EQ(arr.size(), 3);

    arr.removeElement(1);
    EXPECT_EQ(arr.size(), 2);

    arr.removeElement(0);
    EXPECT_EQ(arr.size(), 1);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array<Figure<int> > arr;

    auto trapezoid = std::make_shared<Trapezoid<int> >(
        Point(0, 0),
        Point(4, 0),
        Point(3, 3),
        Point(1, 3)
    );
    arr.addElement(trapezoid);

    auto rhombus = std::make_shared<Rhombus<int> >(
        Point(0, 0),
        Point(2, 1),
        Point(0, 2),
        Point(-2, 1)
    );
    arr.addElement(rhombus);

    auto pentagon = std::make_shared<Pentagon<int> >(
        Point(0, 0),
        Point(2, 0),
        Point(2, 2),
        Point(1, 3),
        Point(0, 2)
    );
    arr.addElement(pentagon);

    EXPECT_DOUBLE_EQ(arr.totalArea(), 18.0);
}
