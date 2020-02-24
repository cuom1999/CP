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

const ll MOD = 998244353;

ll fact[1000005];

ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

ll numTree(int n) {
    if (n == 1) return 1;
    return pw(n, n - 2);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    fact[0] = 1;
    FOR (i, 1, n) {
        fact[i] = fact[i - 1] * i % MOD;
    }   

    if (n % 2) {
        cout << 0 << endl;
        return 0;
    }

    ll res = fact[n] * pw(fact[n / 2], MOD - 2) % MOD * numTree(n / 2) % MOD;
    res = res * pw(numTree(n), MOD - 2) % MOD;
    res = res * pw(pw(2, n / 2), MOD - 2) % MOD;
    res = res * pw(4, n / 2 - 1) % MOD;
    if (n % 4) res = (MOD - res) % MOD;
    cout << res << endl;


    return 0;
}