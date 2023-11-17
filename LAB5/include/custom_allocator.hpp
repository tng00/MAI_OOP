#pragma once
#include <cstddef>
#include <list>
#include <utility>

template <typename _Tp, std::size_t SIZE = 1024>
class CustomAllocator {
public:
    typedef std::size_t size_type;
    typedef _Tp *pointer;
    typedef const _Tp *const_pointer;
    typedef _Tp value_type;

    CustomAllocator();
    ~CustomAllocator();

    pointer allocate(size_type __n);
    void deallocate(pointer __p, size_type __n);

    template <typename _Tp1, typename... Args>
    void construct(_Tp1 *__p, Args &&...args);

    void destroy(pointer __p);

    template <typename _Tp1>
    struct rebind {
        typedef CustomAllocator<_Tp1, SIZE> other;
    };

private:
    std::list<_Tp> _used_blocks;
    void **_free_blocks;
    size_type _free_count;
};
