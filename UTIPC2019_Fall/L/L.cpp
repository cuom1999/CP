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

ll a[5];
ll b[5];
const ll K = 1e9 + 7;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, p;
    cin >> n >> p;

    a[1] = p;
    b[1] = n / a[1];
    FOR (i, 2, 4) {
        a[i] = a[i - 1] * p;
        b[i] = n / a[i];
    }

    ll res = 0;
    FOR (i, 0, b[2]) {
        FOR (j, 0, b[3]) {
            if (a[2] * i + a[3] * j > n) break;
            FOR (k, 0, b[4]) {
                ll val = a[2] * i + a[3] * j + a[4] * k;
                if (val > n) break;
                res += (n - val) / p + 1;
                res %= K;
            } 
        }
    }
    cout << res << endl;
    return 0;
}