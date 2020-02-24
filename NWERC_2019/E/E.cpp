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



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll a[5];
    FOR (i, 1, 4) {
        ld x;
        cin >> x;
        a[i] = round(x * 100);
    }

    ll t;
    ld x;
    cin >> x;
    t = round(x * 100);

    sort(a + 1, a + 5);
    ll res = 3 * t - (a[2] + a[3]);

    if (a[2] + a[3] + a[4] <= 3 * t) {
        cout << "infinite";
    }
    else if (a[1] + a[2] + a[3] > 3 * t) {
        cout << "impossible";
    }
    else {
        cout << fixed << setprecision(2) << res / 100.0 << endl;
    }

    return 0;
}