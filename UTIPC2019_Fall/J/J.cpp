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


typedef pair <int, int> II;
typedef pair <ld, int> DI;

vector<II> adj[50005];
ld d[50005]; // will be the shortest dist from a
int n, m; // number of vertices
ld l[50005];
ll g[50005], r[50005], t[50005];

ld nextTime(ld currTime, int road) {
    if (currTime < t[road]) return t[road];
    ll u = (ll) currTime;
    ll v = u - t[road];
    v %= (g[road] + r[road]);
    if (v < g[road]) {
        return currTime;
    }
    else {
        return u + g[road] + r[road] - v;
    }
}

void dijkstra(int a, ld x) {
    priority_queue < DI, vector<DI>, greater<DI> > pq;

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    d[a] = 0;

    pq.push(II(0, a));
    while (!pq.empty()) {
        ld du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (abs(d[u] - du) > 1e-8) continue;
        
        for (auto i: adj[u]) {
            int road = i.second;
            int v = i.first;
            // this v is better
            ld nextT = nextTime(du + l[road] / x, road);
            // if (v == n) {
            //     nextT = du + l[road] / x;
            // }
            if (d[v] > nextT) {
                d[v] = nextT;
                pq.push({d[v], v}); // push the better one
            }
        }
    }
}

ld T;
    
bool solve(ld x) {
    dijkstra(0, x);
    return d[n] <= T;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m >> T;
    
    g[0] = 1e18;
    r[0] = 1;
    adj[0].pb({1, 0});

    FOR (i, 1, m) {
        int x, y;
        cin >> x >> y >> l[i] >> g[i] >> r[i] >> t[i];
        adj[x].pb({y, i});
    }


    ld lower = 0, upper = 1e12;
    FOR (i, 1, 500) {
        ld mid = (lower + upper) / 2;
        if (solve(mid)) upper = mid;
        else lower = mid;
    }
    cout << fixed << setprecision(9) << lower << endl;
    return 0;
}