struct SegmentTree {
    struct Node {
        long long sum = 0;    
    } st[400005];

    void merge(Node& a, Node& b, Node& c) {
        a.sum = b.sum + c.sum;
    }
    void build(vector<int>& a, int id, int l, int r) {
        if (l == r) {
            st[id].sum = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(a, id * 2, l, mid);
        build(a, id * 2 + 1, mid + 1, r);
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    void update(int id, int l, int r, int u, int v) {
        if (l == r) {
            st[id].sum = v;
            return;
        }
        int mid = (l + r) / 2;
        if (u <= mid) update(id * 2, l, mid, u, v);
        else update(id * 2 + 1, mid + 1, r, u, v); 
        merge(st[id], st[id * 2], st[id * 2 + 1]);
    }

    Node query(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return Node();
        if (u <= l && r <= v) {
            return st[id];
        }
        int mid = (l + r) / 2;
        auto a = query(id * 2, l, mid, u, v);
        auto b = query(id * 2 + 1, mid + 1, r, u, v);
        Node res;
        merge(res, a, b);
        return res;
    }
};