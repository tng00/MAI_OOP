#include "../include/hexagon.hpp"

template <typename T>
    requires std::floating_point<T>
bool Hexagon<T>::check_Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f) const {
    T side_1 = std::sqrt((b.get_x() - a.get_x()) * (b.get_x() - a.get_x()) + (b.get_y() - a.get_y()) * (b.get_y() - a.get_y()));
    T side_2 = std::sqrt((c.get_x() - b.get_x()) * (c.get_x() - b.get_x()) + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()));
    T side_3 = std::sqrt((d.get_x() - c.get_x()) * (d.get_x() - c.get_x()) + (d.get_y() - c.get_y()) * (d.get_y() - c.get_y()));
    T side_4 = std::sqrt((e.get_x() - d.get_x()) * (e.get_x() - d.get_x()) + (e.get_y() - d.get_y()) * (e.get_y() - d.get_y()));
    T side_5 = std::sqrt((f.get_x() - e.get_x()) * (f.get_x() - e.get_x()) + (f.get_y() - e.get_y()) * (f.get_y() - e.get_y()));
    T side_6 = std::sqrt((a.get_x() - f.get_x()) * (a.get_x() - f.get_x()) + (a.get_y() - f.get_y()) * (a.get_y() - f.get_y()));
    if (!(std::abs(side_1 - side_2) < FLT_EPSILON && std::abs(side_2 - side_3) < FLT_EPSILON && std::abs(side_3 - side_4) < FLT_EPSILON && std::abs(side_4 - side_5) < FLT_EPSILON && std::abs(side_5 - side_6) < FLT_EPSILON)) {
        return false;
    }
    return true;
}

template <typename T>
    requires std::floating_point<T>
Hexagon<T>::Hexagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f) {
    if (!check_Hexagon(a, b, c, d, e, f)) {
        throw std::logic_error("Creating a hexagon failed.");
    }
    _side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    _e = e;
    _f = f;
}

template <typename T>
    requires std::floating_point<T>
Hexagon<T>::Hexagon(T s) {
    if (s <= 0) {
        throw std::logic_error("Side must be positive.");
    }
    _side = s;
    T radius = s;
    _a = Point(radius * std::cos(0 * 2 * pi / 6), radius * std::sin(0 * 2 * pi / 6));
    _b = Point(radius * std::cos(1 * 2 * pi / 6), radius * std::sin(1 * 2 * pi / 6));
    _c = Point(radius * std::cos(2 * 2 * pi / 6), radius * std::sin(2 * 2 * pi / 6));
    _d = Point(radius * std::cos(3 * 2 * pi / 6), radius * std::sin(3 * 2 * pi / 6));
    _e = Point(radius * std::cos(4 * 2 * pi / 6), radius * std::sin(4 * 2 * pi / 6));
    _f = Point(radius * std::cos(5 * 2 * pi / 6), radius * std::sin(5 * 2 * pi / 6));
}

template <typename T>
    requires std::floating_point<T>
Hexagon<T>::Hexagon(const Hexagon<T> &other) {
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    _e = other._e;
    _f = other._f;
    _side = other._side;
}

template <typename T>
    requires std::floating_point<T>
Hexagon<T>::Hexagon(Hexagon<T> &&other) noexcept {
    std::swap(_a, other._a);
    std::swap(_b, other._b);
    std::swap(_c, other._c);
    std::swap(_d, other._d);
    std::swap(_e, other._e);
    std::swap(_f, other._f);
    std::swap(_side, other._side);
}

template <typename T>
    requires std::floating_point<T>
Hexagon<T> &Hexagon<T>::operator=(const Hexagon<T> &other) {
    if (*this != other) {
        _a = other._a;
        _b = other._b;
        _c = other._c;
        _d = other._d;
        _e = other._e;
        _f = other._f;
        _side = other._side;
    }

    return *this;
}

template <typename T>
    requires std::floating_point<T>
Hexagon<T> &Hexagon<T>::operator=(Hexagon<T> &&other) noexcept {
    if (*this != other) {
        _a = std::move(other._a);
        _b = std::move(other._b);
        _c = std::move(other._c);
        _d = std::move(other._d);
        _e = std::move(other._e);
        _f = std::move(other._f);
        _side = std::move(other._side);
        other._side = 0.0;
    }

    return *this;
}

template <typename T>
    requires std::floating_point<T>
Point<T> Hexagon<T>::geometric_center() const {
    return Point((_a.get_x() + _b.get_x() + _c.get_x() + _d.get_x() + _e.get_x() + _f.get_x()) / 6, (_a.get_y() + _b.get_y() + _c.get_y() + _d.get_y() + _e.get_y() + _f.get_y()) / 6);
}

template <typename T>
    requires std::floating_point<T>
double Hexagon<T>::area() const {
    return 6 * _side * _side * sqrt(3) / 4;
}

template <typename T>
    requires std::floating_point<T>
std::string Hexagon<T>::coordinates() const {
    return std::to_string(_a.get_x()) + " " + std::to_string(_a.get_y());
}

template <typename T>
    requires std::floating_point<T>
Hexagon<T>::operator double() const {
    return 6 * _side * _side * sqrt(3) / 4;
}

template <typename T>
    requires std::floating_point<T>
const double Hexagon<T>::side() const {
    return _side;
}

template <typename T>
    requires std::floating_point<T>
bool Hexagon<T>::operator==(const Hexagon<T> &other) const {
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d && _e == other._e && _f == other._f;
}

template <typename T>
    requires std::floating_point<T>
bool Hexagon<T>::operator!=(const Hexagon<T> &other) const {
    return !(*this == other);
}

template <typename T>
    requires std::floating_point<T>
std::istream &Hexagon<T>::read(std::istream &in) {
    Point<T> a, b, c, d, e, f;
    in >> a >> b >> c >> d >> e >> f;
    Hexagon<T> temp(a, b, c, d, e, f);
    *this = std::move(temp);
    return in;
}

template <typename T>
    requires std::floating_point<T>
std::ostream &Hexagon<T>::print(std::ostream &out) const {
    return out << std::setprecision(10) << _a << " " << _b << " " << _c << " " << _d << " " << _e << " " << _f;
}
