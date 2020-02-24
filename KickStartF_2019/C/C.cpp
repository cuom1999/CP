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

ll d[100005][4]; 
// 0: bright and has light
// 1: bright by children and no light
// 2: dark

ll f[100005]; // max(d[0->2])
ll b[100005];
vector<int> adj[100005];

void dfs(int a, int p) {
    d[a][0] = b[a];
    d[a][1] = -1e18;
    d[a][2] = 0;

    ll sum = 0;

    for (auto i: adj[a]) {
        if (i == p) continue;
        dfs(i, a);

        ll val0 = max(d[i][2] + b[i], d[i][1]);
        val0 = max(val0, d[i][0]);
        d[a][0] += val0;

        d[a][2] += max(d[i][2], d[i][1]);

        sum += f[i];
    }
    
    for (auto i: adj[a]) {
        if (i == p) {
            continue;
        }
        d[a][1] = max(d[a][1], b[a] + d[i][0] + sum - f[i]);
    } 

    f[a] = max(d[a][0], max(d[a][1], d[a][2]));
        
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
        cout << "Case #" << z << ": ";

        int n;
        cin >> n;

        FOR (i, 1, n) {
            adj[i].clear();
            cin >> b[i];
        }

        FOR (i, 1, n - 1) {
            int x, y;
            cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(1, 0);
        ll res = -1e18;
        cout << f[1] << "\n";
    }


    return 0;
}