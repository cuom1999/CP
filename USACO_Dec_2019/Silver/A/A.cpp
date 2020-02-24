#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("moobuzz.in","r",stdin)
#define OUT freopen("moobuzz.out","w",stdout)
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

ll calc(ll n) {
    return n - n / 3 - n / 5 + n / 15;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int pos;
    cin >> pos;

    ll lower = 1, upper = 2 * INF;
    while (lower < upper) {
        ll mid = (lower + upper) / 2;
        if (calc(mid) >= pos) {
            upper = mid;
        }
        else lower = mid + 1;
    }
    cout << lower << endl;

    return 0;
}