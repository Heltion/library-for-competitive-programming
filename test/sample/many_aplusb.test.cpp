#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "core.hpp"
int main() {
    IO io;
    repeat(io, [&] {
        i64 a = io, b = io;
        io << a + b << "\n";
    });
}