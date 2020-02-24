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

vector<int> v;
ll getVal(int l, int r) {
	if (l > r) return 0;
	return upper_bound(all(v), r) - lower_bound(all(v), l);
}

int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		int x;
		cin >> x;
		v.pb(x);
	}

	sort(all(v));
	ll res = 0;

	FOR (i, 0, n - 1) {
		if (v[i] < 0) {
			res += getVal(v[i] + 1, (v[i] - 1) / 2);
			res += getVal((-v[i] + 1) / 2, -2 * v[i]);
		}
		else {
			res += getVal(v[i] + 1, 2 * v[i]);
		}
		// cout << v[i] << " " << res << endl;
	}

	cout << res << endl;



	return 0;
}