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

ll dist[105][105];

struct Event {
    int location;
    ll startTime, endTime, cost;
};

ll d[105][10005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
        int g, n, m;
    cin >> g >> n >> m;

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            if (i != j) dist[i][j] = 1e18;
        }
    }

    FOR (i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        dist[u][v] = dist[v][u] = min(dist[u][v], (ll) c);
    }   

    FOR (k, 1, n) {
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<Event> events;

    FOR (i, 1, g) {
        int v, s, e, c;
        cin >> v >> s >> e >> c;
        events.pb({v, s, e, c});
    }

    int MAX_TIME = 10000;
    FOR (i, 1, n) {
        FOR (j, 0, MAX_TIME) {
            d[i][j] = -1e18;
        }
    }
    FOR (i, 1, n) {
        if (dist[i][1] < 1e18) d[i][dist[i][1]] = 0;
    }
    FOR (t, 1, MAX_TIME) {
        FOR (i, 1, n) {
            d[i][t] = max(d[i][t - 1], d[i][t]);
            // cout << d[i][t] << " ";
        }
        for (auto e: events) {
            FOR (i, 1, n) {
                if (e.startTime >= t + dist[e.location][i]) {
                    d[e.location][e.endTime] = max(d[e.location][e.endTime], d[i][t] + e.cost);
                }
            }
        }
    }  

    ll res = 0;
    FOR (i, 1, n) {
        res = max(res, d[i][MAX_TIME]);
    }
    cout << res << endl;



    return 0;
}