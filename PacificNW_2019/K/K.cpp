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

const int MOD = 256;

struct BIT {
    int size;
    vector<vector<II>> fen;
    void setSize(int s) {
        size = s;
        fen.resize(s + 1);
    }
    void _add(int u, int v, int t) {
        for (int i = u; i <= size; i += i & -i) {
            int val = 0;
            if (fen[i].size()) {
                val = fen[i].back().second;
            }
            val = (val + v) % MOD;
            fen[i].pb({t, val});
        }
    }   
    void add(int l, int r, int v, int t) {
        _add(l, v, t);
        _add(r + 1, MOD - v, t);
    }

    int query(int u, int t) {
        int res = 0;
        for (int i = u; i; i -= i & -i) {
            // res = (res + fen[i]) % MOD;
            auto u = lower_bound(all(fen[i]), II(t, -1)) - fen[i].begin() - 1;
            res = (res + fen[i][u].second) % MOD;
        }
        return res;
    }
} fen[500005];

int a[500005];

struct Node {
    int first, second, t;
};
Node st[500005 * 4];

void down(int id, int l, int r) {
    if (!st[id].first || l == r) return;
    st[id * 2] = st[id];
    st[id * 2 + 1] = st[id];
    st[id] = {0, 0};
}

void update(int id, int l, int r, int u, int v, Node val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        st[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    down(id, l, r);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
}

Node getA(int id, int l, int r, int u) {
    if (l == r) {
        return st[id];
    }
    int mid = (l + r) / 2;
    down(id, l, r);
    if (u <= mid) {
        return getA(id * 2, l, mid, u);
    }
    return getA(id * 2 + 1, mid + 1, r, u);
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    FOR (i, 1, m) {
        int s;
        cin >> s;
        fen[i].setSize(s);
        FOR (j, 1, fen[i].size) {
            int x;
            cin >> x;
            fen[i].add(j, j, x, 0);
        }
    }
    fen[0].setSize(n);

    FOR (z, 1, q) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, p;
            cin >> i >> p; 
            Node u = {i, p - 1, z};
            update(1, 1, n, p, p + fen[i].size - 1, u);
        }
        else if (type == 2) {
            int p;
            cin >> p;
            Node val = getA(1, 1, n, p);
            if (val.first == 0) {
                cout << 0 << "\n";
            }
            else {
                cout << fen[val.first].query(p - val.second, val.t) << endl;
            }
        }
        else {
            int i, l, r;
            cin >> i >> l >> r;
            fen[i].add(l, r, 1, z);
        }
        // FOR (p, 1, n) {
        //     II val = getA(1, 1, n, p);
        //     cout << fen[val.first].query(p - val.second) << " ";
        // }
        // cout << endl;
    }


    return 0;
}