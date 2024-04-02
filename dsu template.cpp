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
	bool same(int x, int y) {
		int px = find(x), py = find(y);
		return px == py;
	}
};
/*
Initialising: dsu dsu_name(size)
  You can replace dsu_name with any name that you like and the size is just the number of nodes
Merging: dsu_name.merge(x, y)
  this performs a merging of component of x and component of y, if they are already in the same component the function returns false
  else it would just merge the two components
Find: dsu_name.find(x)
  this returns the parent of the component
Same component: dsu_name.same(x, y)
  returns a boolean value that shows whether they are in the same component
*/
