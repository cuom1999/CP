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

vector<int> adj[MAXN], cc[MAXN];
int vs[MAXN], stable[MAXN], stableComp[MAXN];

void dfs(int u, int c) {
    if (vs[u]) return;
    stableComp[c] |= stable[u];
    vs[u] = 1;
    cc[c].pb(u);

    for (auto i: adj[u]) {
        dfs(i, c);
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        if (u == v) stable[u] = 1;
    }

    int numCC = 0;
    FOR (i, 1, 2 * n) {
        if (!vs[i]) dfs(i, ++numCC);
    }
    ll res = 1;
    const ll MOD = 1e9 + 7;

    FOR (c, 1, numCC) {
        int cntEdge = 0;
        for (auto i: cc[c]) {
            cntEdge += adj[i].size();
        }
        cntEdge /= 2;
        if (cntEdge == cc[c].size()) {
            if (stableComp[c]) continue;
            res = res * 2 % MOD;
        }
        else {
            res = res * cc[c].size() % MOD;
        }
    }

    cout << res << endl;

    return 0;
}