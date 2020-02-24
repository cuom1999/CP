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

const int MAXN = 30005;

vector<ll> divisors[MAXN];
ll a[4];

ll calc(int n, ll x) {
    ll p = 1;
    ll res = 0;
    FOR (i, 0, n) {
        res += p * a[i];
        p *= x;
    }

    return res;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 1, 30000) {
        FOR (j, 1, 30000 / i) {
            divisors[i * j].pb(i);
        }
    }

    int t;
    cin >> t;

    FOR (z, 1, t) {
        int n;
        cin >> n;
        FORD(i, n, 0) {
            cin >> a[i];
        }

        ll res = 1e18;
        if (!a[0]) {
            res = 0;
            while (!a[0]) {
                n--;
                FOR (i, 0, n) a[i] = a[i + 1];
            }
        } 
        for (auto i: divisors[abs(a[0])]) {
            if (calc(n, -i) == 0) res = min(res, -i);
            if (calc(n, i) == 0) res = min(res, i); 
        }        

        cout << res << "\n";
    }


    return 0;
}