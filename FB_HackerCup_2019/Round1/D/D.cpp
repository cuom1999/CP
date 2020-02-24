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

int n, H, V;

struct Point {
	int x, y;
}p[800005];

int fen[800005], m;
vector<int> valY;

void add(int u, int v) {
	for (int i = u; i <= m; i += i & -i) {
		fen[i] += v;
	}
}

int getSum(int u) {
	int res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

bool f(int X, int Y) {
	int h = 0, v = 0;

	FOR (i, 1, n) {
		if (p[i].y > Y && p[i].x > X) return 0;
		if (p[i].y > Y) h++;
		if (p[i].x > X) v++; 
	}	
	if (h <= H && v <= V) return 1;
	return 0;
}

int pos[800005], ma[800005];

bool check(int X, int Y) {
	if (X != n && ma[X + 1] > valY[Y]) return 0;
	if (n - X <= V && getSum(m) - getSum(Y) <= H) return 1;
	return 0;
}

int main()
{IN;OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";

		cin >> n >> H >> V;

		ll a, b, c, d;
		cin >> p[1].x >> p[2].x >> a >> b >> c >> d;

		FOR (i, 3, n) {
			p[i].x = (a * p[i - 2].x % d + b * p[i - 1].x % d + c) % d + 1;
		}

		cin >> p[1].y >> p[2].y >> a >> b >> c >> d;

		FOR (i, 3, n) {
			p[i].y = (a * p[i - 2].y % d + b * p[i - 1].y % d + c) % d + 1;
		}

		if (H + V < n) {
			cout << -1 << endl;
			continue;
		}

		sort(p + 1, p + n + 1, [](const Point & a, const Point &b) {
			return a.x < b.x;
		});

		vector<II> v;

		FOR (i, 1, n) v.pb({p[i].y, i});

		sort(all(v));

		valY.pb(0);
		for (int i = 0; i < v.size(); i++) {
			if (!i || v[i].first != v[i - 1].first) {
				valY.pb(v[i].first);
			}
			pos[v[i].second] = valY.size() - 1;
		}
		m = valY.size();

		ma[n] = p[n].y;

		FORD(i, n - 1, 1) {
			ma[i] = max(ma[i + 1], p[i].y);
		}

		int curY = m - 1;
		ll res = 1e18;

		if (V >= n) res = ma[1];

		FOR (i, 1, n) {
			add(pos[i], 1);

			if (i == n || p[i].x != p[i + 1].x) {
				while (curY && check(i, curY)) {
					// cout << p[i].x << " " << valY[curY] << endl;
					res = min(res, (ll) p[i].x + valY[curY]);
					curY--;
				}
				if (!curY && check(i, curY)) {
					res = min(res, (ll) p[i].x + valY[curY]);
				}
			}
		}

		// FOR (i, 1, n) {
		// 	cerr << p[i].x << " " << p[i].y << endl;
		// }

		cout << res << endl;

		FOR (i, 1, m) fen[i] = 0;
		valY.clear();
	}

	return 0;
}