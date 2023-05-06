#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "core.hpp"
#include <map>
int main() {
    IO io;
    std::map<i64, i64> a;
    repeat(io, [&] {
        if (io == 0) {
            i64 k = io;
            a[k] = io;
        } else {
            io << a[io] << "\n";
        }
    });
}