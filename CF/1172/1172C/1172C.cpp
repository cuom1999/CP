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

ll d[55][55][55][55], inv[5305];
int isLiked[55], weight[55];
int n, m, total;
ll a, b;

ll calc(int w, int A, int B, int m, int i) {
	if (w * isLiked[i] + weight[i] < 0 || A + a < 0 || b - B < 0) return 0;
	// cout << w * isLiked[i] + weight[i] << " " << A + a << " " << b - B << endl;
	if (m == 0) {
		return w * isLiked[i] + weight[i];
	}
	if (d[w][A][B][m] != -1) return d[w][A][B][m];

	ll deno = inv[w * isLiked[i] + A - B + weight[i] + a + b];
	ll res = 0;

	res += (A + a) * calc(w, A + 1, B, m - 1, i) % K;
	res %= K;
	// cout << res << endl;

	res += (b - B) * calc(w, A, B + 1, m - 1, i) % K;
	res %= K;

	res += (weight[i] + w * isLiked[i]) * calc(w + 1, A, B, m - 1, i) % K;
	res %= K;
	// cout << w << " " << res << endl;

	res = res * deno % K;
	// cout << w << " " << A << " " << B << " " << m << " " << res << endl;
	return d[w][A][B][m] = res % K;
}

ll solve(int i) {
	memset(d, -1, sizeof(d));
	a = 0, b = 0;
	FOR (j, 1, n) {
		if (j == i) continue;
		if (isLiked[j] == 1) {
			a += weight[j];
		}
		else {
			b += weight[j];
		}
	}
	return calc(0, 0, 0, m, i);
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	FOR (i, 1, 5300) {
		inv[i] = mu(i, K - 2);
	}

	cin >> n >> m;

	FOR (i, 1, n) {
		cin >> isLiked[i];
		if (!isLiked[i]) isLiked[i] = -1;
	}

	FOR (i, 1, n) {
		cin >> weight[i];
	}

	// cout << solve(1) << endl;

	FOR (i, 1, n) {
		cout << solve(i) << endl;
	}
	return 0;
}