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
    int n;
    cin >> n;
    int res = 0;
    int a[300005];

    int b = 0, w = 0;
    ll s = 0;
    FOR (i, 1, n) {
        cin >> a[i];
        s += a[i];
        if (i % 2 == 0) {
            b += a[i] % 2;
        }
        else {
            w += a[i] % 2;
        }
    }
    ll r = abs(w - b);
    cout << (s - r) / 2 << endl;


    return 0;
}