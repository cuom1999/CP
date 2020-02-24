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

ll d[105][105][105];
int a[105];
int n, k;

ll dp(int i, int j, int val) {
    if (d[i][j][val] != -1) return d[i][j][val];
    if (i == n + 1) {
        if (j <= k) {
            return 0;
        }
        else return 1e15;
    }
    ll &res = d[i][j][val];
    if (val == a[i]) {
        res = dp(i + 1, j, val);
    }
    else {
        res = min(dp(i + 1, j + 1, a[i]), dp(i + 1, j, val) + 1);
    }
    // cout << i << " " << j << " " << val << " " << res << endl;
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t) {
        cout << "Case #" << z << ": ";
        cin >> n >> k;

        vector<II> v;

        FOR (i, 1, n) {
            cin >> a[i];
            v.pb({a[i], i});
        }

        sort(all(v));

        int cur = 0;
        FOR (i, 0, n - 1) {
            if (!i || v[i].first != v[i - 1].first) cur++;
            a[v[i].second] = cur;
        }   

        memset(d, -1, sizeof(d));

        ll res = 1e18;
        FOR (i, 1, n) {
            res = min(res, dp(1, 0, i));
        }

        cout << res << "\n";
    }





    return 0;
}