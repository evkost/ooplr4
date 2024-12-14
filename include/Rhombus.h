#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <memory>
#include <cmath>

template<Scalar T>
class Rhombus : public Figure<T> {
private:
    std::unique_ptr<Point<T> > p1;
    std::unique_ptr<Point<T> > p2;
    std::unique_ptr<Point<T> > p3;
    std::unique_ptr<Point<T> > p4;

public:
    Rhombus();

    Rhombus(const Point<T> &point1, const Point<T> &point2,
            const Point<T> &point3, const Point<T> &point4);

    Rhombus(const Rhombus &other);

    Rhombus &operator=(const Rhombus &other);

    bool operator==(const Figure<T> &other) const override;

    Point<T> getGeometricCenter() const override;

    double getArea() const override;

    void print() const override;
};


template<Scalar T>
Rhombus<T>::Rhombus()
    : p1(std::make_unique<Point<T> >()),
      p2(std::make_unique<Point<T> >()),
      p3(std::make_unique<Point<T> >()),
      p4(std::make_unique<Point<T> >()) {
}

template<Scalar T>
Rhombus<T>::Rhombus(const Point<T> &point1, const Point<T> &point2,
                    const Point<T> &point3, const Point<T> &point4)
    : p1(std::make_unique<Point<T> >(point1)),
      p2(std::make_unique<Point<T> >(point2)),
      p3(std::make_unique<Point<T> >(point3)),
      p4(std::make_unique<Point<T> >(point4)) {
}

template<Scalar T>
Rhombus<T>::Rhombus(const Rhombus &other)
    : p1(std::make_unique<Point<T> >(*other.p1)),
      p2(std::make_unique<Point<T> >(*other.p2)),
      p3(std::make_unique<Point<T> >(*other.p3)),
      p4(std::make_unique<Point<T> >(*other.p4)) {
}

template<Scalar T>
Rhombus<T> &Rhombus<T>::operator=(const Rhombus &other) {
    if (this != &other) {
        *p1 = *other.p1;
        *p2 = *other.p2;
        *p3 = *other.p3;
        *p4 = *other.p4;
    }
    return *this;
}

template<Scalar T>
bool Rhombus<T>::operator==(const Figure<T> &other) const {
    const auto *o = dynamic_cast<const Rhombus *>(&other);
    if (!o) return false;
    return *p1 == *o->p1 && *p2 == *o->p2 && *p3 == *o->p3 && *p4 == *o->p4;
}


template<Scalar T>
Point<T> Rhombus<T>::getGeometricCenter() const {
    T center_x = (p1->x + p2->x + p3->x + p4->x) / 4;
    T center_y = (p1->y + p2->y + p3->y + p4->y) / 4;
    return Point<T>(center_x, center_y);
}

template<Scalar T>
double Rhombus<T>::getArea() const {
    double d1 = std::sqrt(std::pow(p3->x - p1->x, 2) + std::pow(p3->y - p1->y, 2));
    double d2 = std::sqrt(std::pow(p4->x - p2->x, 2) + std::pow(p4->y - p2->y, 2));
    return (d1 * d2) / 2.0;
}

template<Scalar T>
void Rhombus<T>::print() const {
    std::cout << "Rhombus vertices:\n";
    std::cout << *p1 << "\n" << *p2 << "\n" << *p3 << "\n" << *p4 << "\n";
    std::cout << "Geometric Center: " << getGeometricCenter() << "\n";
    std::cout << "Area: " << getArea() << "\n\n";
}

#endif // RHOMBUS_H
