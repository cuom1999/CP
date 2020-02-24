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
typedef pair < ll, ll > II;

ll s[300005], a[300005];
ll m, k;

ll calc(int l, int r) {
	// cout << l << " " << r << endl;
	if (l == -1) return 0;
	if (l >= r) return 0;
	return s[r] - s[l] - k * ((r - l - 1) / m + 1);
}

// vector<II> v[15];
II mi[15];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n >> m >> k;

	FOR (i, 1, n) cin >> a[i];

	FOR (i, 1, n) {
		s[i] = s[i - 1] + a[i];
	}

	FOR (i, 0, m - 1) {
		mi[i] = {1e18, -1};
	}

	ll res = 0;
	FOR (i, 0, n) {
		FOR (j, 0, m - 1) {
			res = max(res, calc(mi[j].second, i));
		}

		mi[i % m] = min(mi[i % m], II(m * s[i] - k * i, i));
	}
	cout << res << endl;

	return 0;
}