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

int a[55][55];
int d[55][55];

vector<II> bucket[2505];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            cin >> a[i][j];
            bucket[a[i][j]].pb({i, j});
        }
    }

    int res = INF;

    FOR (val, 1, k) {
        for (auto u1: bucket[val]) {
            int i = u1.first;
            int j = u1.second;
            d[i][j] = INF;
            if (val == 1) d[i][j] = 0;

            for (auto u2: bucket[val - 1]) {
                int u = u2.first;
                int v = u2.second;
                if (a[u][v] == val - 1) {
                    d[i][j] = min(d[i][j], d[u][v] + abs(i - u) + abs(j - v));
                }
            }

            if (val == k) {
                res = min(res, d[i][j]);
            }
        }
    }


    if (res == INF) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }



    return 0;
}