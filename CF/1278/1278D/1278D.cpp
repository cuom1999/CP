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

int vs[500005];
vector<int> adj[500005];

void dfs(int a) {
    vs[a] = 1;
    for (auto i: adj[a]) {
        if (!vs[i]) dfs(i);
    }
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> open[n * 2 + 1], close[n * 2 + 1], time(2 * n + 1);
    if (n == 1) {
        cout << "YES";
        return 0;
    }
    FOR (i, 1, n) {
        int x, y;
        cin >> x >> y;
        open[x].pb(i);
        close[y].pb(i);
        time[i] = x;
    }
    vector<II> edges;
    set<II> active;
    bool isGood = 1;
    FOR (i, 1, 2 * n) {
        for (auto j: open[i]) {
            active.insert({-i, j});
        }
        for (auto j: close[i]) {
            active.erase({-time[j], j});
            for (auto z: active) {
                if (-z.first < time[j]) break;
                edges.pb({j, z.second});
                //cout << j << " " << z.second << endl;
                // cout << j << " " << z.second << " " << z.first << " " << -time[j] << endl;
                if (edges.size() > n - 1) {
                    isGood = 0;
                    break;
                }
            }
            if (!isGood) break;
        }
        if (!isGood) break;
    }

    if (!isGood) cout << "NO\n";
    else {
        vector<int> used(2 * n + 1);
        for (auto i: edges) {
            used[i.first] = 1;
            // cout << i.first << " " << i.second << endl;
            adj[i.first].pb(i.second);
            adj[i.second].pb(i.first);
        }

        FOR (i, 1, n) {
            if (used[i]) {
                dfs(i);
                break;
            }
        }

        int sum = 0;
        FOR (i, 1, n) sum += vs[i];
        if (sum == n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}