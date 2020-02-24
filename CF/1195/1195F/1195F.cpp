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
};

Point vecto(Point a, Point b) {
	int x = a.x - b.x;
	int y = a.y - b.y;
	int g = __gcd(abs(x), abs(y));
	x /= g, y /= g;
	return {x, y};
}

vector<int> v[100005];
vector< pair<Point, int> > allVec;
Point p[300005];
int fen[300005], last[300005], ans[300005];

void add(int u, int k) {
	for (int i = u; i <= 300000; i += i & -i) {
		fen[i] += k;
	}
}

int getSum(int u) {
	int res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
	}
	return res;
} 

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		int k;
		cin >> k;
		FOR (j, 1, k) {
			cin >> p[j].x >> p[j].y; 
		} 
		FOR (j, 1, k - 1) {
			allVec.pb({vecto(p[j], p[j + 1]), i});
		}
		allVec.pb({vecto(p[k], p[1]), i});
	}

	sort(all(allVec), [](pair<Point, int> &a, pair<Point, int> &b) {
		if (a.first.x == b.first.x) return a.first.y < b.first.y;
		return a.first.x < b.first.x;
	});

	int ind = 0;
	for (int i = 0; i < allVec.size(); i++) {
		// cout << allVec[i].first.x << " " << allVec[i].first.y << " " << allVec[i].second << endl;
		if (!i || allVec[i].first.x != allVec[i - 1].first.x || allVec[i].first.y != allVec[i - 1].first.y) {
			ind++;
		}
		v[allVec[i].second].pb(ind);
	}

	// cout << endl;
	// FOR (i, 1, n) {
	// 	for (auto j: v[i]) cout << j << " ";
	// 	cout << endl;
	// }
	
	int q;
	cin >> q;
	vector<II> queries[300005];
	FOR (i, 1, q) {
		int l, r;
		cin >> l >> r;
		queries[r].pb({l, i});
	}

	FOR (i, 1, n) {
		for (auto j: v[i]) {
			if (last[j]) {
				add(last[j], -1);
			}
			add(i, 1);
			last[j] = i;
		}		

		for (auto q: queries[i]) {
			ans[q.second] = getSum(i) - getSum(q.first - 1);
		}
	}

	FOR (i, 1, q) {
		cout << ans[i] << "\n";
	}


	return 0;
}