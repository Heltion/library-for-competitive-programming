#include "core.hpp"
#include <numeric>
#include <string>
#include <vector>
struct WTree {
    static constexpr int w = 64;
    static constexpr u64 bit(int i) { return (u64)1 << i; }
    std::vector<std::vector<u64>> mask;
    WTree(int n) {
        do {
            mask.emplace_back(n = (n + w - 1) / w);
        } while (n > 1);
    }
    WTree(const std::string &t) : WTree(t.size()) {
        repeat(t.size(), [&](int i) {
            if (t[i] == '1') {
                mask[0][i / w] |= bit(i % w);
            }
        });
        repeat(1, mask.size(), [&](int i) {
            repeat(mask[i - 1].size(), [&](int j) {
                if (mask[i - 1][j]) {
                    mask[i][j / w] |= bit(j % w);
                }
            });
        });
    }
    void insert(int k) {
        repeat(mask.size(), [&](int i) { mask[i][k /= w] |= bit(k % w); });
    }
    void remove(int k) {
        for (int i = 0; i < mask.size(); i += 1) {
            if (mask[i][k /= w] &= ~bit(k % w)) {
                break;
            }
        }
    }
    bool contains(int k) { return mask[0][k / w] & bit(k % w); }
    int next(int k) {
        if (contains(k)) {
            return k;
        }
        for (int i = 0; i < mask.size(); i += 1) {
            u64 suc = k % w == w - 1 ? 0 : mask[i][k / w] & -(bit(k % w + 1));
            if (suc) {
                k = k / w * w + std::countr_zero(suc);
                for (int j = i; j; j -= 1) {
                    k = k * w + std::countr_zero(mask[j - 1][k]);
                }
                return k;
            }
            k /= w;
        }
        return -1;
    }
    int prev(int k) {
        if (contains(k)) {
            return k;
        }
        for (int i = 0; i < mask.size(); i += 1) {
            u64 pre = mask[i][k / w] & (bit(k % w) - 1);
            if (pre) {
                k = k / w * w + w - 1 - std::countl_zero(pre);
                for (int j = i; j; j -= 1) {
                    k = k * w + w - 1 - std::countl_zero(mask[j - 1][k]);
                }
                return k;
            }
            k /= w;
        }
        return -1;
    }
};