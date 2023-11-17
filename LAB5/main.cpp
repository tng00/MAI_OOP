#include <bits/stdc++.h>
#include "src/custom_allocator_2.cpp"
#include "src/custom_list.cpp"

template <int N>
int factorial() {
    return N * factorial<N - 1>();
}

template <>
int factorial<0>() {
    return 1;
}

typedef std::map<int, int, std::less<int>,
                 CustomAllocator<std::pair<const int, int>>>
    map_with_custom_allocator;
typedef CustomList<int> list_with_custom_allocator;

template <int N>
void fill_map(map_with_custom_allocator &map) {
    map.insert(std::pair<int, int>(N, factorial<N>()));
    fill_map<N - 1>(map);
}

template <>
void fill_map<0>(map_with_custom_allocator &map) {
    map.insert(std::pair<int, int>(0, factorial<0>()));
}

int main() {
    // Создание экземпляра std::map с созданным аллокатором
    map_with_custom_allocator mp;

    // Заполнение 10 элементами, где ключ - это число от 0 до 9, а значение - факториал ключа
    fill_map<9>(mp);

    // Вывод на экран всех значений (ключ и значение разделены пробелом)
    std::cout << "Map factorials:" << std::endl;
    for (const auto &pair : mp) {
        std::cout << "fact(" << pair.first << "): " << pair.second << std::endl;
    }

    // Создание экземпляра своего контейнера для хранения int с собственным аллокатором
    list_with_custom_allocator l;

    // Заполнение контейнера и печать его элементов
    for (int i = 0; i < 20; ++i) {
        l.push_back(i);
    }

    std::cout << "\nList elements:" << std::endl;
    for (const auto &value : l) {
        std::cout << value << " ";
    }

    return 0;
}
