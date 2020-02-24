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

ll a[200005];
int n, k;

ll calc (ll x) {
	vector<ll> v;
	FOR (i, 1, n) {
		v.pb(abs(a[i] - x));
	}
	sort(all(v));
	return v[k];
}


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		ll res = 1e18;
		cin >> n >> k;

		FOR (i, 1, n) {
			cin >> a[i];
		}

		FOR (i, a[1], a[n]) {
			res = min(res, calc(i));
			cout << i << " " << calc(i) << endl;
		}

		cout << res << endl;
	}


	return 0;
}