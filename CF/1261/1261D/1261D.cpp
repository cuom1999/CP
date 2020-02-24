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
ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

ll fact[200005], inv[200005];

ll combi(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD; 
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    fact[0] = inv[0] = 1;
    FOR (i, 1, 200000) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }

    int n;
    ll k;
    cin >> n >> k;
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> h(n + 1);
    FOR (i, 1, n) {
        cin >> h[i];
    }
    int m = 0;
    FOR (i, 1, n - 1) {
        if (h[i] != h[i + 1]) {
            m++;
        }
    }
    if (h[1] != h[n]) m++;

    ll res = 0;

    FOR (i, 0, m / 2) {
        ll val = combi(m, i) * combi(m - i, i) % MOD * pw(k - 2, m - 2 * i) % MOD;
        res = (res + val) % MOD;
    }
    res = res * pw(k, n - m) % MOD;

    ll sum = pw(k, n);
    res = (sum - res + MOD) * pw(2, MOD - 2) % MOD;
    cout << res << endl; 
    return 0;
}