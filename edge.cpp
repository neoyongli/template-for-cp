const int _N = 2e5;
int head[_N << 1], ver[_N << 1], nxt[_N << 1], tot = 0;
void add_edge(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
#define trav(v, u) for(int j=head[u],v=ver[j];j;j=nxt[j],v=ver[j])
// trav(v, u) just traverses through all the edges going out from u and the neighbour node = v
// add_edge(u, v) to add a directed edge from u to v
// change the _N value if it is not big enough
