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

int fen[10005];
void add(int u, int v) {
	for (int i = u; i <= 10001; i += i & -i) {
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

struct Ver {
	int x, y1, y2;
};

struct Hori {
	int x1, x2, y;
};

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Hori> h;
	vector<Ver> v;
	vector<int> open[10005], close[10005];

	FOR (i, 1, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		x1 += 5001;
		x2 += 5001;
		y1 += 5001;
		y2 += 5001;

		if (x1 == x2) {
			if (y1 > y2) swap(y1, y2);
 			v.pb({x1, y1, y2});
		}
		else {
			if (x1 > x2) swap(x1, x2);
			h.pb({x1, x2, y1});
		}
	}

	sort(all(h), [](Hori h1, Hori h2) {
		return h1.y < h2.y;
	});

	ll res = 0;
	for (int i = 0; i < h.size(); i++) {
		vector<int> close[10005];
		vector<II> query[10005];

		int l = h[i].x1;
		int r = h[i].x2;

		for (int j = i + 1; j < h.size(); j++) {
			// cout << l << " " << h[j].x1 << " " << r << endl;
			if (h[j].x1 < r) {
				query[h[j].y].pb({max(h[j].x1, l), min(h[j].x2, r)});
			} 
		}

		for (auto k: v) {
			if (k.x >= l && k.x <= r && k.y1 <= h[i].y) {
				close[k.y2].pb(k.x);
				add(k.x, 1);
			}
		}

		FOR (j, 1, 10001) {
			for (auto k: query[j]) {
				// cout << i << " " << k.first << " " << k.second << endl;
				int u = getSum(k.second) - getSum(k.first - 1);
				// cout << u << endl;
				res += u * 1ll * (u - 1) / 2;
			}
			for (auto k: close[j]) {
				// cout << k << endl;
				add(k, -1);
			}
		}
		// cout << i << " " << res << endl;
	}

	cout << res << endl;
 
	return 0;
}