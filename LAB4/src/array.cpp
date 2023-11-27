#include "../include/array.hpp"

template <class T>
Array<T>::Array(size_t count, const T &value) : size_(count) {
    capacity_ = size_ * 2;
    data_ = std::shared_ptr<T[]>(new T[capacity_]);
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = value;
    }
}

template <class T>
Array<T>::Array(const Array &other) {
    size_ = other.size();
    capacity_ = other.capacity();
    data_ = std::shared_ptr<T[]>(new T[capacity_]);
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template <class T>
Array<T>::Array(Array &&other) noexcept {
    size_ = other.size();
    capacity_ = other.capacity();
    data_ = other.data_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other) {
    if (*this == other) {
        return *this;
    }
    clear();
    reallocate(other.capacity());
    size_ = other.size();
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
    return *this;
}

template <class T>
Array<T> &Array<T>::operator=(Array &&other) noexcept {
    if (*this == other) {
        return *this;
    }
    size_ = other.size();
    capacity_ = other.capacity();
    data_ = other.data_;
    other.size_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
    return *this;
}

template <class T>
Array<T>::Array(const std::initializer_list<T> &init) {
    size_ = init.size();
    capacity_ = size_ * 2;
    data_ = std::shared_ptr<T[]>(new T[capacity_]);
    std::copy(init.begin(), init.end(), data_.get());
}

template <class T>
Array<T>::~Array() {
    if (data_) {
        for (size_t i = 0; i < size_; ++i) {
            data_[i].~T();
        }
    }
    size_ = 0;
}

template <class T>
T &Array<T>::operator[](size_t pos) {
    if (pos >= size_) {
        throw std::out_of_range("Out of range.");
    }
    return data_[pos];
}

template <class T>
const T &Array<T>::operator[](size_t pos) const {
    if (pos >= size_) {
        throw std::out_of_range("Out of range.");
    }
    return data_[pos];
}

template <class T>
bool Array<T>::empty() const {
    return size_ == 0;
}

template <class T>
size_t Array<T>::size() const {
    return size_;
}

template <class T>
size_t Array<T>::capacity() const {
    return capacity_;
}

template <class T>
void Array<T>::reserve(size_t new_cap) {
    if (new_cap > capacity_) {
        reallocate(new_cap);
    }
}

template <class T>
void Array<T>::clear() {
    for (size_t i = 0; i < size_; i++) {
        data_[i].~T();
    }
    size_ = 0;
}

template <class T>
void Array<T>::push_back(const T &item) {
    if (capacity_ == 0) {
        reserve(1);
    } else if (size_ == capacity_) {
        reserve(capacity_ * 2);
    }
    data_[size_] = item;
    ++size_;
}

template <class T>
void Array<T>::pop_back() {
    if (size_ > 0) {
        data_[size_ - 1].~T();
        --size_;
    }
}

template <class T>
void Array<T>::resize(size_t count) {
    resize(count, T());
}

template <class T>
void Array<T>::resize(size_t count, const T &value) {
    if (count > size_) {
        reserve(count * 2);
        for (size_t i = size_; i < count; ++i) {
            data_[i] = value;
        }
    } else if (count < size()) {
        for (size_t i = count; i < size_; ++i) {
            data_[i].~T();
        }
    }
    size_ = count;
}

template <class T>
void Array<T>::erase(size_t pos) {
    if (pos >= size_) {
        throw std::out_of_range("Out of range.");
    }
    for (size_t i = pos; i < size_ - 1; ++i) {
        data_[i] = std::move(data_[i + 1]);
    }
    --size_;
}

template <class T>
void Array<T>::reallocate(size_t newCapacity) {
    std::shared_ptr<T[]> newData = std::shared_ptr<T[]>(new T[newCapacity]);
    for (size_t i = 0; i < size_; ++i) {
        newData[i] = std::move(data_[i]);
    }
    data_ = newData;
    capacity_ = newCapacity;
}

template <class T>
bool operator==(const Array<T> &lhs, const Array<T> &rhs) {
    if (lhs.size_ != rhs.size_) {
        return false;
    }
    for (size_t i = 0; i < lhs.size_; ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool operator!=(const Array<T> &lhs, const Array<T> &rhs) {
    return !(lhs == rhs);
}
