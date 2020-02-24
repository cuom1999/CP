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
ll len[MAXN], p[MAXN];

struct Node {
    ll res, maxSum, leftPos;
} st[4 * MAXN];

void merge(Node& p, Node& left, Node& right) {
    if (left.leftPos == -1) {
        p = right;
        return;
    }
    if (right.leftPos == -1) {
        p = left;
        return;
    }
    p.res = left.res + right.res;
    p.maxSum = max(left.maxSum, right.maxSum);
    p.res += max(0LL, right.leftPos - left.maxSum);
    p.leftPos = left.leftPos;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id].res = 0;
        st[id].maxSum = p[l] + len[l];
        st[id].leftPos = p[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    merge(st[id], st[id * 2], st[id * 2 + 1]);
}

Node query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return {0, 0, -1};
    if (u <= l && r <= v) {
        cout << l << " " << r << " " << st[id].res << endl;
        return st[id];
    }

    int mid = (l + r) / 2;
    Node res;
    Node left = query(id * 2, l, mid, u, v);
    Node right = query(id * 2 + 1, mid + 1, r, u, v); 
    merge(res, left, right);
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> p[i] >> len[i];
    }

    build(1, 1, n);
    int q;
    cin >> q;
    FOR (z, 1, q) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r).res << "\n";
    }


    return 0;
}