int X = 60;//X = size of matrix
struct matrix {
	int P[X + 1][X + 1];
	matrix operator * (const matrix& A) const {
		matrix B; me(B.P, 0);
		L(k, 0, X - 1) L(i, 0, X - 1) if (P[i][k]) L(j, 0, X - 1)
			B.P[i][j] = (B.P[i][j] + 1LL * P[i][k] * A.P[k][j] % mod) % mod;
		return B;
	}
};
// use template L(i, j, k) and me(x, a) -> for(int i = j; j <= k; j++) and memset(x, a, sizeof(x))
// this performs a matrix multiplication with O(n ^ 3)
// note that matrix can also be used for binary exponential
