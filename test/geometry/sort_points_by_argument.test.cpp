#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include "geometry.hpp"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Point<i64>> p(n);
    for (auto &[x, y] : p) {
        cin >> x >> y;
    }
    sort(p.begin(), p.end(), Argument<i64>());
    for (auto [x, y] : p) {
        cout << x << " " << y << "\n";
    }
    return 0;
}