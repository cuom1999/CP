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

ll sum(ll x) {
    return x * (x + 1) / 2;
}

struct Node {
    ll val0, val1;
    ll lz;
};

Node st[12000006];

void merge(int id) {
    st[id].val0 = st[id * 2].val0 + st[id * 2 + 1].val0;
    st[id].val1 = st[id * 2].val1 + st[id * 2 + 1].val1;
}

void down(int id, int l, int r) {
    if (!st[id].lz || l == r) return;
    st[id * 2].lz += st[id].lz;
    st[id * 2 + 1].lz += st[id].lz;

    int mid = (l + r) / 2;
    st[id * 2].val0 += (mid - l + 1) * st[id].lz;
    st[id * 2 + 1].val0 += (r - mid) * st[id].lz;

    st[id * 2].val1 += (sum(mid) - sum(l - 1)) * st[id].lz;
    st[id * 2 + 1].val1 += (sum(r) - sum(mid)) * st[id].lz;
    st[id].lz = 0;   
}

void update(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) {
        return;
    }
    if (u <= l && r <= v) {
        st[id].lz += k;
        st[id].val0 += k;
        st[id].val1 += k * 1ll * (sum(r) - sum(l - 1));
        return;
    }

    int mid = (l + r) / 2;
    down(id, l, r);

    update(id * 2, l, mid, u, v, k);
    update(id * 2 + 1, mid + 1, r, u, v, k);
    merge(id);
}

ll getSum0(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id].val0;
    int mid = (l + r) / 2;
    down(id, l, r);

    return getSum0(id * 2, l, mid, u, v) + getSum0(id * 2 + 1, mid + 1, r, u, v);
}


ll getSum1(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id].val1;
    int mid = (l + r) / 2;
    down(id, l, r);

    return getSum1(id * 2, l, mid, u, v) + getSum1(id * 2 + 1, mid + 1, r, u, v);
}

ll getSum(int l, int r) {
    return (r + 1) * getSum0(1, 0, 3000000, l, r) - getSum1(1, 0, 3000000, l, r);
}

ll a[1000006];
vector<int> v[1000005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    FOR (i, 0, n - 1) {
        cin >> a[i];
        v[a[i]].pb(i);
    } 

    ll res = 0;

    FOR (i, 0, k - 1) {
        v[i].pb(n + 1);
        int cnt = 0;
        for (int j = 0; j + 1 < v[i].size(); j++) {
            cnt++;
            res += getSum(2 * cnt - v[i][j + 1] + v[i][j] + 1200000, 2 * cnt - 1 + 1200000);
            res += getSum0(1, 0, 3000000, 1200000, 2 * cnt - v[i][j + 1] + v[i][j] + 1200000 - 1) * (v[i][j + 1] - v[i][j]);
            update(1, 0, 3000000, v[i][j] + 1200000, v[i][j + 1] + 1200000 - 1, 1);
        }
        cout << res << "\n";
        res = 0;
        for (int j = 0; j + 1 < v[i].size(); j++) {
            update(1, 0, 3000000, v[i][j] + 1200000, v[i][j + 1] + 1200000 - 1, -1);
        }
    }



    return 0;
}