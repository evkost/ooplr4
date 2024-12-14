#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <memory>
#include <vector>
#include <cmath>

template<Scalar T>
class Trapezoid : public Figure<T> {
private:
    std::unique_ptr<Point<T> > p1;
    std::unique_ptr<Point<T> > p2;
    std::unique_ptr<Point<T> > p3;
    std::unique_ptr<Point<T> > p4;

public:
    Trapezoid();

    Trapezoid(const Point<T> &point1, const Point<T> &point2,
              const Point<T> &point3, const Point<T> &point4);

    Trapezoid(const Trapezoid &other);

    Trapezoid &operator=(const Trapezoid &other);

    bool operator==(const Figure<T> &other) const override;

    Point<T> getGeometricCenter() const override;

    double getArea() const override;

    void print() const override;
};


template<Scalar T>
Trapezoid<T>::Trapezoid()
    : p1(std::make_unique<Point<T> >()),
      p2(std::make_unique<Point<T> >()),
      p3(std::make_unique<Point<T> >()),
      p4(std::make_unique<Point<T> >()) {
}

template<Scalar T>
Trapezoid<T>::Trapezoid(const Point<T> &point1, const Point<T> &point2,
                        const Point<T> &point3, const Point<T> &point4)
    : p1(std::make_unique<Point<T> >(point1)),
      p2(std::make_unique<Point<T> >(point2)),
      p3(std::make_unique<Point<T> >(point3)),
      p4(std::make_unique<Point<T> >(point4)) {
}

template<Scalar T>
Trapezoid<T>::Trapezoid(const Trapezoid &other)
    : p1(std::make_unique<Point<T> >(*other.p1)),
      p2(std::make_unique<Point<T> >(*other.p2)),
      p3(std::make_unique<Point<T> >(*other.p3)),
      p4(std::make_unique<Point<T> >(*other.p4)) {
}

template<Scalar T>
Trapezoid<T> &Trapezoid<T>::operator=(const Trapezoid &other) {
    if (this != &other) {
        *p1 = *other.p1;
        *p2 = *other.p2;
        *p3 = *other.p3;
        *p4 = *other.p4;
    }
    return *this;
}

template<Scalar T>
bool Trapezoid<T>::operator==(const Figure<T> &other) const {
    const auto *o = dynamic_cast<const Trapezoid *>(&other);
    if (!o) return false;
    return *p1 == *o->p1 && *p2 == *o->p2 && *p3 == *o->p3 && *p4 == *o->p4;
}

template<Scalar T>
Point<T> Trapezoid<T>::getGeometricCenter() const {
    T center_x = (p1->x + p2->x + p3->x + p4->x) / 4;
    T center_y = (p1->y + p2->y + p3->y + p4->y) / 4;
    return Point<T>(center_x, center_y);
}

template<Scalar T>
double Trapezoid<T>::getArea() const {
    std::vector<Point<T> > vertices = {*p1, *p2, *p3, *p4};
    double area = 0.0;
    size_t n = vertices.size();
    for (size_t i = 0; i < n; ++i) {
        area += (vertices[i].x * vertices[(i + 1) % n].y) - (vertices[(i + 1) % n].x * vertices[i].y);
    }
    return std::abs(area) / 2.0;
}

template<Scalar T>
void Trapezoid<T>::print() const {
    std::cout << "Trapezoid vertices:\n";
    std::cout << *p1 << "\n" << *p2 << "\n" << *p3 << "\n" << *p4 << "\n";
    std::cout << "Geometric Center: " << getGeometricCenter() << "\n";
    std::cout << "Area: " << getArea() << "\n\n";
}

#endif // TRAPEZOID_H
