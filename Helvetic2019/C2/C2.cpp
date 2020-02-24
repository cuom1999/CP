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

struct Point {
	int x, y;
}p[300005];

int y1[300005], y2[300005], st[300005 * 4], lz[300005 * 4];

void down(int id, int l, int r) {
	if (l == r || lz[id] == 0) return;

	st[id * 2] += lz[id];
	st[id * 2 + 1] += lz[id];
	lz[id * 2] += lz[id];
	lz[id * 2 + 1] += lz[id];
	lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
	if (v < l || r < u) return;
	// cout << id << " " << l << " " << r << " " << u << " " << v << endl;
	if (u <= l && r <= v) {
		st[id] += k;
		lz[id] += k;
		// cout << id << " " << u << " " << v << " " << st[id] << endl;
		return;
	}
	down(id, l, r);
	int mid = (l + r) / 2;

	update(id * 2, l, mid, u, v, k);
	update(id * 2 + 1, mid + 1, r, u, v, k);

	st[id] = max(st[id * 2], st[id * 2 + 1]);
	// cout << id << " " << u << " " << v << " " << st[id] << endl;
}

int getMax(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return -INF;
	if (u <= l && r <= v) {
		return st[id];
	}
	down(id, l, r);
	int mid = (l + r) / 2;
	return max(getMax(id * 2, l, mid, u, v), getMax(id * 2 + 1, mid + 1, r, u, v));
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, r;
	cin >> n >> r;

	FOR (i, 1, n) {
		int x0, y0;
		cin >> x0 >> y0;
		p[i].x = x0 + y0;
		p[i].y = x0 - y0;
	}

	vector<II> yVal;

	FOR (i, 1, n) {
		yVal.pb({p[i].y - r, -i});
		yVal.pb({p[i].y + r, i});
	}

	sort(all(yVal));
	int index = 0;

	for (int i = 0; i < yVal.size(); i++) {
		if (!i || yVal[i].first != yVal[i - 1].first) {
			index++;
		} 
		int u = abs(yVal[i].second);
		if (yVal[i].second > 0) {
			y2[u] = index;
		}
		else {
			y1[u] =index;
		}
	}

	vector<II> xVal;

	FOR (i, 1, n) {
		xVal.pb({p[i].x - r, -i});
		xVal.pb({p[i].x + r, i});
	}
	// FOR (i, 1, n) {
	// 	cerr << y1[i] << " " << y2[i] << endl;
	// }
	sort(all(xVal));

	int N = 2 * n;

	int res = 0;
	for (auto i: xVal) {
		int u = abs(i.second);

		if (i.second < 0) { // add
			update(1, 1, N, y1[u], y2[u], 1);
		}
		else { // remove
			update(1, 1, N, y1[u], y2[u], -1);
		}

		res = max(res, st[1]);
		// cout << i.second << ": ";
		// FOR (j, 1, N) cout << getMax(1, 1, N, j, j) << " ";
		// cout << endl;
	}

	cout << res << endl;


	return 0;
}