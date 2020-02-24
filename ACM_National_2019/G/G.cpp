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

ll a[100005];
int n;

ll calc(ll x) {
    ll res = 0;
    FOR (i, 1, n) {
        res += min(abs(a[i]), abs(x - a[i]));
    }

    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    FOR (i, 1, n) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    
    ll lower = 1, upper = n;

    while (lower < upper) {
        ll mid = (lower + upper + 1) / 2;
        if (calc(a[mid]) < calc(a[mid - 1])) {
            lower = mid;
        }
        else {
            upper = mid - 1;
        }
    } 

    cout << calc(a[lower]) << endl;

    return 0;
}