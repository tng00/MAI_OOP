#pragma once
#include <iomanip>

#include "figure.hpp"

template <typename T>
    requires std::floating_point<T>
class Hexagon final : public Figure<T> {
private:
    Point<T> _a;
    Point<T> _b;
    Point<T> _c;
    Point<T> _d;
    Point<T> _e;
    Point<T> _f;
    T _side = 0.0;

public:
    Hexagon() = default;
    Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f);
    Hexagon(T s);
    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;
    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;
    ~Hexagon() = default;

    virtual Point<T> geometric_center() const override;
    virtual double area() const override;
    virtual std::string coordinates() const override;
    virtual operator double() const override;
    virtual const double side() const override;

    bool operator==(const Hexagon &other) const;
    bool operator!=(const Hexagon &other) const;

    std::istream &read(std::istream &in) override;
    std::ostream &print(std::ostream &out) const override;

private:
    bool check_Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f) const;
};
