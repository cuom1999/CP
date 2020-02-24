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
    if (n == 0) {
        return 1;
    }
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

ll d[5005][5005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n, m;
    int k;
    cin >> n >> m >> k;

    d[1][1] = n;
    FOR (i, 2, k) {
        for (int j = 1; j <= n && j <= i; j++) {
            d[i][j] = (n - j + 1) * d[i - 1][j - 1] % MOD + j * d[i - 1][j] % MOD;
            d[i][j] %= MOD;
        }
    }
    // FOR (i, 1, k) {
    //     cout << d[2][i] << " ";
    // }
    // cout << endl;

    ll res = 0;
    ll inv = pw(m, MOD - 2);
    FOR (i, 1, k) {
        res = (res + d[k][i] * pw(inv, i) % MOD) % MOD; 
    }
    cout << res << endl;
    return 0;
}