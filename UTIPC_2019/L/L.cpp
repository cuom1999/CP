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

int a[500005];

const ll K = 998244353;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll fact[500005], rev[500005];
ll pw2[500005];

ll combi(int n, int k) {
	if (n < k || k < 0) return 0;
	return fact[n] * rev[k] % K * rev[n - k] % K;
}

ll calc (int m, int n) {
	ll res = 0;
	FOR (i, 0, m) {
		ll val = mu(pw2[i] - 1, n) * 1ll * combi(m, i) % K;
		if (i % 2) {
			res = (res - val + K) % K;
		}
		else {
			res = (res + val) % K;
		}
	}
	if (m % 2) return (K - res) % K;
	else return res;
}
int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = rev[0] = 1;
	pw2[0] = 1;
	FOR (i, 1, 500000) {
		fact[i] = fact[i - 1] * 1ll * i % K;
		rev[i] = mu(fact[i], K - 2);
		pw2[i] = pw2[i - 1] * 2ll % K;
	} 
	int n;
	cin >> n;

	ll res = 1;
	FOR (i, 1, n) {
		cin >> a[i];
		if (i > 1) res = res * calc(a[i - 1], a[i]) % K;
	}

	cout << res << endl;

	return 0;
}