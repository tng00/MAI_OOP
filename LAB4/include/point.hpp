#pragma once
#include <cmath>
#include <concepts>
#include <iomanip>
#include <iostream>

template <typename T>
    requires std::integral<T> || std::floating_point<T>
class Point {
    T _x = 0.0;
    T _y = 0.0;

public:
    Point() = default;
    Point(T x, T y);
    Point(const Point &other);
    Point(Point &&other) noexcept;
    Point &operator=(const Point &other);
    Point &operator=(Point &&other);
    ~Point() = default;

    const T get_x() const;
    const T get_y() const;
    void set_x(T x);
    void set_y(T x);

    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

    template <typename T1>
        requires std::integral<T1> || std::floating_point<T1>
    friend std::ostream &operator<<(std::ostream &out, const Point<T1> &x);
    template <typename T1>
        requires std::integral<T1> || std::floating_point<T1>
    friend std::istream &operator>>(std::istream &in, Point<T1> &x);
};
