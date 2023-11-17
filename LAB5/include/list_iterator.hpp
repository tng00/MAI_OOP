#pragma once
#include "../src/custom_allocator.cpp"
#include "../src/custom_allocator_2.cpp"

template <typename T>
struct Node {
    T data;
    Node *next;
    Node *prev;
    Node() : data(T()), next(nullptr), prev(nullptr) {}
    Node(const T &value) : data(value), next(nullptr), prev(nullptr) {}
};

template <typename T>
class ListIterator {
public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef value_type &reference;
    typedef value_type *pointer;
    typedef const value_type &const_reference;
    typedef const value_type *const_pointer;

    template <typename T1, typename Alloc1>
    friend class CustomList;

    ListIterator(Node<value_type> *node) : current(node) {}

    ListIterator &operator++();
    ListIterator operator++(int);
    reference operator*();
    pointer operator->();
    const_reference operator*() const;
    const_pointer operator->() const;
    bool operator==(const ListIterator &other) const;
    bool operator!=(const ListIterator &other) const;

private:
    Node<value_type> *current;
};
