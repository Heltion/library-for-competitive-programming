#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include "string/manacher.hpp"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (int mi : manacher(s)) {
        cout << mi << " ";
    }
}