#pragma once
#include <iomanip>
#include <string>

#include "figure.hpp"

template <typename T>
    requires std::floating_point<T>
class Pentagon final : public Figure<T> {
    Point<T> _a;
    Point<T> _b;
    Point<T> _c;
    Point<T> _d;
    Point<T> _e;
    T _side = 0.0;

public:
    Pentagon() = default;
    Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e);
    Pentagon(T s);
    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;
    ~Pentagon() = default;

    virtual Point<T> geometric_center() const override;
    virtual double area() const override;
    virtual std::string coordinates() const override;
    virtual operator double() const override;
    virtual const double side() const override;

    bool operator==(const Pentagon &other) const;
    bool operator!=(const Pentagon &other) const;

    std::istream &read(std::istream &in) override;
    std::ostream &print(std::ostream &out) const override;

private:
    bool check_Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e) const;
};
