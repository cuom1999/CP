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

typedef pair < int, ll > II;
typedef pair < ll, ll > pll;

vector<II> adj[200005];
int sub[200005];
ll w[200005];

void dfs(int a, int par) {
    sub[a] = 1;
    for (auto i: adj[a]) {
        if (i.first == par) continue;
        w[i.first] = i.second;
        dfs(i.first, a);
        sub[a] += sub[i.first];  
    }
}   

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    FOR (z, 1, t) {
        int k;
        cin >> k;
        int n = 2 * k;
        FOR (i, 1, n) adj[i].clear();
        FOR (i, 1, n - 1) {
            int x, y;
            ll c;
            cin >> x >> y >> c;
            adj[x].pb({y, c});
            adj[y].pb({x, c});
        }
        dfs(1, 0);
        ll minCost = 0;
        ll maxCost = 0;
        FOR (i, 1, n) {
            if (sub[i] % 2) {
                minCost += w[i];
            }
            maxCost += min(sub[i], n - sub[i]) * 1ll * w[i];
        }
        cout << minCost << " " << maxCost << "\n";
    }

    return 0;
}