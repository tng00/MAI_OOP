#include "../include/octagon.hpp"

template <typename T>
    requires std::floating_point<T>
bool Octagon<T>::check_Octagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f, const Point<T> &g, const Point<T> &h) const {
    T side_1 = std::sqrt((b.get_x() - a.get_x()) * (b.get_x() - a.get_x()) + (b.get_y() - a.get_y()) * (b.get_y() - a.get_y()));
    T side_2 = std::sqrt((c.get_x() - b.get_x()) * (c.get_x() - b.get_x()) + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()));
    T side_3 = std::sqrt((d.get_x() - c.get_x()) * (d.get_x() - c.get_x()) + (d.get_y() - c.get_y()) * (d.get_y() - c.get_y()));
    T side_4 = std::sqrt((e.get_x() - d.get_x()) * (e.get_x() - d.get_x()) + (e.get_y() - d.get_y()) * (e.get_y() - d.get_y()));
    T side_5 = std::sqrt((f.get_x() - e.get_x()) * (f.get_x() - e.get_x()) + (f.get_y() - e.get_y()) * (f.get_y() - e.get_y()));
    T side_6 = std::sqrt((g.get_x() - f.get_x()) * (g.get_x() - f.get_x()) + (g.get_y() - f.get_y()) * (g.get_y() - f.get_y()));
    T side_7 = std::sqrt((h.get_x() - g.get_x()) * (h.get_x() - g.get_x()) + (h.get_y() - g.get_y()) * (h.get_y() - g.get_y()));
    T side_8 = std::sqrt((a.get_x() - h.get_x()) * (a.get_x() - h.get_x()) + (a.get_y() - h.get_y()) * (a.get_y() - h.get_y()));
    if (!(std::abs(side_1 - side_2) < FLT_EPSILON && std::abs(side_2 - side_3) < FLT_EPSILON && std::abs(side_3 - side_4) < FLT_EPSILON && std::abs(side_4 - side_5) < FLT_EPSILON && std::abs(side_5 - side_6) < FLT_EPSILON && std::abs(side_6 - side_7) < FLT_EPSILON && std::abs(side_7 - side_8) < FLT_EPSILON)) {
        return false;
    }
    return true;
}

template <typename T>
    requires std::floating_point<T>
Octagon<T>::Octagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e, const Point<T> &f, const Point<T> &g, const Point<T> &h) {
    if (!check_Octagon(a, b, c, d, e, f, g, h)) {
        throw std::logic_error("Creating a octagon failed.");
    }
    _side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    _e = e;
    _f = f;
    _g = g;
    _h = h;
}

template <typename T>
    requires std::floating_point<T>
Octagon<T>::Octagon(T s) {
    if (s <= 0) {
        throw std::logic_error("Side must be positive.");
    }
    _side = s;
    T radius = _side * std::sqrt((1 + std::sqrt(2)) / std::sqrt(2));
    _a = Point(radius * std::cos(0 * 2 * pi / 8), radius * std::sin(0 * 2 * pi / 8));
    _b = Point(radius * std::cos(1 * 2 * pi / 8), radius * std::sin(1 * 2 * pi / 8));
    _c = Point(radius * std::cos(2 * 2 * pi / 8), radius * std::sin(2 * 2 * pi / 8));
    _d = Point(radius * std::cos(3 * 2 * pi / 8), radius * std::sin(3 * 2 * pi / 8));
    _e = Point(radius * std::cos(4 * 2 * pi / 8), radius * std::sin(4 * 2 * pi / 8));
    _f = Point(radius * std::cos(5 * 2 * pi / 8), radius * std::sin(5 * 2 * pi / 8));
    _g = Point(radius * std::cos(6 * 2 * pi / 8), radius * std::sin(6 * 2 * pi / 8));
    _h = Point(radius * std::cos(7 * 2 * pi / 8), radius * std::sin(7 * 2 * pi / 8));
}

template <typename T>
    requires std::floating_point<T>
Octagon<T>::Octagon(const Octagon<T> &other) {
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    _e = other._e;
    _f = other._f;
    _g = other._g;
    _h = other._h;
    _side = other._side;
}

template <typename T>
    requires std::floating_point<T>
Octagon<T>::Octagon(Octagon<T> &&other) noexcept {
    std::swap(_a, other._a);
    std::swap(_b, other._b);
    std::swap(_c, other._c);
    std::swap(_d, other._d);
    std::swap(_e, other._e);
    std::swap(_f, other._f);
    std::swap(_g, other._g);
    std::swap(_h, other._h);
    std::swap(_side, other._side);
}

template <typename T>
    requires std::floating_point<T>
Octagon<T> &Octagon<T>::operator=(const Octagon<T> &other) {
    if (*this != other) {
        _a = other._a;
        _b = other._b;
        _c = other._c;
        _d = other._d;
        _e = other._e;
        _f = other._f;
        _g = other._g;
        _h = other._h;
        _side = other._side;
    }

    return *this;
}

template <typename T>
    requires std::floating_point<T>
Octagon<T> &Octagon<T>::operator=(Octagon<T> &&other) noexcept {
    if (*this != other) {
        _a = std::move(other._a);
        _b = std::move(other._b);
        _c = std::move(other._c);
        _d = std::move(other._d);
        _e = std::move(other._e);
        _f = std::move(other._f);
        _g = std::move(other._g);
        _h = std::move(other._h);
        _side = std::move(other._side);
        other._side = 0.0;
    }

    return *this;
}

template <typename T>
    requires std::floating_point<T>
Point<T> Octagon<T>::geometric_center() const {
    return Point((_a.get_x() + _b.get_x() + _c.get_x() + _d.get_x() + _e.get_x() + _f.get_x() + _g.get_x() + _h.get_x()) / 8, (_a.get_y() + _b.get_y() + _c.get_y() + _d.get_y() + _e.get_y() + _f.get_x() + _g.get_y() + _h.get_x()) / 8);
}

template <typename T>
    requires std::floating_point<T>
double Octagon<T>::area() const {
    return 2 * _side * _side * (1 + sqrt(2));
}

template <typename T>
    requires std::floating_point<T>
std::string Octagon<T>::coordinates() const {
    return std::to_string(_a.get_x()) + " " + std::to_string(_a.get_y());
}

template <typename T>
    requires std::floating_point<T>
Octagon<T>::operator double() const {
    return 2 * _side * _side * (1 + sqrt(2));
}

template <typename T>
    requires std::floating_point<T>
const double Octagon<T>::side() const {
    return _side;
}

template <typename T>
    requires std::floating_point<T>
bool Octagon<T>::operator==(const Octagon<T> &other) const {
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d && _e == other._e && _f == other._f && _g == other._g && _h == other._h;
}

template <typename T>
    requires std::floating_point<T>
bool Octagon<T>::operator!=(const Octagon<T> &other) const {
    return !(*this == other);
}

template <typename T>
    requires std::floating_point<T>
std::istream &Octagon<T>::read(std::istream &in) {
    Point<T> a, b, c, d, e, f, g, h;
    in >> a >> b >> c >> d >> e >> f >> g >> h;
    Octagon<T> temp(a, b, c, d, e, f, g, h);
    *this = std::move(temp);
    return in;
}

template <typename T>
    requires std::floating_point<T>
std::ostream &Octagon<T>::print(std::ostream &out) const {
    return out << std::setprecision(10) << _a << " " << _b << " " << _c << " " << _d << " " << _e << " " << _f << " " << _g << " " << _h;
}
