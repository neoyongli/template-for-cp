const int N = 4e5, K = 30;// change the N and K value if not the same
vector<int> G[N];
int dep[N], sp[N][K];
void dfs(int u, int p) {
	dep[u] = dep[p] + 1; sp[u][0] = p;
	for (int i = 1; i < K; i++)sp[u][i] = sp[sp[u][i - 1]][i - 1];
	for (int v : G[u]) if (v != p)dfs(v, u);
}
int lca(int u, int v) { 
	if (dep[u] < dep[v])swap(u, v);
	for (int i = K - 1; i >= 0; i--)if (dep[sp[u][i]] >= dep[v])u = sp[u][i];
	if (u == v) return u;
	for (int i = K - 1; i >= 0; i--)if (sp[u][i] != sp[v][i])u = sp[u][i], v = sp[v][i];
	return sp[v][0];
}
// first dfs(root, 0) if one indexed
// then you can find lca(x, y) in O(log N) time
