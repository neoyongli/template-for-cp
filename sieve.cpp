vector<int> prime, minp;
void sieve(int N = 1e6) {
    prime.clear(); minp.assign(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            prime.push_back(i);
        }

        for (auto& p : prime) {
            if (i * p > N) break;
            minp[i * p] = p;
            if (p == minp[i]) break;
        }
    }
}

/*
do seive(size) or else the default is size = 10 ^ 6
we can get a prime list that stores all primes <= N and find the minimum prime (minp[i]) that can divide i
this is useful when we want to do prime factorisation to the number
*/
