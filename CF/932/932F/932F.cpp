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
typedef pair < ll, ll > II;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
} *cht[100006];

ll a[100005], b[100005], d[100005];
int sub[100005];
vector<int> v[100005];
vector<II> *lines[100005];

void dfs(int u, int p) {
	sub[u] = 1;
	for (auto i: v[u]) {
		if (i == p) continue;
		dfs(i, u);
		sub[u] += sub[i];
	}

	int heavy = -1;
	int maxSub = -1;
	for (auto i: v[u]) {
		if (i == p) continue;
		if (maxSub < sub[i]) {
			maxSub = sub[i];
			heavy = i;
		}
	}

	if (heavy == -1) { // leaf
		d[u] = 0;
		cht[u] = new LineContainer();
		cht[u]->add(-b[u], -d[u]);
		lines[u] = new vector<II>();
		lines[u]->pb({-b[u], -d[u]});
	}
	else {
		cht[u] = cht[heavy];
		lines[u] = lines[heavy];
		for (auto i: v[u]) {
			if (i == p || i == heavy) continue;
			for (auto j: (*lines[i])) {
				lines[u]->pb(j);
				cht[u]->add(j.first, j.second);
			}
		}
		d[u] = -cht[u]->query(a[u]);
		cht[u]->add(-b[u], -d[u]);
		lines[u]->pb({-b[u], -d[u]});
	}
}

int main()
{IN;
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