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

ll road[505][505];
ll dist[505][505], dist2[505][505];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, t;
    ll d;
    
    cin >> n >> m >> t >> d;

    vector<int> station;
    station.pb(1);
    FOR (i, 1, t) {
        int x;
        cin >> x;
        station.pb(x);
    }
    station.pb(n);

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            dist[i][j] = 1e15;
        }
        dist[i][i] = 0;
    }

    FOR (i, 1, m) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        dist[x][y] = dist[y][x] = z;
    }

    FOR (k, 1, n) {
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            dist2[i][j] = 1e15;
        }
        dist2[i][i] = 0;
    }

    FOR (i, 0, t + 1) {
        FOR (j, 0, t + 1) {
            if (dist[station[i]][station[j]] <= d) {
                dist2[station[i]][station[j]] = dist[station[i]][station[j]];
            }
        }
    }

    FOR (k, 0, t + 1) {
        FOR (i, 0, t + 1) {
            FOR (j, 0, t + 1) {
                dist2[station[i]][station[j]] = min(dist2[station[i]][station[j]], dist2[station[i]][station[k]] + dist2[station[k]][station[j]]);
            }
        }
    }

    if (dist2[1][n] <= INT_MAX) {
        cout << dist2[1][n];
    }
    else {
        cout << "stuck";
    }

    return 0;
}