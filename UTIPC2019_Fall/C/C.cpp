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

const int MAXN = 1e6 + 5;
const ll K = 1e9 + 7;
ll fact[MAXN], rev[MAXN];
ll pw (ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % K;
    return q * q % K * a % K;
}

ll combi(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n] * rev[n - k] % K * rev[k] % K;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    rev[0] = fact[0] = 1;
    FOR (i, 1, n + 1) {
        fact[i] = fact[i - 1] * 1ll * i % K;
        rev[i] = pw(fact[i], K - 2);
    }   

    ll res = 0;

    FOR (k, 1, n) {
        res = (res + k * fact[k + 1] % K * combi(n, k) % K) % K;
    }

    cout << res << endl;
    return 0;
}