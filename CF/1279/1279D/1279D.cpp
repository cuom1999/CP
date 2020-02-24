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

vector<int> v[1000005];
int con[1000005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        int k;
        cin >> k;
        FOR (j, 1, k) {
            int x;
            cin >> x;
            v[i].pb(x);
            con[x]++;
        }
    }

    ll res = 0;
    ll inv = pw(n, MOD - 2);
    FOR (i, 1, n) {
        ll val = pw(v[i].size(), MOD - 2) * inv % MOD;
        for (auto j: v[i]) {
            res = (res + val * con[j] % MOD * inv % MOD) % MOD;
        }
    }

    cout << res << "\n";
    return 0;
}