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

int n, g, k;
ll a[100005], s[100005], s2[100005];

ll cost(int x, int y) {
    if (k == 1) {
        int m = (x + y) / 2;
        return (m - x + 1 - y + m) * a[m] - (s[m] - s[x - 1] - s[y] + s[m]);
    }
    else {
        ll u = (s[y] - s[x - 1]) / (y - x + 1);
        auto f = [&](ll u) {
            return (y - x + 1) * u * u - 2 * (s[y] - s[x - 1]) * u + s2[y] - s2[x - 1];
        };
        return min(f(u), f(u + 1));
    }
}

ll d[100005];
int cnt[100005];
// each segment is increased x
II solve(ll x) {
    FOR (i, 1, n) {
        d[i] = 1e18;
        int opt = -1;
            
        FOR (j, 0, i - 1) {
            ll val = d[j] + cost(j + 1, i) + x;

            if (val < d[i]) {
                d[i] = val;
                opt  = j;
            }           
        }
        cnt[i] = cnt[opt] + 1;
    }
    return {cnt[n], d[n]};
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);  

    cin >> n >> g >> k;

    FOR (i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        s2[i] = s2[i - 1] + a[i] * a[i];
    }

    ll L = 0, R = 1e13;
    while (L < R) {
        ll mid = (L + R) / 2;
        if (solve(mid).first <= g) {    
            R = mid;
        }
        else {
            L = mid + 1;
        }
    }
    cout << L << endl;
    cout << solve(L).second - g * L << endl;
    return 0;
}