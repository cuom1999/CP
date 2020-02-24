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

vector<II> adj[100005], edges;
vector<int> cycle[100005], child;

int vs[100005], val[100005], par[100005], anc[100005], backEdge[100005];

void dfs(int a, int p = 0) {
    vs[a] = 1;
    if (p == 1) {
        anc[a] = a;
        child.pb(a);
    }
    if (p > 1) {
        anc[a] = anc[p];
    }
    for (auto i: adj[a]) {
        if (!vs[i.first]) {
            val[i.first] = i.second ^ val[a];
            dfs(i.first, a);
        }
        else if (p != i.first && i.first < a) {
            // cout << "cycle " << i.first << " " << a << " " << anc[a] << endl;
            if (i.first == 1) {
                backEdge[anc[a]] = i.second ^ val[a];
            }   
            else {
                cycle[anc[a]].pb(val[i.first] ^ val[a] ^ i.second);
            }
        }
    }
}

vector<int> basis(vector<int>& v) {
    vector<int> res;
    for (auto i: v) {
        for (auto j: res) {
            i = min(i, i ^ j);
        }
        if (i) {
            // cout << i << endl;
            res.pb(i);
        }
    }
    // cout << res.size() << endl;
    sort(all(res));
    return res;
}
const ll MOD = 1e9 + 7;
map<vector<int>, ll> dp[100005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    FOR (i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    memset(backEdge, -1, sizeof(backEdge));
    dfs(1);

    int ind = 0;
    dp[0][{}] = 1;

    for (auto i: child) {
        ind++;
        dp[ind] = dp[ind - 1];
        vector<int> bas = basis(cycle[i]);
        if (backEdge[i] != -1) {
            if (bas.size() == cycle[i].size()) {
                for (auto cc: dp[ind - 1]) {
                    vector<int> c = cc.first;
                    vector<int> old = c;
                    for (auto j: bas) {
                        c.pb(j);
                    }
                    vector<int> curBasis = basis(c);
                    if (curBasis.size() == c.size()) {
                        dp[ind][curBasis] += 2 * dp[ind - 1][old];
                        dp[ind][curBasis] %= MOD;
                    }
                }
            }
            bas.pb(backEdge[i]);
            vector<int> bas1 = basis(bas);
            if (bas1.size() == cycle[i].size() + 1) {
                bas = bas1;
                for (auto cc: dp[ind - 1]) {
                    vector<int> c = cc.first;
                    vector<int> old = c;
                    for (auto j: bas) {
                        c.pb(j);
                    }
                    vector<int> curBasis = basis(c);
                    if (curBasis.size() == c.size()) {
                        dp[ind][curBasis] += 2 * dp[ind - 1][old];
                        dp[ind][curBasis] %= MOD;
                    }
                }
            }
        }
        else {
            if (bas.size() == cycle[i].size()) {
                for (auto cc: dp[ind - 1]) {
                    vector<int> c = cc.first;
                    vector<int> old = c;
                    // cout << c.size() << " " << bas.size() << endl;
                    for (auto j: bas) {
                        c.pb(j);
                    }
                    vector<int> curBasis = basis(c);
                    // cout << curBasis.size() << endl;
                    // cout << c.size() << endl;
                    if (curBasis.size() == c.size()) {
                        dp[ind][curBasis] += dp[ind - 1][old];
                        dp[ind][curBasis] %= MOD;
                    }
                }
            }
        }
        // cout << child[ind - 1] << ": \n";
        // for (auto i: dp[ind]) {
        //     for (auto j: i.first) {
        //         cout << j << " ";
        //     }
        //     cout << " = " << i.second << endl;
        // }
    }
    // cout << dp[1][{1, 2, 8}] << endl;
    ll res = 0;
    for (auto i: dp[child.size()]) {
        res = (res + i.second) % MOD;
    }
    cout << res << endl;

    return 0;
}