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

const int MAXN = 1000005;
const int K = 11092019;
int ver[4 * MAXN];
int nVer;
int nNode;

struct Node{
    int max;
    int count;
    int left, right;
}st[4 * 20 * MAXN];

void refine (int id){
    int l = st[id].left;
    int r = st[id].right;
    if (st[l].max > st[r].max) {
        st[id].max = st[l].max;
        st[id].count = st[l].count;
    }
    else if (st[l].max < st[r].max) {
        st[id].max = st[r].max;
        st[id].count = st[r].count;
    }
    else {
        st[id].max = st[r].max;
        st[id].count = (st[l].count + st[r].count) % K;
    }
    // cout << id << " " << st[id].max << " " << st[id].count << endl;
}

int update(int oldId, int l, int r, int u, int x, int y){
    if (l == r) {
        ++nNode;
        // cout << nNode << " " << l << " " << r << " " << x << " " << y << endl;
        st[nNode].max = x;
        st[nNode].count = y;
        st[nNode].left = st[nNode].right = 0;
        return nNode;
    }
    int mid = (l + r) / 2;
    int cur = ++nNode;

    if (u <= mid){
        st[cur].left = update(st[oldId].left, l, mid, u, x, y);
        st[cur].right = st[oldId].right;
    }
    else{
        st[cur].right=update(st[oldId].right, mid+1, r, u, x, y);
        st[cur].left=st[oldId].left;
    }
    refine (cur);
    return cur;
}

II get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return II(0, 0);
    // cout << id << " " << l << " " << r << endl;
    if (u <= l && r <= v) {
        return II(st[id].max,st[id].count);
    }
    int mid=(l+r)/2;
    II A = get(st[id].left,l, mid, u,v);
    II B = get(st[id].right,mid+1,r,u,v);
    if (A.first > B.first) {
        return A;
    }
    if (A.first < B.first) {
        return B;
    }
    return {A.first, (A.second + B.second) % K};
}

int a[MAXN];
vector<int> adj[MAXN];
int id[MAXN], val[MAXN], cnt[MAXN];


void dfs(int u, int par) {
    auto res = get(id[par], 0, 1000000, 0, a[u]);
    val[u] = res.first + 1;
    cnt[u] = res.second;
    id[u] = update(id[par], 0, 1000000, a[u], val[u], cnt[u]);
    for (auto i: adj[u]) {
        if (i == par) continue;
        dfs(i, u);
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> a[i];
    }
    FOR (i, 2, n) {
        int p;
        cin >> p;
        adj[p].pb(i);
        adj[i].pb(p);
    }
    id[0] = update(0, 0, 1000000, 0, 0, 1);

    dfs(1, 0);
    int lis = 0;

    FOR (i, 1, n) {
        lis = max(lis, val[i]);
    }
    ll res = 0;
    FOR (i, 1, n) {
        if (val[i] == lis) {
            res = (res + cnt[i]) % K;
        }
    }
    cout << lis << " " << res << endl;

    return 0;
}