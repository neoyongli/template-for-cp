#define low(i) i & (-i)
struct bit {
    vector<i64> t; int _; 
    bit(int N) { t.resize(N + 1); _ = N; }
    void add(int x, i64 y) { for (; x <= _; x += low(x)) t[x] += y; }
    i64 query(int x) { i64 res = 0; for (; x >= 1; x -= low(x)) res += t[x]; return res; }
    i64 query(int l, int r) { return query(r) - query(l - 1); }
};
// add(x, y) means add y to everything from [x, N]
// query(l, r) finds the sum of values from [l, r]
// this can be used in range sum and point update
