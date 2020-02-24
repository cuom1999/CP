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

int mob[1000005], isComp[1000005];

void sieve(int n) {
    mob[1] = 1;
    FOR (i, 2, n) {
        if (isComp[i]) continue;
        mob[i] = -1;
        FOR (j, 2, n / i) {
            isComp[i * j] = 1;
            if (j % i) mob[i * j] = mob[i] * mob[j];
        }
    }
}

ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int m, k;
    cin >> m >> k;

    ll res = 1;
    sieve(1000000);

    FOR (i, 1, k) {
        ll val = (k / i) * 2 + 1;
        val = pw(val, m);
        val = (val + MOD - 1) % MOD;
        res = (res + val * mob[i]) % MOD;
    }

    res = (res + MOD) % MOD;
    cout << res << endl;

    return 0;
}