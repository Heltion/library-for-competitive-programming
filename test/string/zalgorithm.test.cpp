#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "string/z.cpp"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (int zi : z_function(s)) {
        cout << zi << " ";
    }
}