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

const int MAXN = 200005;
const ll K = 1e9 + 7;
ll fact[MAXN], rev[MAXN];

ll pw(ll a, ll n) {
	if (n == 0) return 1;
	ll q = pw(a, n / 2);
	if (n % 2 == 0) {
		return q * q % K;
	}
	return q * q % K * a % K;
}

ll combi(int n, int k) {
	if (n < k || k < 0) return 0;
	return fact[n] * rev[n - k] % K * rev[k] % K;
}

ll s[MAXN];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = rev[0] = 1;
	FOR (i, 1, 200000) {
		fact[i] = fact[i - 1] * i % K;
		rev[i] = pw(fact[i], K - 2);
	}

	int n;
	ll T;

	cin >> n >> T;

	FOR (i, 1, n) {
		ll x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}

	int cur = -1;

	ll curSum = 0;
	ll res = 0;
	ll inv2 = pw(2, K - 2);
	ll pw2  = pw(pw(2, n), K - 2);

	FORD (i, n, 1) {
		ll u = min(T - s[i], (ll) i);
		if (u >= 0) {

			curSum = (curSum + combi(i, cur)) * inv2 % K;

			FOR (j, cur + 1, u) {
				curSum = (curSum + combi(i, j)) % K;
			}
			cur = u;

			// cout << i << " " << cur << " " << curSum << endl;
		}
		
		res += pw2 * curSum % K;
		pw2 = pw2 * 2 % K;
		res %= K;
	}

	cout << res << endl;

	return 0;
}