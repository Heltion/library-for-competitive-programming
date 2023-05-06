#include <functional>
#include <iostream>

using i64 = int64_t;

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

void repeat(int n, std::function<void()> &&f) {
    for (int i = 0; i < n; i += 1) {
        f();
    }
}