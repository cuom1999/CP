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

vector<int> v[70];

vector<II> edges;

int lab[100005];

int getRoot(int a) {
	while (lab[a] >= 0) a = lab[a];
	return a;
}

void dsu(int a, int b) {
	int x = lab[a] + lab[b];
	if (lab[a] < lab[b]) {
		lab[a] = x;
		lab[b] = a;
	}
	else {
		lab[b] = x;
		lab[a] = b;
	}
}

vector<int> adj[100005];
int h[100005], p[100005];

int lca(int a, int b) {
	if (h[a] > h[b]) swap(a, b);
	while (h[b] > h[a]) b = p[b];

	while (a != b) {
		a = p[a];
		b = p[b];
	}
	return a;
}

void dfs(int a, int par) {
	p[a] = par;
	h[a] = h[par] + 1;
	for (auto i: adj[a]) {
		if (i == par) continue;
		dfs(i, a);
	}
}
int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		ll x;
		cin >> x;
		FOR (j, 0, 59) {
			if ((1LL << j) & x) {
				v[j].pb(i);
			}
		}
	}

	FOR (i, 0, 59) {
		if (v[i].size() >= 3) {
			cout << 3;
			return 0;
		}
	}
	set<II> E;
	FOR (i, 0, 59) {
		if (v[i].size() == 2) {
			// edges.pb({v[i][0], v[i][1]});
			E.insert({v[i][0], v[i][1]});
		}
	}

	for (auto e: E) {
		edges.pb(e);
	}

	memset(lab, -1, sizeof(lab));

	vector<II> backEdges;

	for (auto e: edges) {
		int a = getRoot(e.first);
		int b = getRoot(e.second);
		if (a == b) {
			backEdges.pb(e);
		}
		else {
			dsu(a, b);
			adj[e.first].pb(e.second);
			adj[e.second].pb(e.first);
		}
	}

	FOR (i, 1, n) {
		if (lab[i] < 0) {
			dfs(i, 0);
		}
	}

	int res = INF;

	for (auto i: backEdges) {
		int k = lca(i.first, i.second);
		res = min(res, h[i.first] + h[i.second] - 2 * h[k] + 1);
	}

	if (res < INF) cout << res << endl;
	else cout << -1;



	return 0;
}