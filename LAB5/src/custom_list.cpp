#include "../include/custom_list.hpp"

template <typename T, typename Alloc>
CustomList<T, Alloc>::CustomList() : head(nullptr), tail(nullptr), _size(0) {}

template <typename T, typename Alloc>
CustomList<T, Alloc>::CustomList(const CustomList &other) : head(nullptr), tail(nullptr), _size(0) {
    for (const auto &element : other) {
        push_back(element);
    }
}

template <typename T, typename Alloc>
CustomList<T, Alloc> &CustomList<T, Alloc>::operator=(const CustomList &other) {
    if (this != &other) {
        clear();
        for (const auto &element : other) {
            push_back(element);
        }
    }
    return *this;
}

template <typename T, typename Alloc>
CustomList<T, Alloc>::CustomList(CustomList &&other) noexcept {
    head = other.head;
    tail = other.tail;
    _size = other._size;
    other.head = other.tail = nullptr;
    other._size = 0;
}

template <typename T, typename Alloc>
CustomList<T, Alloc> &CustomList<T, Alloc>::operator=(CustomList &&other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        tail = other.tail;
        _size = other._size;
        other.head = other.tail = nullptr;
        other._size = 0;
    }
    return *this;
}

template <typename T, typename Alloc>
CustomList<T, Alloc>::CustomList(std::initializer_list<value_type> initList) : head(nullptr), tail(nullptr), _size(0)  {
    for (const auto &element : initList) {
        push_back(element);
    }
}

template <typename T, typename Alloc>
CustomList<T, Alloc>::~CustomList() {
    clear();
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::reference CustomList<T, Alloc>::front() {
    return head->data;
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::const_reference CustomList<T, Alloc>::front() const {
    return head->data;
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::reference CustomList<T, Alloc>::back() {
    return tail->data;
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::const_reference CustomList<T, Alloc>::back() const {
    return tail->data;
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::iterator CustomList<T, Alloc>::begin() noexcept {
    return ListIterator<value_type>(head);
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::iterator CustomList<T, Alloc>::end() noexcept {
    return ListIterator<value_type>(nullptr);
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::const_iterator CustomList<T, Alloc>::begin() const noexcept {
    return ListIterator<value_type>(head);
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::const_iterator CustomList<T, Alloc>::end() const noexcept {
    return ListIterator<value_type>(nullptr);
}

template <typename T, typename Alloc>
bool CustomList<T, Alloc>::empty() const {
    return head == nullptr;
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::size_type CustomList<T, Alloc>::size() const {
    return _size;
}

template <typename T, typename Alloc>
void CustomList<T, Alloc>::clear() {
    while (!empty()) {
        pop_front();
    }
    _size = 0;
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::iterator CustomList<T, Alloc>::insert(const_iterator pos, const value_type &value) {
    if (pos == end()) {
        push_back(value);
        return iterator(tail);
    }

    Node<value_type> *current = pos.current;
    Node<value_type> *newNode = _node_allocator.allocate(1u);
    _node_allocator.construct(newNode, value);

    newNode->next = current;
    newNode->prev = current->prev;

    if (current->prev) {
        current->prev->next = newNode;
    } else {
        head = newNode;
    }

    current->prev = newNode;
    ++_size;
    return iterator(newNode);
}

template <typename T, typename Alloc>
typename CustomList<T, Alloc>::iterator CustomList<T, Alloc>::erase(const_iterator pos) {
    Node<value_type> *current = pos.current;

    if (current == nullptr) {
        return iterator(nullptr);
    }

    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    iterator nextIter(current->next);
    _node_allocator.destroy(current);
    _node_allocator.deallocate(current, 1u);
    --_size;
    return nextIter;
}

template <typename T, typename Alloc>
void CustomList<T, Alloc>::push_back(const value_type &value) {
    Node<value_type> *newNode = _node_allocator.allocate(1u);
    _node_allocator.construct(newNode, value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++_size;
}

template <typename T, typename Alloc>
template <typename... Args>
void CustomList<T, Alloc>::emplace_back(Args &&...args) {
    Node<value_type> *newNode = _node_allocator.allocate(1u);
    _node_allocator.construct(newNode, std::forward<Args>(args)...);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    ++_size;
}

template <typename T, typename Alloc>
void CustomList<T, Alloc>::pop_back() {
    if (tail) {
        Node<value_type> *prev = tail->prev;
        _node_allocator.destroy(tail);
        _node_allocator.deallocate(tail, 1u);
        tail = prev;
        if (tail) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        --_size;
    }
}

template <typename T, typename Alloc>
void CustomList<T, Alloc>::push_front(const value_type &value) {
    Node<value_type> *newNode = _node_allocator.allocate(1u);
    _node_allocator.construct(newNode, value);
    if (!head) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    ++_size;
}

template <typename T, typename Alloc>
template <typename... Args>
void CustomList<T, Alloc>::emplace_front(Args &&...args) {
    Node<value_type> *newNode = _node_allocator.allocate(1u);
    _node_allocator.construct(newNode, std::forward<Args>(args)...);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    ++_size;
}

template <typename T, typename Alloc>
void CustomList<T, Alloc>::pop_front() {
    if (head) {
        Node<value_type> *next = head->next;
        _node_allocator.destroy(head);
        _node_allocator.deallocate(head, 1u);
        head = next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        --_size;
    }
}

template <typename T, typename Alloc>
void CustomList<T, Alloc>::resize(size_type new_size) {
    while (_size < new_size) {
        push_back(value_type());
    }
    while (_size > new_size) {
        pop_back();
    }
}

template <typename T, typename Alloc>
bool CustomList<T, Alloc>::operator==(const CustomList &other) const {
    iterator it1 = begin();
    iterator it2 = other.begin();

    while (it1 != end() && it2 != other.end()) {
        if (*it1 != *it2) {
            return false;
        }
        ++it1;
        ++it2;
    }
    return it1 == end() && it2 == other.end();
}

template <typename T, typename Alloc>
bool CustomList<T, Alloc>::operator!=(const CustomList &other) const {
    return !(*this == other);
}
