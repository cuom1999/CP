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
typedef pair < int, ll > II;

ll t[100005];
vector<II> adj[100005];
ll sub0[100005], sub1[100005], sz[100005], sumT[100005], val[100005];
int p[100005];

void dfs(int a, int par) {
    sz[a] = 1;
    p[a] = par;
    sumT[a] = t[a];
    for (auto i: adj[a]) {
        if (i.first == par) continue;
        dfs(i.first, a);
        val[i.first] = i.second;
        sumT[a] += sumT[i.first];
        sz[a] += sz[i.first];
        sub0[a] += sub0[i.first] + sz[i.first] * i.second;
        sub1[a] += sub1[i.first] + sumT[i.first] * i.second;
    }
}
int vs[100005];
ll sum0[100005], sum1[100005];
int n;

void dfs1(int a) {
    if (vs[a] || a == 0) return;
    vs[a] = 1;
    dfs1(p[a]);
    sum0[a] = sum0[p[a]] + val[a] * (n - 2 * sz[a]);
    sum1[a] = sum1[p[a]] + val[a] * (sumT[1] - 2 * sumT[a]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;

    FOR (i, 1, n) cin >> t[i];
    FOR (i, 1, n - 1) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs(1, 0);
    sum0[1] = sub0[1];
    sum1[1] = sub1[1];
    vs[1] = 1;
    FOR (i, 1, n) dfs1(i);
        

    FOR (i, 1, n) {
        cout << sum0[i] * t[i] + sum1[i] << "\n";
    }

    // cout << sub0[1] * t[1] + sub1[1] << endl;

    return 0;
}