#pragma once
#include <iomanip>

#include "figure.hpp"

template <typename T>
    requires std::floating_point<T>
class Octagon final : public Figure<T> {
private:
    Point<T> _a;
    Point<T> _b;
    Point<T> _c;
    Point<T> _d;
    Point<T> _e;
    Point<T> _f;
    Point<T> _g;
    Point<T> _h;
    T _side = 0.0;

public:
    Octagon() = default;
    Octagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f, const Point<T> &g, const Point<T> &h);
    Octagon(T s);
    Octagon(const Octagon &other);
    Octagon(Octagon &&other) noexcept;
    Octagon &operator=(const Octagon &other);
    Octagon &operator=(Octagon &&other) noexcept;
    ~Octagon() = default;

    virtual Point<T> geometric_center() const override;
    virtual double area() const override;
    virtual std::string coordinates() const override;
    virtual operator double() const override;
    virtual const double side() const override;

    bool operator==(const Octagon &other) const;
    bool operator!=(const Octagon &other) const;

    std::istream &read(std::istream &in) override;
    std::ostream &print(std::ostream &out) const override;

private:
    bool check_Octagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f, const Point<T> &g, const Point<T> &h) const;
};
