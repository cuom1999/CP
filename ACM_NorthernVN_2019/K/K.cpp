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

ll d[2005][2005][2];

vector<II> in[2005];
int n;

ll dp(int pos, int farthest, int numPeople) {
    // cout << pos << " " << farthest << " " << numPeople << endl;
    ll &res = d[pos][farthest][numPeople]; 
    if (res != -1) return res;

    if (numPeople == 0) {
        if (pos == n) return 0;
        res = max(res, dp(pos + 1, 0, 0));
        int m = in[pos].size();
        FOR (i, 0, m - 1) {
            res = max(res, dp(pos + 1, in[pos][i].first, 1) + in[pos][i].second);
        }
        FOR (i, 0, m - 1) {
            FOR (j, i + 1, m - 1) {
                II u = II(in[pos][i].first, in[pos][j].first);
                if (u.first > u.second) swap(u.first, u.second);
                res = max(res, dp(u.first, u.second, 1) + in[pos][i].second + in[pos][j].second);
            }
        }
    }
    if (numPeople == 1) {
        if (pos < n && pos < farthest) res = max(res, dp(pos + 1, farthest, 1));
        if (pos == farthest) {
            res = max(res, dp(pos, 0, 0));
        }
        else {
            int m = in[pos].size();
            FOR (i, 0, m - 1) {
                auto u = II(in[pos][i].first, (ll) farthest);
                if (u.first > u.second) swap(u.first, u.second);
                res = max(res, dp(u.first, u.second, 1) + in[pos][i].second);
            }
        }
    }
    //cout << pos << " " << farthest << " " << numPeople << " " << res << endl;
    return res;
}

int main()
{//IN; OUT;
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
        FOR (i, 1, n) {
            FOR (j, 0, n) {
                FOR (k, 0, 1) d[i][j][k] = -1;
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