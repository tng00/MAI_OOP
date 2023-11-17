#include "../src/list_iterator.cpp"
#include <initializer_list>

template <typename T, typename Alloc = CustomAllocator<T>>
class CustomList {
public:
    typedef T value_type;
    typedef std::size_t size_type;
    typedef value_type &reference;
    typedef const value_type &const_reference;
    typedef value_type *pointer;
    typedef const value_type *const_pointer;
    typedef ListIterator<value_type> iterator;
    typedef const ListIterator<value_type> const_iterator;

    CustomList();
    CustomList(const CustomList &other);
    CustomList &operator=(const CustomList &other);
    CustomList(CustomList &&other) noexcept;
    CustomList &operator=(CustomList &&other) noexcept;
    CustomList(std::initializer_list<value_type> initList);
    ~CustomList();

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator begin() const noexcept;
    const_iterator end() const noexcept;

    bool empty() const;
    size_type size() const;

    void clear();
    iterator insert(const_iterator pos, const value_type &value);
    iterator erase(const_iterator pos);

    void push_back(const value_type &value);
    template <typename... Args>
    void emplace_back(Args &&...args);
    void pop_back();

    void push_front(const value_type &value);
    template <typename... Args>
    void emplace_front(Args &&...args);
    void pop_front();

    void resize(size_type new_size);

    bool operator==(const CustomList &other) const;
    bool operator!=(const CustomList &other) const;

private:
    Node<value_type> *head;
    Node<value_type> *tail;
    size_type _size;
    typename Alloc::template rebind<Node<value_type>>::other _node_allocator;
};
