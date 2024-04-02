struct lichao {
    using Line = pair<i64, i64>;
    struct node {
        int l, r;
        Line line; //(m,c)
    };
    i64 get(Line line, i64 intersect) {
        return line.first * intersect + line.second;
        //y = m * x + c
    }
    vector<node> tr;
    lichao(int S) {
        tr.resize((S + 50) << 2);
    }
    int idx = 0, root = 0;
    void insert(int& u, int l, int r, Line line) {
        if (!u) {
            tr[u = ++idx].line = line;//new position for the line
            return;
        }
        else {
            int mid = (l + r) >> 1;
            if (get(line, mid) < get(tr[u].line, mid))//if it gets a smaller value, swap
                swap(line, tr[u].line);
            if (line.first > tr[u].line.first) //insert left
                insert(tr[u].l, l, mid, line);
            else //insert right
                insert(tr[u].r, mid + 1, r, line);
        }
    }
    i64 query(int u, int l, int r, int p) {
        if (!u) return (1ULL << 63) - 1; //if we visit some unknown line
        int mid = (l + r) >> 1;
        return min(get(tr[u].line, (i64)p),//minimum of current line
            (p <= mid ? query(tr[u].l, l, mid, p) : //minimum of the left son
                query(tr[u].r, mid + 1, r, p))); //minimum of the right son
    }
};
/*
lichao tree is used in a more advanced version of convex jull trick, more information about it can be found online.

lichao li(N+1)
li.query(li.root,0,mx,intersection) + something related to i  + something not related to both
li.insert(li.root,0,mx,{gradient,constant})
make sure to query before inserting
Note: a trick is just to add {0,0} before doing anything\
*/
