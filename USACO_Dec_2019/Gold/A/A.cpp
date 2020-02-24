#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("pump.in","r",stdin)
#define OUT freopen("pump.out","w",stdout)
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

// for every edge u, v with length c:
// adj[u].push_back(II(v, c));
// adj[v].push_back(II(u, c)); if 2-way edge

int n; // number of vertices

struct Dijsktra {
    vector<II> adj[1005];
    int d[1005]; // will be the shortest dist from a
    
    priority_queue < II, vector<II>, greater<II> > pq;
    void addEdge(int u, int v, int c) {
        adj[u].pb({v, c});
        adj[v].pb({u, c});
    }
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

struct Road {
    int u, v, cost, flow;
};

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int m;
    cin >> n >> m;

    vector<Road> roads;
    FOR (i, 1, m) {
        int u, v, c, f;
        cin >> u >> v >> c >> f;
        roads.pb({u, v, c, f});
    }

    sort(all(roads), [](Road a, Road b) {
        return a.flow < b.flow;
    });

    reverse(all(roads));

    ld res = -1;
    FOR (i, 0, m - 1) {
        Dijsktra dij;
        FOR (j, 0, i) {
            dij.addEdge(roads[j].u, roads[j].v, roads[j].cost);
        }
        dij.dijkstra(1);
        int minCost = dij.d[n];
        if (minCost == INF) continue;
        else {
            res = max(res, (ld) roads[i].flow / minCost);
        }
    }

    cout << (ll) (res * 1000000) << endl;


    return 0;
}