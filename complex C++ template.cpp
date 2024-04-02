#pragma warning(suppress : 4996)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
// char buf[1 << 23], * p1 = buf, * p2 = buf;
// #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename T> inline void read(T& x) { x = 0; T f = 1; char ch = getchar();  while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); } while (isdigit(ch)) { x = (x << 1) + (x << 3) + (ch - 48); ch = getchar(); } x *= f; }
template<typename x, typename... y>void read(x& a, y&... b) { read(a); read(b...); }
template<typename T> inline void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x > 9)  print(x / 10); putchar(x % 10 + '0'); }
template<typename x, typename... y>void print(x& a, y&... b) { print(a); putchar(' '); print(b...); }
#define spa putchar(' ')
#define nl putchar('\n')
#define au(i, p) putchar(" \n"[i == p.size() - 1])
#define printv(a) for(int p = 0; p < a.size(); p++) print(a[p]), au(p, a);
#define L(i,j,k) for(int i=(j);i<=(k);++i)
#define R(i,j,k) for(int i=(j);i>=(k);--i)
#define l(i, n) for(int i=(1);i<=(n);++i)
#define r(i, n) for(int i=(n);i>=1;--i)
#define all(x) x.begin(),x.end()
#define me(x,a) memset(x,a,sizeof(x))
#define mp make_pair
#define pb push_back

void solve() {
	
}

int main() {
	int T; read(T);
	while(T--) solve();
}
