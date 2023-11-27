#include "../include/pentagon.hpp"

template <typename T>
    requires std::floating_point<T>
bool Pentagon<T>::check_Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e) const {
    T side_1 = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    T side_2 = std::sqrt((c.get_x() - b.get_x()) * (c.get_x() - b.get_x()) + (c.get_y() - b.get_y()) * (c.get_y() - b.get_y()));
    T side_3 = std::sqrt((c.get_x() - d.get_x()) * (c.get_x() - d.get_x()) + (c.get_y() - d.get_y()) * (c.get_y() - d.get_y()));
    T side_4 = std::sqrt((e.get_x() - d.get_x()) * (e.get_x() - d.get_x()) + (e.get_y() - d.get_y()) * (e.get_y() - d.get_y()));
    T side_5 = std::sqrt((a.get_x() - e.get_x()) * (a.get_x() - e.get_x()) + (a.get_y() - e.get_y()) * (a.get_y() - e.get_y()));
    if (!(std::abs(side_1 - side_2) < FLT_EPSILON && std::abs(side_2 - side_3) < FLT_EPSILON && std::abs(side_3 - side_4) < FLT_EPSILON && std::abs(side_4 - side_5) < FLT_EPSILON)) {
        return false;
    }
    return true;
}

template <typename T>
    requires std::floating_point<T>
Pentagon<T>::Pentagon(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d, const Point<T> &e) {
    if (!check_Pentagon(a, b, c, d, e)) {
        throw std::logic_error("Creating a pentagon failed.");
    }
    _side = std::sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    _e = e;
}

template <typename T>
    requires std::floating_point<T>
Pentagon<T>::Pentagon(T s) {
    if (s <= 0) {
        throw std::logic_error("Side must be positive.");
    }
    _side = s;
    T radius = _side * std::sqrt(0.5 + (std::sqrt(5) / 10));
    _a = Point(radius * std::cos(0 * 2 * pi / 5), radius * std::sin(0 * 2 * pi / 5));
    _b = Point(radius * std::cos(1 * 2 * pi / 5), radius * std::sin(1 * 2 * pi / 5));
    _c = Point(radius * std::cos(2 * 2 * pi / 5), radius * std::sin(2 * 2 * pi / 5));
    _d = Point(radius * std::cos(3 * 2 * pi / 5), radius * std::sin(3 * 2 * pi / 5));
    _e = Point(radius * std::cos(4 * 2 * pi / 5), radius * std::sin(4 * 2 * pi / 5));
}

template <typename T>
    requires std::floating_point<T>
Pentagon<T>::Pentagon(const Pentagon<T> &other) {
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    _e = other._e;
    _side = other._side;
}

template <typename T>
    requires std::floating_point<T>
Pentagon<T>::Pentagon(Pentagon<T> &&other) noexcept {
    std::swap(_a, other._a);
    std::swap(_b, other._b);
    std::swap(_c, other._c);
    std::swap(_d, other._d);
    std::swap(_e, other._e);
    std::swap(_side, other._side);
}

template <typename T>
    requires std::floating_point<T>
Pentagon<T> &Pentagon<T>::operator=(const Pentagon<T> &other) {
    if (*this != other) {
        _a = other._a;
        _b = other._b;
        _c = other._c;
        _d = other._d;
        _e = other._e;
        _side = other._side;
    }

    return *this;
}

template <typename T>
    requires std::floating_point<T>
Pentagon<T> &Pentagon<T>::operator=(Pentagon<T> &&other) noexcept {
    if (*this != other) {
        _a = std::move(other._a);
        _b = std::move(other._b);
        _c = std::move(other._c);
        _d = std::move(other._d);
        _e = std::move(other._e);
        _side = std::move(other._side);
        other._side = 0.0;
    }

    return *this;
}

template <typename T>
    requires std::floating_point<T>
Point<T> Pentagon<T>::geometric_center() const {
    return Point((_a.get_x() + _b.get_x() + _c.get_x() + _d.get_x() + _e.get_x()) / 5, (_a.get_y() + _b.get_y() + _c.get_y() + _d.get_y() + _e.get_y()) / 5);
}

template <typename T>
    requires std::floating_point<T>
double Pentagon<T>::area() const {
    return (std::sqrt(5 * (5 + 2 * std::sqrt(5))) * _side * _side) / 4;
}

template <typename T>
    requires std::floating_point<T>
std::string Pentagon<T>::coordinates() const {
    return std::to_string(_a.get_x()) + " " + std::to_string(_a.get_y());
}

template <typename T>
    requires std::floating_point<T>
Pentagon<T>::operator double() const {
    return (std::sqrt(5 * (5 + 2 * std::sqrt(5))) * _side * _side) / 4;
}

template <typename T>
    requires std::floating_point<T>
const double Pentagon<T>::side() const {
    return _side;
}

template <typename T>
    requires std::floating_point<T>
bool Pentagon<T>::operator==(const Pentagon<T> &other) const {
    return _a == other._a && _b == other._b && _c == other._c && _d == other._d && _e == other._e;
}

template <typename T>
    requires std::floating_point<T>
bool Pentagon<T>::operator!=(const Pentagon<T> &other) const {
    return !(*this == other);
}

template <typename T>
    requires std::floating_point<T>
std::istream &Pentagon<T>::read(std::istream &in) {
    Point<T> a, b, c, d, e;
    in >> a >> b >> c >> d >> e;
    Pentagon<T> temp(a, b, c, d, e);
    *this = std::move(temp);
    return in;
}

template <typename T>
    requires std::floating_point<T>
std::ostream &Pentagon<T>::print(std::ostream &out) const {
    return out << std::setprecision(10) << _a << " " << _b << " " << _c << " " << _d << " " << _e;
}
