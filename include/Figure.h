#ifndef FIGURE_H
#define FIGURE_H

#include "ScalarType.h"
#include "Point.h"

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual Point<T> getGeometricCenter() const = 0;

    virtual double getArea() const = 0;

    virtual void print() const = 0;

    virtual operator double() const {
        return getArea();
    }

    virtual bool operator==(const Figure &other) const = 0;
};

#endif // FIGURE_H
