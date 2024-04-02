const int _N = 1e5 + 500;
struct node {
    int ls, rs, val;
}tr[_N * 20];
int id[_N], tot;
void update(int& u, int v, int l, int r, int x, int p) {
    u = ++tot;
    tr[u] = tr[v]; tr[u].val += p;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (x <= mid) update(tr[u].ls, tr[v].ls, l, mid, x, p);
    else update(tr[u].rs, tr[v].rs, mid + 1, r, x, p);
}
int query(int u, int v, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tr[u].val - tr[v].val;
    if (l == r) return 0;
    int mid = (l + r) >> 1, ans = 0;
    if (x <= mid) ans += query(tr[u].ls, tr[v].ls, l, mid, x, y);
    if (y >= mid + 1) ans += query(tr[u].rs, tr[v].rs, mid + 1, r, x, y);
    return ans;
}
// increase at position x by p: update(id[i], id[i-1], 1, n, x, p)
// get sum between version a and b: query(id[a], id[b-1], l, r, x, y)
// make sure to set the memory size to be larger, normally N * log N
