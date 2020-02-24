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

int n, m, k, q;
vector<int> v[105];
vector<int> goodCol;

ll dist(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		return abs(y1 - y2);
	}
	if (y1 > y2) {
		swap(x1, x2);
		swap(y1, y2);
	}

	int u = lower_bound(all(goodCol), y1) - goodCol.begin();
	ll res = 1e18;

	FOR (i, u - 1, u + 1) {
		if (i >= 0 && i < goodCol.size()) {
			int uu = goodCol[i];
			res = min(res, (ll) abs(x1 - x2) + abs(uu - y1) + abs(uu - y2));
		}
	}
	return res;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k >> q;
	
	FOR (i, 1, k) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
	}

	vector<int> goodRows;

	FOR (i, 1, n) {
		if (v[i].size()) {
			goodRows.pb(i);
		}
	}

	for (int i = 0; i < goodRows.size(); i++) {
		if (i) {
			for (auto u: v[goodRows[i - 1]]) {
				for (auto k: v[goodRows[i]]) {
					
				}
			}
		}
	}


	return 0;
}