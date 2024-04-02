const int _N = 5e5; // you can change the size to bigger or smaller
vector<int> G[_N];
namespace shupou {
    int dfn[_N], tim = 0, dep[_N], sz[_N], fa[_N], top[_N], son[_N];
    void dfs_heavy(int u, int f) {
        dfn[u] = ++tim; sz[u] = 1; fa[u] = f; dep[u] = dep[f] + 1;
        for (auto& v : G[u]) {
            if (v == f) continue;
            dfs_heavy(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[son[u]]) son[u] = v;
        }
    }
    void dfs_top(int u, int f) {
        top[u] = f;
        if (son[u]) dfs_top(son[u], f);
        for (auto& v : G[u]) {
            if (v == fa[u] || v == son[u]) continue;
            dfs_top(v, v);
        }
    }
    int lca(int x, int y) {
        while (top[x] != top[y]) {
            if (dep[top[x]] >= dep[top[y]]) x = fa[top[x]];
            else y = fa[top[y]];
        }
        return dep[x] < dep[y] ? x : y;
    }
    void shupou(int root = 1) {
        dfs_heavy(root, 0);
        dfs_top(root, root);
    }
};
//this uses Heavy Light Decomposition
//shupou::shupou(root)
//shupou::lca(x,y)

namespace xushu {
    int a[_N], pt = 0, npt = 0;
    vector<int> XG[_N], prev;
    int cmp(int x, int y) { return shupou::dfn[x] < shupou::dfn[y]; }
    void build(vector<int>& x) {
        pt = 0;
        for (auto& v : x) a[++pt] = v;
        sort(a + 1, a + pt + 1, cmp);
        npt = pt;
        for (int i = 2; i <= pt; i++) {
            int lca = shupou::lca(a[i], a[i - 1]);
            if (lca != a[i] && lca != a[i - 1]) a[++npt] = lca;
        }
        sort(a + 1, a + npt + 1);
        npt = unique(a + 1, a + npt + 1) - (a + 1);
        sort(a + 1, a + npt + 1, cmp);
        prev.push_back(a[1]);
        for (int i = 2; i <= npt; i++) {
            int lca = shupou::lca(a[i], a[i - 1]);
            XG[lca].push_back(a[i]);
            prev.push_back(a[i]);
        }
    }
    void clear() {
        for (auto& v : prev) XG[v].clear();
        prev.clear();
        pt = 0; npt = 0;
    }
};
//xushu::build(vector)
//xushu::clear()
//xushu::a[1] to access top of the virtual tree
//xushu::GX[i] to access directed edges starting from i
//note that we only build directed edges from root of the tree
//use shupou snippet to work
