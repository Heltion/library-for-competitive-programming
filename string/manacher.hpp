#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<int> manacher(const T &s) {
    int n = s.size(), l = 0, r = 0;
    vector<int> m(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i += 1) {
        if (i >= r) {
            m[i] = 0;
        } else {
            m[i] = min(m[2 * l - i], r - i);
        }
        while (i - m[i] >= 0 and i + m[i] < 2 * n - 1 and
               ((i - m[i]) & 1 or s[(i - m[i]) / 2] == s[(i + m[i]) / 2])) {
            m[i] += 1;
        }
        if (i + m[i] > r) {
            l = i;
            r = i + m[i];
        }
    }
    for (int i = 0; i < 2 * n - 1; i += 1) {
        int j = i % 2 == 0;
        m[i] = (m[i] - j) / 2 * 2 + j;
    }
    return m;
}