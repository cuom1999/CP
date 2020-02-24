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
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

ll x[70], y[70];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll ax, ay, bx, by;
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;

    int n = 0;
    ll INF = 1e17;
    FOR (i, 1, 69) {
        x[i] = x[i - 1] * ax + bx;
        y[i] = y[i - 1] * ay + by;
        if (x[i] > INF || y[i] > INF) break;
        n = i; 
    }

    ll ans = 0;
    FOR (i, 0, n) {
        ll val = abs(x[i] - xs) + abs(y[i] - ys);      
        if (val > t) continue;
            
        ll res = 1;
        ll old = val;
        FOR (j, i, n - 1) {
            val += abs(x[j + 1] - x[j]) + abs(y[j + 1] - y[j]);
            // cout << i << " " << val << endl;
            if (val > t) break;
            res++;
        }
        ans = max(ans, res);
        val = old;
        res = 1;
        FORD (j, i - 1, 0) {
            val += abs(x[j + 1] - x[j]) + abs(y[j + 1] - y[j]);
            // cout << i << " " << val << endl;
            if (val > t) break;
            res++;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;


    return 0;
}