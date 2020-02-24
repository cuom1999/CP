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

const ll K = 998244353;

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);
	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}
int dd[200005];
int p[200005];
int s[200005];
int a[200005];
int fen[200005];
int m;

void add(int u, int v) {
	for (int i = u; i <= 200000; i += i & -i) {
		fen[i] += v;
	}
}

int get(int u) {
	int res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 	int n;
 	cin >> n;
 	int cnt = 0;
 	FOR (i, 1, n) {
 		cin >> p[i];   
 		if (p[i] > 0) dd[p[i]] = 1;
 		else {
 			cnt++;
 		}
 	}
	FOR (i, 1, n) {
		if (dd[i] == 0) {
			s[i] = s[i - 1] + 1;
		}
		else s[i] = s[i - 1];
	}
	ll P = 0, Q = 0;

	int cnt1 = 0;
	ll den = mu(cnt, K - 2);
	FOR (i, 1, n) {
		if (p[i] == -1) {
			cnt1++;
		}
		else {
			int u = cnt - cnt1;
			P = (P + u * 1ll * s[p[i]] % K * den % K) % K;
			P = (P + cnt1 * 1ll * (cnt - s[p[i]]) % K * den % K) % K;
		}
	}
	P = (P + cnt * 1ll * (cnt - 1) % K * mu(4, K - 2) % K) % K;
	FOR (i, 1, n) {
		if (p[i] > 0) {
			a[++m] = p[i];
		}
	}
	ll P1 = 0;
	FORD (i, m, 1) {
		P1 = (P1 + get(a[i])) % K;
		add(a[i], 1);
	}
	P = (P + P1) % K;

	cout << P << endl;



	return 0;
}