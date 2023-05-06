#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem.test"
#include "core.hpp"
#include "ds/w_tree.hpp"
#include <string>
int main() {
    IO io;
    int n = io, q = io;
    std::string t = io;
    WTree w_tree(t);
    repeat(q, [&]() {
        choose(io, {[&]() { w_tree.insert(io); }, [&]() { w_tree.remove(io); },
                    [&]() { io << w_tree.contains(io) << "\n"; },
                    [&]() { io << w_tree.next(io) << "\n"; },
                    [&]() { io << w_tree.prev(io) << "\n"; }});
    });
}