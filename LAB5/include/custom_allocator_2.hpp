#pragma once
#include <cstddef>
#include <list>
#include <utility>

template <typename _Tp, std::size_t BLOCK_SIZE = 1024>
class CustomAllocator2 {
public:
    typedef std::size_t size_type;
    typedef _Tp *pointer;
    typedef const _Tp *const_pointer;
    typedef _Tp value_type;

    CustomAllocator2() : _used_count(0) {}
    ~CustomAllocator2();

    pointer allocate(size_type __n);
    void deallocate(pointer __p, size_type __n);

    template <typename _Tp1, typename... Args>
    void construct(_Tp1 *__p, Args &&...args);

    void destroy(pointer __p);

    void create_block();
    pointer get_cur_block(size_type __n);

    template <typename _Tp1>
    struct rebind {
        typedef CustomAllocator2<_Tp1, BLOCK_SIZE> other;
    };

private:
    std::list<pointer> _blocks_storage;
    size_type _used_count;
};
