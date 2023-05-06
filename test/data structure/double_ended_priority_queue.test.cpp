#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"
#include "core.hpp"
#include <set>
int main() {
    IO io;
    int n = io, q = io;
    std::multiset<i64> s;
    repeat(n, [&]() { s.insert(i64(io)); });
    repeat(q, [&] {
        choose(io, {[&]() { s.insert(i64(io)); },
                    [&]() {
                        io << *s.begin() << "\n";
                        s.erase(s.begin());
                    },
                    [&]() {
                        io << *s.rbegin() << "\n";
                        s.extract(*s.rbegin());
                    }});
    });
}