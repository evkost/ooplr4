#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <memory>
#include <vector>
#include <cmath>

template<Scalar T>
class Pentagon : public Figure<T> {
private:
    std::unique_ptr<Point<T> > p1;
    std::unique_ptr<Point<T> > p2;
    std::unique_ptr<Point<T> > p3;
    std::unique_ptr<Point<T> > p4;
    std::unique_ptr<Point<T> > p5;

public:
    Pentagon();

    Pentagon(const Point<T> &point1, const Point<T> &point2,
             const Point<T> &point3, const Point<T> &point4,
             const Point<T> &point5);

    Pentagon(const Pentagon &other);

    Pentagon &operator=(const Pentagon &other);

    bool operator==(const Figure<T> &other) const override;

    Point<T> getGeometricCenter() const override;

    double getArea() const override;

    void print() const override;
};


template<Scalar T>
Pentagon<T>::Pentagon()
    : p1(std::make_unique<Point<T> >()),
      p2(std::make_unique<Point<T> >()),
      p3(std::make_unique<Point<T> >()),
      p4(std::make_unique<Point<T> >()),
      p5(std::make_unique<Point<T> >()) {
}

template<Scalar T>
Pentagon<T>::Pentagon(const Point<T> &point1, const Point<T> &point2,
                      const Point<T> &point3, const Point<T> &point4,
                      const Point<T> &point5)
    : p1(std::make_unique<Point<T> >(point1)),
      p2(std::make_unique<Point<T> >(point2)),
      p3(std::make_unique<Point<T> >(point3)),
      p4(std::make_unique<Point<T> >(point4)),
      p5(std::make_unique<Point<T> >(point5)) {
}

template<Scalar T>
Pentagon<T>::Pentagon(const Pentagon &other)
    : p1(std::make_unique<Point<T> >(*other.p1)),
      p2(std::make_unique<Point<T> >(*other.p2)),
      p3(std::make_unique<Point<T> >(*other.p3)),
      p4(std::make_unique<Point<T> >(*other.p4)),
      p5(std::make_unique<Point<T> >(*other.p5)) {
}

template<Scalar T>
Pentagon<T> &Pentagon<T>::operator=(const Pentagon &other) {
    if (this != &other) {
        *p1 = *other.p1;
        *p2 = *other.p2;
        *p3 = *other.p3;
        *p4 = *other.p4;
        *p5 = *other.p5;
    }
    return *this;
}

template<Scalar T>
bool Pentagon<T>::operator==(const Figure<T> &other) const {
    const auto *o = dynamic_cast<const Pentagon *>(&other);
    if (!o) return false;
    return *p1 == *o->p1 && *p2 == *o->p2 && *p3 == *o->p3 &&
           *p4 == *o->p4 && *p5 == *o->p5;
}

template<Scalar T>
Point<T> Pentagon<T>::getGeometricCenter() const {
    T center_x = (p1->x + p2->x + p3->x + p4->x + p5->x) / 5;
    T center_y = (p1->y + p2->y + p3->y + p4->y + p5->y) / 5;
    return Point<T>(center_x, center_y);
}

template<Scalar T>
double Pentagon<T>::getArea() const {
    std::vector<Point<T> > vertices = {*p1, *p2, *p3, *p4, *p5};
    double area = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        area += (vertices[i].x * vertices[(i + 1) % n].y) - (vertices[(i + 1) % n].x * vertices[i].y);
    }
    return std::abs(area) / 2.0;
}

template<Scalar T>
void Pentagon<T>::print() const {
    std::cout << "Pentagon vertices:\n";
    std::cout << *p1 << "\n" << *p2 << "\n" << *p3 << "\n" << *p4 << "\n" << *p5 << "\n";
    std::cout << "Geometric Center: " << getGeometricCenter() << "\n";
    std::cout << "Area: " << getArea() << "\n\n";
}

#endif // PENTAGON_H
