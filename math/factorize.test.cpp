#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
i64 mul(i64 a, i64 b, i64 mod) { return (__int128_t)a * b % mod; }
i64 pow(i64 a, i64 r, i64 mod) {
    i64 res = 1;
    for (; r; r >>= 1, a = mul(a, a, mod)) {
        if (r & 1) {
            res = mul(res, a, mod);
        }
    }
    return res;
}
bool miller_rabin(i64 n) {
    static constexpr array<int, 9> p = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (int pi : p) {
        if (n == pi) {
            return true;
        }
        if (n % pi == 0) {
            return false;
        }
    }
    if (n <= p.back()) {
        return false;
    }
    i64 r = countr_zero((u64)n - 1), d = (n - 1) >> r;
    for (int pi : p) {
        i64 x = pow(pi, d, n);
        if (x == 1 or x == n - 1) {
            continue;
        }
        for (int j = 1; j < r; j += 1) {
            x = mul(x, x, n);
            if (x == n - 1) {
                break;
            }
        }
        if (x != n - 1) {
            return false;
        }
    }
    return true;
}
vector<i64> factorize(i64 n) {
    if (n == 1) {
        return {};
    }
    mt19937_64 mt;
    uniform_int_distribution uid(0LL, n - 1);
    vector<i64> res, stack = {n};
    while (not stack.empty()) {
        i64 n = stack.back();
        stack.pop_back();
        if (miller_rabin(n)) {
            res.push_back(n);
            continue;
        }
        while (true) {
            i64 c = uid(mt) % n, x = 0, y = 0, s = 1;
            for (i64 k = 1;; k <<= 1, y = x) {
                for (int i = 1; i <= k; i += 1) {
                    x = (mul(x, x, n) + c) % n;
                    s = mul(s, abs(x - y), n);
                }
                if (gcd(s, n) != 1) {
                    break;
                }
            }
            if (s != 0) {
                i64 d = gcd(s, n);
                stack.push_back(d);
                stack.push_back(n / d);
                break;
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    for (int qi = 0; qi < q; qi += 1) {
        i64 n;
        cin >> n;
        auto p = factorize(n);
        cout << p.size();
        for (i64 pi : p) {
            cout << " " << pi;
        }
        cout << "\n";
    }
}