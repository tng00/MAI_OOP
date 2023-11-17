#pragma once
#include "../include/list_iterator.hpp"

template <typename T>
typename ListIterator<T>::ListIterator &ListIterator<T>::operator++() {
    current = current->next;
    return *this;
}

template <typename T>
typename ListIterator<T>::ListIterator ListIterator<T>::operator++(int) {
    ListIterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename ListIterator<T>::reference ListIterator<T>::operator*() {
    return current->data;
}

template <typename T>
typename ListIterator<T>::pointer ListIterator<T>::operator->() {
    return &current->data;
}

template <typename T>
typename ListIterator<T>::const_reference ListIterator<T>::operator*() const {
    return current->data;
}

template <typename T>
typename ListIterator<T>::const_pointer ListIterator<T>::operator->() const {
    return &current->data;
}

template <typename T>
bool ListIterator<T>::operator==(const ListIterator &other) const {
    return current == other.current;
}

template <typename T>
bool ListIterator<T>::operator!=(const ListIterator &other) const {
    return !(*this == other);
}
