template<typename T> T gcd(T x, T y) { if (y == 0) return x; return gcd(y, x % y); }
template<typename T> T lcm(T x, T y) { T d = gcd(x, y); return x * y / d; }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if (b == 0) { x = 1, y = 0; return a; } T g = exgcd(b, a % b, y, x); y -= a / b * x; return g; }
/*
    gcd returns the greatest common divisor of 2 numbers
    lcm returns the least common multiple
    exgcd(a, b, x, y) finds a pair(x, y) that satisfies a * x + b * y = +- gcd(a, b)
    example to find A * X - B * Y = c
        if(c % gcd(A, B) != 0) no solution
        i64 X, Y;
        exgcd(A, B, X, Y);
        since we want negative B, Y = -Y
        X *= (c/g); Y *= (c/g);
*/
