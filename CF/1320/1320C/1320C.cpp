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

const int MAXN = 200005;

struct Weapon {
    int power;
    ll cost;
} a[MAXN], b[MAXN];

struct Monster {
    int x, y, z;
} monster[MAXN];

ll st[4000005], lz[4000005];
ll init[4000005];

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

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, p;
    cin >> n >> m >> p;

    FOR (i, 1, n) {
        cin >> a[i].power >> a[i].cost;
    }

    FOR (i, 1, m) {
        cin >> b[i].power >> b[i].cost;
    } 

    FOR (i, 1, p) {
        cin >> monster[i].x >> monster[i].y >> monster[i].z;
    }

    sort(b + 1, b + m + 1, [&](Weapon a, Weapon b) {
        return a.power < b.power;
    });

    sort(monster + 1, monster + p + 1, [&](Monster a, Monster b) {
        return a.y < b.y;
    });

    FOR (i, 1, 1000000) {
        init[i] = -1e18;
    }
    FOR (i, 1, n) {
        init[a[i].power] = max(init[a[i].power], -a[i].cost);
    }

    build(1, 1, 1000000);

    ll res = -1e18;
    int j = 1;

    // FOR (k, 1, 10) {
    //     cout << query(1, 1, 1000000, k, k) << " ";
    // }
    // cout << endl;
    FOR (i, 1, m) {
        while (j <= p && monster[j].y < b[i].power) {
            update(1, 1, 1000000, monster[j].x + 1, 1000000, monster[j].z);
            // cout << i << " " << j << endl;
            j++;
        }
        // FOR (k, 1, 10) {
        //     cout << query(1, 1, 1000000, k, k) << " ";
        // }
        // cout << endl;
        // cout << i << " " << st[1] << " " << b[i].cost << endl;
        res = max(res, st[1] - b[i].cost);
    }

    cout << res << endl;


    return 0;
}