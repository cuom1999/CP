#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("milkvisits.in","r",stdin)
#define OUT freopen("milkvisits.out","w",stdout)
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

vector<int> adj[100005];
int h[100005], p[100005][20], in[100005], out[100005];

struct Query {
    int u, v, index;
};

int TIME = 0;
vector<int> eulerTour;
void dfs(int a, int par) {
    in[a] = ++TIME;
    eulerTour.pb(a);
    h[a] = h[par] + 1;
    p[a][0] = par;
    for (auto i: adj[a]) {
        if (i == par) continue;
        dfs(i, a);
    }
    out[a] = ++TIME;
    eulerTour.pb(a);
}

void init(int n){
    FOR (i,1,18){
        FOR (j,1,n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
//remember h[1]=1
int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,17,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,17,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,17,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}

int fen[200005];
void add(int u, int v) {
    for (int i = u; i <= 200000; i += i & -i) {
        fen[i] += v;
    }
}

int getSum(int u) {
    int res = 0;
    for (int i = u; i; i -= i & -i) {
        res += fen[i];
    }
    return res;
}

void addTree(int u, int v) {
    add(in[u], v);
    add(out[u] + 1, -v);
}

int getNode(int u) {
    if (!u) return 0;
    return getSum(in[u]);
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<int> type[100005];
    vector<Query> queries[100006];
    FOR (i, 1, n) {
        int x;
        cin >> x;
        type[x].pb(i);
    }

    FOR (i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    FOR (i, 1, m) {
        int u, v, t;
        cin >> u >> v >> t;
        queries[t].pb({u, v, i});
    }
    eulerTour.pb(0);
    dfs(1, 0);
    init(n);


    vector<int> ans(m + 1);

    FOR (z, 1, n) {
        for (auto i: type[z]) {
            addTree(i, 1);
        }
        
        for (auto q: queries[z]) {
            int k = LCA(q.u, q.v);
            int k1 = p[k][0];

            int val = getNode(q.u) + getNode(q.v) - getNode(k) - getNode(k1);
            if (val) ans[q.index] = 1;
        }
        for (auto i: type[z]) {
            addTree(i, -1);
        }
    }

    FOR (i, 1, m) cout << ans[i];

    return 0;
}