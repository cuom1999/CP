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

    int t;
    cin >> t;
    FOR (z, 1, t) {
        ll a, b, c, r;
        cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        ll a1 = c - r, b1 = c + r;
        ll res = 0;
        if (a1 >= a && b1 <= b) {
            res = a1 - a + b - b1;
        }
        else if (a1 >= b || b1 <= a) {
            res = b - a;
        }
        else if (a1 < a && b1 > b) {
            res = 0;
        }
        else res = max(a1 - a, b - b1);
        cout << res << "\n";
    }

    return 0;
}