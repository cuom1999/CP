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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

const ll K = 1e9 + 7;

const int MAXN = 1000005;

ll fen[MAXN];
int a[MAXN], b[MAXN];
vector<II> v;

void add(int u, ll v) {
	for (int i = u; i <= MAXN - 1; i += i & -i) {
		fen[i] += v;
		fen[i] %= K;
	}
}

ll getSum(int u) {
	ll res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
		res %= K;
	}
	return res;
}

ll c[MAXN], d[MAXN], s[MAXN];


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;

	FOR (i, 1, n) cin >> a[i];
	FOR (i, 1, n) {
		v.pb({a[i], i});
	}

	sort(all(v));

	for (int i = 0; i < v.size(); i++) {
		b[v[i].second] = i + 1;
	}

	FOR (i, 1, n) {
		add(b[i], i);
		c[i] = getSum(b[i] - 1);
	}

	memset(fen, 0, sizeof(fen));

	FORD(i, n, 1) {
		add(b[i], (n + 1 - i));
		d[i] = getSum(b[i] - 1);
	}

	ll res = 0;

	FOR (i, 1, n) {
		s[i] = c[i] * 1ll * (n - i + 1) % K + d[i] * 1ll * i % K + i * 1ll * (n - i + 1) % K;
		res += s[i] * a[i] % K;
		res %= K;
	}

	cout << res << endl;




	return 0;
}