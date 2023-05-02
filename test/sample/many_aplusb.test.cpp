#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _ += 1) {
        i64 a, b;
        cin >> a >> b;
        cout << a + b << "\n";
    }
    return 0;
}