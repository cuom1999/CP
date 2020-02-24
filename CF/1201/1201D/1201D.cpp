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
vector<int> row[200005];
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

ll d[200005][3], f[200005][3];
int firstInRow[200005], lastInRow[200005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k >> q;

	row[1].pb(1);

	FOR (i, 1, k) {
		int x, y;
		cin >> x >> y;
		row[x].pb(y);
	}

	FOR (i, 1, q) {
		int x;
		cin >> x;
		goodCol.pb(x);
	}
	sort(all(goodCol));

	vector<int> goodRow = {0};

	FOR (i, 1, n) {
		if (row[i].size()) {
			sort(all(row[i]));
			goodRow.pb(i);
			int kk = goodRow.size() - 1;

			firstInRow[kk] = row[i][0];
			lastInRow[kk]  = row[i].back(); 
		}
	}

	m = goodRow.size() - 1;
	d[1][0] = 0;
	d[1][1] = dist(1, 1, 1, lastInRow[1]);
	f[1][0] = 2 * d[1][1];
	f[1][1] = d[1][1];

	FOR (i, 2, m) {
		d[i][0] = min(f[i - 1][0] + dist(goodRow[i], firstInRow[i], goodRow[i - 1], firstInRow[i - 1]), 
			f[i - 1][1] + dist(goodRow[i], firstInRow[i], goodRow[i - 1], lastInRow[i - 1]));
		d[i][1] = min(f[i - 1][0] + dist(goodRow[i], lastInRow[i], goodRow[i - 1], firstInRow[i - 1]), 
			f[i - 1][1] + dist(goodRow[i], lastInRow[i], goodRow[i - 1], lastInRow[i - 1]));
		ll distInRow = abs(firstInRow[i] - lastInRow[i]);
		f[i][0] = d[i][1] + distInRow;
		f[i][1] = d[i][0] + distInRow;
	}
	// FOR (i, 1, m) {
		// cout << f[i - 1][1] + dist(goodRow[i], firstInRow[i], goodRow[i - 1], lastInRow[i - 1]) << endl;
		// cout << i << " " << f[i][0] << " " << f[i][1] << endl;
		// cout << d[i][0] << " " << d[i][1] << endl; 
	// }


	cout << min(f[m][0], f[m][1]) << endl;
	return 0;
}