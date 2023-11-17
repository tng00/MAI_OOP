#pragma once
#include "../include/custom_allocator.hpp"

template <typename _Tp, std::size_t SIZE>
CustomAllocator<_Tp, SIZE>::CustomAllocator() {
    static_assert(SIZE > 0);
    _used_blocks.resize(SIZE);
    _free_blocks = (void **)operator new(sizeof(void *) * SIZE);

    auto it = _used_blocks.begin();
    for (size_type i = 0; i < SIZE; ++i) {
        _free_blocks[i] = &(*it++);
    }
    _free_count = SIZE;
}

template <typename _Tp, std::size_t SIZE>
CustomAllocator<_Tp, SIZE>::~CustomAllocator() {
    _used_blocks.clear();
    operator delete(_free_blocks);
}

template <typename _Tp, std::size_t SIZE>
typename CustomAllocator<_Tp, SIZE>::pointer
CustomAllocator<_Tp, SIZE>::allocate(size_type __n) {
    if (__n == 0) {
        return nullptr;
    }

    if (__n > _free_count) {
        throw std::bad_alloc();
    }

    _free_count -= __n;
    return (_Tp *)_free_blocks[_free_count];
}

template <typename _Tp, std::size_t SIZE>
void CustomAllocator<_Tp, SIZE>::deallocate(pointer __p, size_type __n) {
    // Memory after deallocation is not reused
}

template <typename _Tp, std::size_t SIZE>
template <typename _Tp1, typename... Args>
void CustomAllocator<_Tp, SIZE>::construct(_Tp1 *__p, Args &&...args) {
    new (__p) _Tp1(std::forward<Args>(args)...);
}

template <typename _Tp, std::size_t SIZE>
void CustomAllocator<_Tp, SIZE>::destroy(pointer __p) {
    __p->~_Tp();
}
