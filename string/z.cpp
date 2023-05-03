#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<int> z_function(const T &s) {
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n, n);
    for (int i = 1; i < n; i += 1) {
        if (i >= r) {
            z[i] = 0;
        } else {
            z[i] = min(z[i - l], r - i);
        }
        while (i + z[i] < n and s[i + z[i]] == s[z[i]]) {
            z[i] += 1;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}