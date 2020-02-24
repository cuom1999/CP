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

ll g[200005];
ll suf[200005], sumSuf[200005];

ll calc(int l, int r) {
    ll val = sumSuf[l] - sumSuf[r + 1];
    val = val * pw(suf[r + 1], MOD - 2) % MOD;
    val = (val + MOD) % MOD;
    return val;
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    FOR (i, 1, n) {
        ll p;
        cin >> p;
        g[i] = 100 * pw(p, MOD - 2) % MOD;
    }
    suf[n + 1] = 1;
    sumSuf[n + 1] = 0;
    FORD (i, n, 1) {
        suf[i] = suf[i + 1] * g[i] % MOD;
        sumSuf[i] = (suf[i] + sumSuf[i + 1]) % MOD;
    }

    set<int> checkpoint;

    checkpoint.insert(1);
    checkpoint.insert(n + 1);
    ll res = calc(1, n);
    FOR (z, 1, q) {
        int u;
        cin >> u;
        auto j = checkpoint.find(u);
        if (j == checkpoint.end()) {
            auto ptr = checkpoint.lower_bound(u);
            int next = *ptr;
            int prev = *(--ptr);
            res = res - calc(prev, next - 1);
            res += calc(prev, u - 1) + calc(u, next - 1);
            checkpoint.insert(u);
        }
        else {
            checkpoint.erase(u);
            auto ptr = checkpoint.lower_bound(u);
            int next = *ptr;
            int prev = *(--ptr);
            res = res + calc(prev, next - 1);
            res -= calc(prev, u - 1) + calc(u, next - 1);
        }
        res = (res % MOD + MOD) % MOD;
        cout << res << '\n';
    }

    return 0;
}