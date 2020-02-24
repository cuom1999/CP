#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

ll calc2(ll p, ll q, ll n);

ll calc(ll p, ll q, ll n) {
    if (p == 0 || n == 0) return 0;
    if (p > q) return calc(p % q, q, n);

    if (n >= q) {
        ll k = n / q;
        return calc(p, q, n % q) + k * q * (q - 1) / 2;
    }


    ll m = p * n / q;

    ll sum = m * n - calc2(q, p, m) + m / p;
    
    ll sum1 = 0;

    FOR (i, 1, n) {
        sum1 += p * i / q;
    }

    return p * n * (n + 1) / 2 - q * sum;
}

ll calc2(ll p, ll q, ll n) {
    if (n == 0) return 0;
    return (p * n * (n + 1) / 2 - calc(p, q, n)) / q;
}

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));

    int t;
    cin >> t;

    FOR(z, 1, t) {
    	ll p, q, n;

    	cin >> p >> q >> n;

        ll d = __gcd(p, q);
        cout << d * calc(p / d, q / d, n) << endl;

    }
    
	
    return 0;
}