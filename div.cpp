namespace factorBasic {
	template <class T> vector<pair<T, int>> factor(T x) {
		vector<pair<T, int>> pri;
		for (T i = 2; i * i <= x; ++i)
			if (x % i == 0) {
				int t = 0;
				while (x % i == 0) x /= i, t++;
				pri.pb({ i, t });
			}
		if (x > 1) pri.pb({ x, 1 });
		return pri;
	}
	i64 phi(i64 x) {
		for (auto& a : factor(x)) x -= x / a.first;
		return x;
	}
	template <class T>
	void tour(vector<pair<T, int>>& v, vector<T>& V, int ind, T cur) {
		if (ind == (int)(v.size())) V.pb(cur);
		else {
			T mul = 1;
			FOR(i, 0, v[ind].second + 1) {
				tour(v, V, ind + 1, cur * mul);
				mul *= v[ind].first;
			}
		}
	}
	template <class T> vector<T> divisors(T x) {
		auto v = factor(x);
		vector<T> V;
		tour(v, V, 0, (T)1);
		sort(V.begin(), V.end());
		return V;
	}
	//this can work up to 10^19 as long as there is a data structure that can hold it
}
using namespace factorBasic;
// this code is able to factorise the numbers into primes and calculate phi, 
// it can also return the vector of divisors
