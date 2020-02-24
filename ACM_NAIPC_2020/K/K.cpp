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

vector<int> adj[200005];
int p[200005][20], h[200005];

void dfs(int a, int par) {
    h[a] = h[par] + 1;
    p[a][0] = par;
    for (auto i: adj[a]) {
        if (i == par) continue;
        dfs(i, a);
    }
}


void init(int n){
    FOR (i,1,19){
        FOR (j,1,n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
//remember h[1]=1
int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,18,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,18,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,18,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    FOR (i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
    init(n);

    FOR (z, 1, q) {
        int u, v;
        cin >> u >> v;
        int k = LCA(u, v);
        // cout << h[u] + h[v] - 2 * h[k] << endl;
        ll len = h[u] + h[v] - 2 * h[k];
        cout << n + len * (len + 1) / 2 << "\n";
    }


    return 0;
}