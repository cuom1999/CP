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

ll b[3005], w[3005], cost[3005], d[3005];
vector<int> adj[3005];
int remain;
int res;

void dfs(int a, int p) {
    d[a] = cost[a];
    for (auto i: adj[a]) {
        if (i == p) continue;
        dfs(i, a);
        d[a] += d[i];
    }
    if (d[a] > 0 && remain > 1 && p) {
        remain--;
        d[a] = 0;
        res++;
    }
    if (p == 0) {
        if (d[a] > 0) res++;
    }
    cout << d[a] << " " << a << " " << res << endl;
}   

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n, m;
        cin >> n >> m;
        FOR (i, 1, n) {
            adj[i].clear();
            cin >> b[i];
        }
        FOR (i, 1, n) {
            cin >> w[i];
            cost[i] = w[i] - b[i];
        }

        FOR (i, 1, n - 1) {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        remain = m;
        dfs(4, 0);
        return 0;

        int ans = 0;
        FOR (i, 1, n) {
            res = 0;
            remain = m;
            dfs(i, 0);
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }


    return 0;
}