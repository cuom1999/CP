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

ll MOD;

ll fact[20005], inv[20005];
ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

ll combi(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n >> MOD;

    fact[0] = inv[0] = 1;
    FOR (i, 1, 20000) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }

    int a = (n + 1) / 2;
    int b = (n - 1) / 2;

    vector<ll> cntA(n + 1), cntB(n + 1), prefB(n + 1);
    FOR (i, 1, n) {
        cntA[i] = combi(i - 1 + a - 1, a - 1);
        cntB[i] = combi(i + b - 1, b - 1);
        prefB[i] = (prefB[i - 1] + cntB[i]) % MOD;
    }

    ll res = 0;
    FOR (i, 1, n) {
        FOR(j, 1, i - 1) {
            ll val = cntA[i] * 
        }
    }

    return 0;
}