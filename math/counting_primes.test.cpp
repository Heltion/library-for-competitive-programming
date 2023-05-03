#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    cin >> n;
    i64 sqrt_n = sqrt(n);
    int num = sqrt_n * 2 - (sqrt_n * (sqrt_n + 1) > n);
    auto div = [&](i64 x, i64 y) -> i64 { return (double)x / y; };
    auto index = [&](i64 i) { return i <= sqrt_n ? i : num + 1 - div(n, i); };
    auto value = [&](int i) { return i <= sqrt_n ? i : div(n, num + 1 - i); };
    vector<i64> f(num + 1);
    for (int i = 1; i <= num; i += 1) {
        f[i] = value(i);
    }
    vector<bool> cp(sqrt_n + 1);
    for (int p = 2, m = 0; p <= sqrt_n; p += 1) {
        if (not cp[p]) {
            m += 1;
            for (int i = p; i <= sqrt_n; i += p) {
                cp[i] = true;
            }
            int l = index((i64)p * p), r = index(div(n, p));
            f[num] -= f[r] - m;
            for (int i = r; i >= l; i -= 1) {
                f[i] -= f[index(div(value(i), p))] - m;
            }
        }
    }
    cout << f[num] - 1;
}