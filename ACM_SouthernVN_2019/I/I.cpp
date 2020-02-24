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

void calc(ll &r, ll &g, ll &b, ll n) {
    if (n == 1) {
        return;
    }

    ll par = (n + 1) / 3;
    calc(r, g, b, par);

    ll newR, newG, newB;
    if (n % 3 == 2) {
        newR = r + g;
        newG = b;
        newB = g;
    }
    else if (n % 3 == 0) {
        newR = b;
        newG = b + g;
        newB = r;
    }
    else {
        newR = g;
        newG = r;
        newB = b + r;
    }

    r = newR;
    g = newG;
    b = newB;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll r, g, b;
    ll n;
    cin >> r >> g >> b >> n;

    calc(r, g, b, n);

    cout << r << " " << g << " " << b << endl;

    return 0;
}