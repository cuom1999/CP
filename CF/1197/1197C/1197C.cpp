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

ll a[300005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	vector<ll> v;

	FOR (i, 1, n - 1) {
		v.pb(a[i + 1] - a[i]);
	}

	sort(all(v));
	reverse(all(v));

	ll res = a[n] - a[1];
	FOR (i, 0, k - 2) {
		res -= v[i];
	}

	cout << res << endl;


	return 0;
}