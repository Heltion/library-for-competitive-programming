#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    map<i64, i64> a;
    for (int _ = 0, t; _ < q; _ += 1) {
        i64 k, v;
        cin >> t >> k;
        if (t == 0) {
            cin >> v;
            a[k] = v;
        } else {
            cout << a[k] << "\n";
        }
    }

    return 0;
}