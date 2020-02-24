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

const ll K = 998244353;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll d[4005][2005];
ll gt[4005], rev2[4005];
int n, k;

ll calc2(int u1, int u0) {
	return gt[u1 + 2 * u0] * rev2[u0] % K;
}

int cnt = 0;
ll calc(int i, int u1) {
	if (d[i][u1] != -1) return d[i][u1];
	if (i == n * 2) return 0;
	cnt++;
	int u2 = (i - u1) / 2;
	int u0 = (n - u1 - u2);

	ll res = 0;
	if (u0 >= 1) {
		ll u = calc(i + 1, u1 + 1);

		res = (res + u0 * 1ll * u % K) % K;
	}
	if (u1 >= 1) {
		ll u = calc(i + 1, u1 - 1);

		res = (res + u1 * 1ll * u % K) % K;
	}
	if (u1 >= k) res = (res + calc2(u1, u0)) % K;

	// cout << i << " " << u2 << " " << u1 << " " << u0 << " " << res << endl;
	return d[i][u1] = res;
} 

int main()
{//IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	ll l;
	cin >> n >> k >> l;
	memset(d, -1, sizeof(d));

	gt[0] = 1;
	rev2[0] = 1;
	ll pw2 = 1;
	FOR (i, 1, 4000) {
		gt[i] = gt[i - 1] * 1ll * i % K;
		pw2 = pw2 * 2 % K;
		rev2[i] = mu(pw2, K - 2) % K;
	}

	ll res = calc(0, 0) * mu(calc2(0, n), K - 2) % K;
	res = (res * l % K * mu(2 * n + 1, K - 2) % K);

	cout << res << endl;
    return 0;
}