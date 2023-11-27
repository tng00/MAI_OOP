#pragma once
#include <float.h>

#include "../src/point.cpp"

const double pi = M_PI;

template <typename T>
class Figure {
protected:
    Figure() = default;

public:
    virtual ~Figure() = default;
    virtual Point<T> geometric_center() const = 0;
    virtual double area() const = 0;
    virtual std::string coordinates() const = 0;
    virtual operator double() const = 0;
    virtual const double side() const = 0;

    virtual std::ostream& print(std::ostream& out) const = 0;
    virtual std::istream& read(std::istream& in) = 0;
};

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Figure<T>& figure) {
    return figure.print(out);
}

template <typename T>
inline std::istream& operator>>(std::istream& in, Figure<T>& figure) {
    return figure.read(in);
}
