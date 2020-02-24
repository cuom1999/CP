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

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int MAXN = 300005;

struct Query {
    int a, l, r;
};
vector<Query> queries[MAXN];
vector<int> updates[MAXN], jump[MAXN];

ll st[4 * MAXN], lz[4 * MAXN];

void down(int id, int l, int r) {
    if (l == r || !lz[id]) return;
    int mid = (l + r ) / 2;
    lz[id * 2] += lz[id];
    st[id * 2] += lz[id] * (mid - l + 1);

    lz[id * 2 + 1] += lz[id];
    st[id * 2 + 1] += lz[id] * (r - mid);
    
    lz[id] = 0;    
}

void update(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        st[id] += k * 1ll * (r - l + 1);
        lz[id] += k;
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);

    st[id] = st[id * 2] + st[id * 2 + 1];
}

ll getSum(int id, int l, int r, int u, int v) {
    if (v < l || r < u || v < u) return 0;
    if (u <= l && r <= v) return st[id];

    int mid = (l + r) / 2;
    down(id, l, r);
    return getSum(id * 2, l, mid, u, v) + getSum(id * 2 + 1, mid + 1, r, u, v);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, w;
    cin >> n >> w;
    FOR (i, 1, w) {
        int k;
        cin >> k;

        FOR (j, 1, k) {
            int x;
            cin >> x;
            jump[x].pb(i);
        }
    }

    FOR (i, 1, n) {
        for (int j = 0; j < jump[i].size(); j++) {
            updates[j].pb(jump[i][j]);
        }
        jump[i].pb(w + 1);
        if (jump[i].size()) queries[0].pb({i, 1, jump[i][0] - 1});
        for (int j = 0; j + 1 < jump[i].size(); j++) {
            queries[j + 1].pb({i, jump[i][j], jump[i][j + 1] - 1});
        }
    }

    vector<ll> sum(n + 1);

    FOR (t, 0, w) {
        for (auto u: updates[t]) {
            update(1, 1, w, u, w, 1);
        } 
        for (auto q: queries[t]) {
            // cout << q.l << " " << q.r << endl;
            sum[q.a] += getSum(1, 1, w, q.l, q.r);
        }
        for (auto u: updates[t]) {
            update(1, 1, w, u, w, -1);
        } 
    }

    FOR (i, 1, n) cout << fixed << setprecision(8) << sum[i] * 1.0 / w + 1 << "\n";

    return 0;
}