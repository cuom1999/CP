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

int w[100005], sum[100005], h[100005], p[100005][20];
vector<int> adj[100005];

void dfs(int a, int par) {
    sum[a] = sum[par] + w[a];
    h[a] = h[par] + 1;
    p[a][0] = par;
    for (auto i: adj[a]) {
        if (i == par) continue;
        dfs(i, a);
    }
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

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    FOR (i, 1, n) {
        char c;
        cin >> c;
        if (c == 'H') {
            w[i] = 1;
        }
    }

    FOR (i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs(1, 0);
    init(n);

    FOR (z, 1, m) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        int k = LCA(u, v);
        int s = sum[u] + sum[v] - 2 * sum[k] + w[k];
        if (c == 'H' && s) {
            cout << 1;
        }
        else if (c == 'G' && s < h[u] + h[v] - 2 * h[k] + 1) {
            cout << 1;
        }
        else cout << 0;
    }

    return 0;
}