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

typedef pair < ll, int > II;
typedef pair < ll, ll > pll;

int g[50005], vs[50005];
char type[50005];
vector<int> adj[50005], cc[50005];


void dfs(int u, int c) {
    if (vs[u]) return;
    vs[u] = 1;
    cc[c].pb(u);
    for (auto i: adj[u]) dfs(i, c);
}

inline ll cube(ll n) {
    return n * n * n;
}

ll calc(vector<II>& alien, vector<II>& human) {
    ll res = 9e18;

    for (int i = 0; i < alien.size(); i++) {
        auto a = alien[i];
        int u = lower_bound(all(human), II(a.first, 0)) - human.begin();
        FOR (j, max(0, u - 3), min((int)human.size() - 1, u + 3)) {
            auto b = human[j];
            bool isConnected = 0;
            bool hasNonNeighbor = 0;
            map<int, int> isNeighbor;
            
            for (auto k: adj[a.second]) {
                if (k == b.second) isConnected = 1;
                isNeighbor[k] = 1;
            }

            for (auto k: adj[b.second]) {
                if (!isNeighbor[k] && k != a.second) hasNonNeighbor = 1; 
            }

            res = min(res, abs(cube(a.first) - cube(b.first)));
            if (isConnected) {
                res = min(res, abs(cube(a.first - 1) - cube(b.first + 1)));
            }
            else {
                res = min(res, abs(cube(a.first - 1) - cube(b.first)));
            }
            if (hasNonNeighbor) res = min(res, abs(cube(a.first) - cube(b.first + 1)));
        }
    }
    return res;
}

ll solve(vector<int>& component) {
    vector<II> alien, human;
    for (auto i: component) {
        if (type[i] == 'a') {
            alien.pb({g[i], i});
        }
        else {
            human.pb({g[i], i});
        }
    }
    sort(all(alien));
    sort(all(human));

    ll res = 9e18;
    res = min(res, calc(alien, human));
    res = min(res, calc(human, alien));

    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n;

    FOR (i, 1, n) {
        cin >> g[i] >> type[i];
    }

    cin >> m;
    FOR (i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // int numCC = 0;
    // FOR (i, 1, n) {
    //     if (!vs[i]) dfs(i, ++numCC);
    // }

    // ll res = 9e18;
    // FOR (i, 1, numCC) {
    //     res = min(res, solve(cc[i]));
    // }

    vector<int> v;
    FOR (i, 1, n) {
        v.pb(i);
    }
    ll res = solve(v);
    cout << res << endl;

    return 0;
}