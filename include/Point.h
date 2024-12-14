#ifndef POINT_H
#define POINT_H

#include "ScalarType.h"

template <Scalar T>
struct Point {
    T x;
    T y;

    Point() : x(0), y(0) {}
    Point(T x_val, T y_val) : x(x_val), y(y_val) {}

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    friend std::istream& operator>>(std::istream& is, Point& point) {
        is >> point.x >> point.y;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& point) {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }
};

#endif // POINT_H
