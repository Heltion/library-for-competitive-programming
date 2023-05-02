using i64 = long long;
template <typename T> struct Point {
    T x, y;
    int sign() const {
        if (y < 0 or (y == 0 and x > 0)) {
            return -1;
        }
        if (y > 0 or (y == 0 and x < 0)) {
            return 1;
        }
        return 0;
    }
    T cross(const Point &rhs) const { return x * rhs.y - y * rhs.x; }
};
template <typename T> struct Argument {
    bool operator()(const Point<T> &lhs, const Point<T> &rhs) const {
        return lhs.sign() != rhs.sign() ? lhs.sign() < rhs.sign()
                                        : lhs.cross(rhs) > 0;
    }
};