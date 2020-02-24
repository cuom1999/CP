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

int st[MAXN * 4], lz[MAXN * 4];
int a[MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void down(int id, int l, int r) {
    if (l == r || lz[id] == 0) {
        return;
    }
    st[id * 2] = lz[id];
    lz[id * 2] = lz[id];
    st[id * 2 + 1] = lz[id];
    lz[id * 2 + 1] = lz[id];
    lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int c) {
    if (v < l || r < u) {
        return;
    }

    if (u <= l && r <= v) {
        st[id] = c;
        lz[id] = c;
        return;
    }

    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, c);
    update(id * 2 + 1, mid + 1, r, u, v, c);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
} 

int get(int id, int l, int r, int u) {
    if (l == r) {
        return st[id];
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    if (u <= mid) {
        return get(id * 2, l, mid, u);
    }
    return get(id * 2 + 1, mid + 1, r, u);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    build(1, 1, n);

    FOR (z, 1, q) {
        int l, r, c;
        cin >> l >> r >> c;
        assert(c >= 1);
        update(1, 1, n, l, r, c);
    }

    FOR (i, 1, n) {
        cout << get(1, 1, n, i) << " ";
    }

    return 0;
}