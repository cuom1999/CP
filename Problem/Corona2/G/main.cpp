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

const ll MOD = 1e9 + 7;
    
ll pw(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

ll fact[100005];

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    fact[0] = 1;
    FOR (i, 1, n) {
        fact[i] = fact[i - 1] * i % MOD;
    }   

    // k * i + (k + 1) * j = n
    ll res = 0;
    FOR (i, 0, n / k) {
        int rest = n - k * i;
        
        if (rest % (k + 1) == 0) {
            int j = rest / (k + 1);
            ll val = fact[i] * fact[j] % MOD * pw(fact[k], i) % MOD
                    * pw(fact[k + 1], j) % MOD;

            val = pw(val, MOD - 2);
            res = (res + val) % MOD;
        }
    }

    res = res * fact[n] % MOD;
    cout << res << endl;

    return 0;
}