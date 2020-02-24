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

vector<ll> v;
ll s[105], t[105], r[105];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int m, n, p;
    cin >> m >> n >> p;
    FOR (i, 1, m) {
        cin >> s[i];
        t[i] = (p - 1) / s[i] + 1;
    }
    FOR (i, 1, n) {
        cin >> r[i];
    }
    sort(r + 1, r + n + 1);
    
    v.pb(0);

    FOR (i, 1, m) {
        v.pb(1);
    }

    FOR (i, 1, n) {
        ll minVal = 1e18;
        int index = -1;
        vector<ll> val(m + 1);
        FOR (j, 1, m) {
            if (v[j] <= r[i]) {
                val[j] = r[i] + t[j];
            }
            else {
                val[j] = v[j] + t[j];
            }
            if (minVal > val[j]) {
                minVal = val[j];
                index = j;
            }
        }
        // cout << index << " " << minVal << " " << val[index] << endl;
        v[index] = val[index];
        FOR (j, 1, m) cout << v[j] << " ";
        cout << endl;
    }
    ll res = 0;
    for (auto i: v) res = max(res, i);
    cout << res - 1 << endl;

    return 0;
}