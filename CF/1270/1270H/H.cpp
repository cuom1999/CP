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

struct Node {
    int minVal = 0;
    int minCnt = 0;
    int lazy = 0;
} st[4000005];

Node merge(Node& l, Node& r) {
    Node res;
    res.minVal = min(l.minVal, r.minVal);
    if (l.minVal < r.minVal) res.minCnt = l.minCnt;
    else if (l.minVal > r.minVal) res.minCnt = r.minCnt;
    else res.minCnt = l.minCnt + r.minCnt;
    return res;
}

void down(int id, int l, int r) {
    if (!st[id].lazy || l == r) return;
    FOR (j, 0, 1) {
        st[id * 2 + j].lazy += st[id].lazy;
        st[id * 2 + j].minVal += st[id].lazy;
    }
    st[id].lazy = 0;
}

void add(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        st[id].minVal += k;
        st[id].lazy += k;
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    add(id * 2, l, mid, u, v, k);
    add(id * 2 + 1, mid + 1, r, u, v, k);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}
    
void modify(int id, int l, int r, int u, int k) {
    if (l == r) {
        st[id].minVal = k;
        st[id].minCnt = 1;
        return;        
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    if (u <= mid) {
        modify(id * 2, l, mid, u, k);
    }
    else {
        modify(id * 2 + 1, mid + 1, r, u, k);
    }
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 2);
    a[0] = 1e6 + 1;
    FOR (i, 1, n) {
        int x;
        cin >> x;
        a[i] = x;
    }

    int M = 1000000;
    FOR (i, 0, M) {
        modify(1, 0, M, i, INF);
    }

    FOR (i, 1, n) {
        modify(1, 0, M, a[i], 0);
    }

    FOR (i, 1, n + 1) {
        auto u = minmax(a[i], a[i - 1]);
        add(1, 0, M, u.first, u.second - 1, 1);
    }

    FOR (z, 1, q) {
        int pos, x;
        cin >> pos >> x;

        FOR (i, pos, pos + 1) {
            auto u = minmax(a[i], a[i - 1]);
            add(1, 0, M, u.first, u.second - 1, -1);
        }
        
        add(1, 0, M, a[pos], a[pos], INF);
        add(1, 0, M, x, x, -INF);
        a[pos] = x;

        FOR (i, pos, pos + 1) {
            auto u = minmax(a[i], a[i - 1]);
            add(1, 0, M, u.first, u.second - 1, 1);   
        }

        cout << st[1].minCnt << "\n";
    }
    return 0;
}