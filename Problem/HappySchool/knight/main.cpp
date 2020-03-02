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

// n (1e5) a b (1e18)
// n lines
// x1 y1 x2 y2

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n, a, b;
    cin >> n >> a >> b;

    ll d = __gcd(a, b);
    a /= d;
    b /= d;

    FOR (i, 1, n) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x2 -= x1;
        y2 -= y1;

        ll x = abs(x2);
        ll y = abs(y2);
        if (x % d || y % d) {
            cout << "NO\n";
        }
        else {
            x /= d;
            y /= d;
            if (a % 2 && b % 2) {
                if ((x + y) % 2 == 0) {
                    cout << "YES\n";
                }
                else {
                    cout << "NO\n";
                }
            }
            else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}