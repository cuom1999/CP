const int MAXN = 1000005;
ll st[4 * MAXN], lz[4 * MAXN];
ll init[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = init[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void down(int id, int l, int r) {
    if (l == r || !lz[id]) return;
    FOR (i, 0, 1) {
        st[id * 2 + i] += lz[id];
        lz[id * 2 + i] += lz[id];
    } 
    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, ll k) {
    if (v < l || r < u) {
        return;
    }
    if (u <= l && r <= v) {
        st[id] += k;
        lz[id] += k;
        return;
    }

    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

ll query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return -1e18;
    }
    if (u <= l && r <= v) {
        return st[id];
    }

    down(id, l, r);
    int mid = (l + r) / 2;
    return max(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}