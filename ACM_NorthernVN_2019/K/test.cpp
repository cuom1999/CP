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
typedef pair < ll, ll > II;

ll d[105][105][105];
vector<II> in[2005];
int n;


ll dp(int pos, int a, int b) {
    if (a > b) return dp(pos, b, a);
    if ((a && a < pos) || (b && b < pos)) return -1e18;
    // cout << pos << " " << a << " " << b << endl;
    ll &res = d[pos][a][b];
    if (res != -1) return res;

    if (pos == n) {
        if (a == 0 && b == 0) {
            return 0;
        }
    }
    res = max(res, dp(pos + 1, a, b));
    if (a == pos) {
        res = max(res, dp(pos, 0, b));
    }
    if (b == pos) {
        res = max(res, dp(pos, 0, a));
    }

    if (a == 0 && b == 0) {
        int m = in[pos].size();
        FOR (i, 0, m - 1) {
            res = max(res, dp(pos + 1, 0, in[pos][i].first) + in[pos][i].second);
        }
        FOR (i, 0, m - 1) {
            FOR (j, i + 1, m - 1) {
                res = max(res, dp(pos + 1, in[pos][i].first, in[pos][j].first) + in[pos][i].second + in[pos][j].second);
            }
        }
    }
    else if (a == 0) {
        int m = in[pos].size();
        FOR (i, 0, m - 1) {
            res = max(res, dp(pos + 1, in[pos][i].first, b) + in[pos][i].second);
        }
    }
    // cout << 1 << endl;
    // cout << res << endl;
    res = max(res, 0LL);
    // cout << pos << " " << a << " " << b << " " << res << endl;
    return res;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
        int m;
        cin >> n >> m;
        FOR (i, 1, n) {
            in[i].clear();
        }
        FOR (i, 0, n) {
            FOR (j, 0, n) {
                FOR (k, 0, n) d[i][j][k] = -1;
            }
        }
        FOR (i, 1, m) {
            int a, b;
            ll c;
            cin >> a >> b >> c;
            in[a].pb({b, c});
        }
        cout << dp(1, 0, 0) << "\n";
    } 
    return 0;
}