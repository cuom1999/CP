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

const int LG = 20;

struct Point {
	ll x, y;
	bool operator < (Point &a) {
		if (x == a.x) return y < a.y;
		return x < a.x;
	}
};

struct CHT {
	vector<Point> v;

	ld cross (Point a, Point b) {return (ld)(b.y - a.y) / (b.x - a.x);}

	void addLine(ll x, ll y) {
		if (v.size() && v.back().x == x && v.back().y == y) return;

		while(v.size() >= 2 && cross(v[v.size()-2], v.back()) > cross(v.back(), (Point){x, y})){
			v.pop_back();	
		}
		v.push_back({x, y});
	}

	ll query(ll x) {
		int s = 0, e = v.size()-1;
		auto f = [&](int p) {
			return v[p].x * x + v[p].y;
		};

		while(s != e){
			int m = (s + e) / 2;
			if(f(m) <= f(m+1)) e = m;
			else s = m + 1;
		}
		return v[s].x * x + v[s].y;
	}
};

CHT merge(CHT &a, CHT &b) {
	CHT res;
	vector<Point> tmp;
	merge(all(a.v), all(b.v), back_inserter(tmp));

	for (auto i: tmp) {
		res.addLine(i.x, i.y);
	}
	return res;
}

struct Container {
	vector<CHT*> group[LG + 1];

	void insert(Container &c) {
		FOR (i, 0, LG) {
			for (auto j: c.group[i]) {
				group[i].pb(j);
			}
		}
	}

	void rebuild() {
		FOR (i, 0, LG) {
			for (int j = 0; j + 1 < group[i].size(); j += 2) {
				CHT *tmp = new CHT();
				*tmp = merge(*group[i][j], *group[i][j + 1]);
				group[i + 1].pb(tmp);
			}
			if (group[i].size() % 2) {
				auto tmp = group[i].back();
				group[i].clear();
				group[i].pb(tmp);
			}
			else {
				group[i].clear();
			}
		}
	}

	void print() {
		FOR (i, 0, LG) {
			if (group[i].size()) {
				cout << i << endl;
				for (auto j: group[i][0]->v) {
					cout << j.x << " " << j.y << endl;
				}
			}
		}
		cout << endl;
	}
};



ll a[100005], b[100005], d[100005];
vector<int> v[100005];
Container c[100005];

void dfs(int u, int p) {
	for (auto i: v[u]) {
		if (i == p) continue;
		dfs(i, u);
		c[u].insert(c[i]);
	}

	if (v[u].size() == 1 && u != 1) { //leaf
		d[u] = 0;
	}
	else {
		c[u].rebuild();

		// cout << u << endl;
		// c[u].print();

		d[u] = 1e18;
		FOR (i, 0, LG) {
			if (c[u].group[i].size()) {
				d[u] = min(d[u], c[u].group[i][0]->query(a[u]));
			}
		}
	}
	Container tmp;
	CHT *tmpCHT = new CHT();
	tmpCHT->addLine(b[u], d[u]);
	tmp.group[0].pb(tmpCHT);

	c[u].insert(tmp); 
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	
	int n;
	cin >> n;
	FOR (i, 1, n) {
		cin >> a[i];
	}

	FOR (i, 1, n) {
		cin >> b[i];
	}

	FOR (i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, 0);

	FOR (i, 1, n) cout << d[i] << " ";


	return 0;
}