struct dsu {
	vector<int> fa, sz;
	dsu(int n) {
		fa.resize(n + 10);
		iota(fa.begin(), fa.end(), 0);
		sz.assign(n + 10, 1);
	}
	int find(int x) {
		while (x != fa[x]) x = fa[x] = fa[fa[x]];
		return x;
	}
	bool merge(int x, int y) {
		int px = find(x), py = find(y);
		if (px == py) return false;
		if (sz[py] > sz[px]) swap(px, py);
		sz[px] += sz[py]; fa[py] = px;
		return true;
	}
};
struct edge {
	int u, v;
	i64 w;
	bool operator <(edge& a) { return w < a.w; }
};
namespace MST {
	vector<edge> G;
	vector<edge> build(vector<edge> GG) {
		G = GG;
		int mx = -1;
		for (auto e : G) {
			mx = max(e.u, mx);
			mx = max(e.v, mx);
		}
		sort(G.begin(), G.end());
		dsu ds(mx + 50);
		vector<edge> res;
		for (auto e : G) {
			int u = e.u, v = e.v; i64 w = e.w;
			if (ds.merge(u, v)) {
				res.push_back(e);
			}
		}
		return res;
	}
};
// use MST::build(vector<edge> G) to return vector<edge>(set of edges for the MST) 

