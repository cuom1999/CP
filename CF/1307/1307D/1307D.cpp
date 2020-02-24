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

// for every edge u, v with length c:
// adj[u].push_back(II(v, c));
// adj[v].push_back(II(u, c)); if 2-way edge

typedef pair <int, int> II;

int n; // number of vertices
vector<II> adj[200005];

struct Dijkstra {
    int d[200005]; // will be the shortest dist from a

    priority_queue < II, vector<II>, greater<II> > pq;

    void dijkstra(int a) {
        for (int i = 1; i <= n; i++) {
            d[i] = INF;
        }

        d[a] = 0;

        pq.push(II(0, a));
        while (!pq.empty()) {
            int du = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d[u] != du) continue;
            
            for (auto i: adj[u]){
                int v = i.first;
                int uv = i.second;

                // this v is better
                if (d[v] > du + uv){
                    d[v] = du + uv;
                    pq.push(II(d[v],v)); // push the better one
                }
            }
        }
    }
};
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int m, k;
    cin >> n >> m >> k;

    vector<int> special;
    FOR (i, 1, k) {
        int x;
        cin >> x;
        special.pb(x);
    }

    FOR (i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb({y, 1});
        adj[y].pb({x, 1});
    }

    Dijkstra dij1, dijn;
    dij1.dijkstra(1);
    dijn.dijkstra(n);

    int res = 0;
    FOR (i, 1, 5e6) {
        int u = Rand(0, special.size() - 1);
        int v = Rand(0, special.size() - 1);
        if (u == v) continue;
        u = special[u];
        v = special[v];
        int val = min(dij1.d[n], dij1.d[u] + dijn.d[v] + 1);
        val = min(val, dijn.d[u] + dij1.d[v] + 1);
        res = max(res, val);
    }
    cout << res << endl;
    return 0;
}