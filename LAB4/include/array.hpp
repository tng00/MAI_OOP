#pragma once
#include <iostream>
#include <limits>
#include <memory>

template <typename T>
class Array {
public:
    Array() = default;
    Array(size_t count, const T &value = T());
    Array(const Array &other);
    Array(Array &&other) noexcept;
    Array &operator=(const Array &other);
    Array &operator=(Array &&other) noexcept;
    Array(const std::initializer_list<T> &init);
    ~Array();

    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;

    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t capacity() const;

    void reserve(size_t new_cap);
    void clear();

    void push_back(const T &item);
    void pop_back();
    void resize(size_t count);
    void resize(size_t count, const T &value);
    void erase(size_t pos);

    template <typename T1>
    friend bool operator==(const Array<T1> &lhs, const Array<T1> &rhs);
    template <typename T1>
    friend bool operator!=(const Array<T1> &lhs, const Array<T1> &rhs);

private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    std::shared_ptr<T[]> data_ = nullptr;
    void reallocate(size_t minSize);
};
