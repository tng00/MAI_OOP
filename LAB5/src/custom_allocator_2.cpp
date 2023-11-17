#pragma once
#include "../include/custom_allocator_2.hpp"

template <typename _Tp, std::size_t BLOCK_SIZE>
CustomAllocator2<_Tp, BLOCK_SIZE>::~CustomAllocator2() {
    for (auto it : _blocks_storage) {
        operator delete(it);
    }
}

template <typename _Tp, std::size_t BLOCK_SIZE>
typename CustomAllocator2<_Tp, BLOCK_SIZE>::pointer
CustomAllocator2<_Tp, BLOCK_SIZE>::allocate(size_type __n) {
    if (__n == 0) {
        return nullptr;
    }

    if (__n > BLOCK_SIZE) {
        throw std::bad_alloc();
    }

    if (_blocks_storage.empty()) {
        create_block();
    }

    std::size_t cur_index = _used_count / BLOCK_SIZE;
    std::size_t cur_pointer = _used_count % BLOCK_SIZE;
    std::size_t cur_remainder = BLOCK_SIZE - cur_pointer;

    if (cur_remainder < __n) {
        _used_count += cur_remainder + __n;
        create_block();
        pointer res = get_cur_block(cur_index + 1);
        return res;
    } else {
        _used_count += __n;
        pointer res = get_cur_block(cur_index) + cur_pointer;
        return res;
    }
}

template <typename _Tp, std::size_t BLOCK_SIZE>
void CustomAllocator2<_Tp, BLOCK_SIZE>::deallocate(pointer __p, size_type __n) {
    // Memory after deallocation is not reused
}

template <typename _Tp, std::size_t BLOCK_SIZE>
template <typename _Tp1, typename... Args>
void CustomAllocator2<_Tp, BLOCK_SIZE>::construct(_Tp1 *__p, Args &&...args) {
    new (__p) _Tp1(std::forward<Args>(args)...);
}

template <typename _Tp, std::size_t BLOCK_SIZE>
void CustomAllocator2<_Tp, BLOCK_SIZE>::destroy(pointer __p) {
    __p->~_Tp();
}

template <typename _Tp, std::size_t BLOCK_SIZE>
void CustomAllocator2<_Tp, BLOCK_SIZE>::create_block() {
    pointer block = static_cast<value_type *>(::operator new(BLOCK_SIZE * sizeof(value_type)));
    if (!block) {
        throw std::bad_alloc();
    }
    _blocks_storage.push_back(block);
}

template <typename _Tp, std::size_t BLOCK_SIZE>
typename CustomAllocator2<_Tp, BLOCK_SIZE>::pointer
CustomAllocator2<_Tp, BLOCK_SIZE>::get_cur_block(size_type __n) {
    auto res = _blocks_storage.begin();
    while (__n--) {
        ++res;
    }
    return *res;
}