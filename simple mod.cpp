const int mod = 998244353;
i64 add(i64 x, i64 y) { return ((x % mod) + (y % mod)) % mod; }
i64 prod(i64 x, i64 y) { return ((x % mod) * (y % mod)) % mod; }
i64 minus(i64 x, i64 y) { return ((x % mod) - (y % mod) + mod) % mod; }
i64 fpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) { if (b & 1) res = prod(res, a); a = prod(a, a); b >>= 1; }
    return res;
}
i64 divi(i64 x, i64 y) { return prod(x, fpow(y, mod - 2)); }

// this code performs the 4 main basic operations used + binary exponential, change the mod value if the mod is not 998244353
// sometimes it goes over the mod value, remember to modulo before printing
