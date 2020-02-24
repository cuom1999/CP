#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

struct Node {
    int val;
    int pos;
} st[4 * 200005];
    
int a[200005];

Node merge(Node l, Node r) {
    if (l.val < r.val) return l;
    if (l.val > r.val) return r;
    return {l.val, min(l.pos, r.pos)};
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id].val = a[l];
        st[id].pos = l;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int k) {
    if (l == r) {
        st[id] = {k, l};
        return;
    }
    int mid = (l + r) / 2;
    if (u <= mid) {
        update(id * 2, l, mid, u, k);
    }
    else {
        update(id * 2 + 1, mid + 1, r, u, k);
    }
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

Node getMin(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return {INF + 1, 0};
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    Node a = getMin(id * 2, l, mid, u, v);
    Node b = getMin(id * 2 + 1, mid + 1, r, u, v);
    return merge(a, b);
}


vector<int> v[200005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    priority_queue<II, vector<II>, greater<II>> pq;
    int n, k;
    cin >> n >> k;

    FOR (i, 1, n) {
        int x;
        cin >> x;
        a[i] = x;
        v[x].pb(i);
    }

    build(1, 1, n);

    FOR (i, 1, k) {
        pq.push({v[i].back(), i});
    }

    vector<int> res;
    vector<bool> used(k + 1);

    int lastPos = 1;

    while (pq.size()) {
        int u = pq.top().first;
        int uu = pq.top().second;
        if (used[uu]) {
            pq.pop();
            continue;
        }

        Node curRes = getMin(1, 1, n, lastPos, u);
        int val = curRes.val;
        lastPos = curRes.pos;
        res.pb(val);
        // cout << u << " " << val << endl;
        for (auto i: v[val]) {
            update(1, 1, n, i, INF);
        }
        used[val] = 1;
    }

    for (auto i: res) cout << i << " "; cout << endl;

    return 0;
}