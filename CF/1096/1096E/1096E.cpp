#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

ll c[5205][5205];
const ll K = 998244353;

ll inv[5205];

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

ll calc (int m, int d, int S) {
	ll res = 0;
	if (m == 0) {
		if (S == 0) return 1;
		return 0;
	}
	for (int u = 0; u * d <= S && u <= m; u++) {
		ll U = c[m][u] * c[S - u * d + m - 1][m - 1] % K;
		if (u % 2 == 0) {
			res = (res + U) % K;
		}
		else {
			res = (res - U + K) % K;
		}
	}
	return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    c[0][0] = 1;
    inv[0] = 1;
    FOR (i, 1, 5100) inv[i] = mu(i, K - 2);

	FOR (i, 1, 5100) {
		c[i][0] = 1;
		FOR (j, 1, i - 1) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % K;
		}
		c[i][i] = 1;
	}
	int p, r, s;

	cin >> p >> s >> r;
	ll res = 0;
	ll den = 0;
	for (int i = 1; i <= p; i++) {
		ll A = 0;
		for (int d = r; i * d <= s; d++) {
			if (i < p) A = (A + calc(p - i, d, s - d * i)) % K;
			else {
				if (s - i * d == 0) A++;
			}
			//if (i < p) cout << i << " " << d << " " << calc(p - i, d, s - d * i) << " " << mu(c[s - d * i + p - i - 1][p - i - 1], K - 2) % K << endl;
		}
		A = A * inv[i] % K;
		res = (res + A * c[p - 1][i - 1] % K) % K;
	}
	den = c[s - r + p - 1][p - 1];
	cout << res * mu(den, K - 2) % K << endl;

    return 0;
}