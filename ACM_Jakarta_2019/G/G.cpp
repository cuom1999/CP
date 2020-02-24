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

int st[400005], data[100005];
int lz[400005];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = data[l];
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

void down(int id, int l, int r) {
    if (l == r || !lz[id]) {
        return;
    } 

    st[id * 2] += lz[id];
    st[id * 2 + 1] += lz[id];
    lz[id * 2] += lz[id];
    lz[id * 2 + 1] += lz[id];

    lz[id] = 0;
} 

void update(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u || u > v) return;
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

int getMax(int id, int l, int r, int u, int v) {
    if (v < l || r < u || u > v) return -INF;
    if (u <= l && r <= v) return st[id];

    down(id, l, r);
    int mid = (l + r) / 2;
    return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n + 1);
    FOR (i, 1, n) {
        cin >> a[i];
    }

    vector<int> rank(m + 1);
    vector<int> r(m + 1);
    vector<int> s[100005];

    FOR (i, 2, n) {
        if (a[i] > a[1]) {
            rank[0]++;
        }
    }

    FOR (i, 1, m) {
        rank[i] = rank[i - 1];
        cin >> r[i];
        s[i].resize(r[i] + 1);

        FOR (j, 1, r[i]) {
            cin >> s[i][j];
            if (s[i][j] > a[1]) {
                rank[i]++;
            }
        }
    }


    FOR (i, 1, m) {
        data[i] = rank[i - 1] + r[i];
    }

    build(1, 1, m);

    FOR (zz, 1, q) {
        int x, y, z;
        cin >> x >> y >> z;
        if (s[x][y] > a[1] && z < a[1]) {
            update(1, 1, m, x + 1, m, -1);
        }
        if (s[x][y] < a[1] && z > a[1]) {
            update(1, 1, m, x + 1, m, 1);
        }
        s[x][y] = z;
        // FOR (i, 1, m) {
        //     cout << getMax(1, 1, m, i, i) << " ";
        // }
        // cout << endl;
        if (st[1] >= n) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
    }

    return 0;
}