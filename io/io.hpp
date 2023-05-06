#include <iostream>
struct VectorIO {};
struct IO {
    IO() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    template <typename T> operator T() const {
        T t;
        std::cin >> t;
        return t;
    }
    template <typename T> IO &operator<<(const T &t) {
        std::cout << t;
        return *this;
    }
};