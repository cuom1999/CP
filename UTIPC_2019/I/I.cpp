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

const int MAXN = 100005;
const int MAXQ = 1000006;

int vs[MAXN], cycLink[MAXN], a[MAXN], h[MAXN], n;
int p[MAXN][20];

vector<int> v[MAXN], tree[MAXN];

set<II> edgeTree;

void dfs(int a, int p) {
	vs[a] = 1;
	for (auto i: v[a]) {
		if (!vs[i]) {
			dfs(i, a);
			tree[i].pb(a);
			tree[a].pb(i);
			edgeTree.insert(II(min(i, a), max(i, a)));
		}	
	}
}

void dfsTree(int a, int par) {
	h[a] = h[par] + 1;
	p[a][0] = par;
	for (auto i: tree[a]) {
		if (i != par) {
			dfsTree(i, a);
		}
 	}
}

void init() {
	FOR (i, 1, 18){
		FOR (j, 1, n){
			p[j][i] = p[p[j][i - 1]][i - 1];
		}
	}
}
//remember h[1]=1
int LCA(int u, int v){
	if (h[v] < h[u]) FORD(i,17,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
	if (h[u] < h[v]) FORD(i,17,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

	FORD(i, 17, 0) if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}

	while (u!=v){
		u=p[u][0]; v=p[v][0];
	}
	return u;
}

ll V[MAXQ], E[MAXQ], F[MAXQ];
set<II> backEdge;

void findCycle() {
	for (auto e: backEdge) {
		int u = e.first;
		int v = e.second;
		// cout << u << " " << v << endl;

		int val = __gcd(a[u], a[v]);

		int w = LCA(u, v);

		val = __gcd(val, a[w]);

		while (u != w) {
			u = p[u][0];
			val = __gcd(val, a[u]);
		}	

		while (v != w) {
			v = p[v][0];
			val = __gcd(val, a[v]);
		}
		F[val]++;
	}
}

void findEdge() {
	FOR (i, 1, n) {
		for (auto j: v[i]) {
			if (i < j) {
				int val = __gcd(a[i], a[j]);
				E[val]++;
			}
		}
	}
}

void findVertex() {
	FOR (i, 1, n) V[a[i]]++;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);


	int m, q;
	cin >> n >> m >> q;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	FOR (i, 1, m) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, 0);

	dfsTree(1, 0);

	init();

	FOR (i, 1, n) {
		for (auto j: v[i]) {
			II u = II(min(i, j), max(i, j));
			if (edgeTree.find(u) == edgeTree.end()) {
				backEdge.insert(u);
			} 
		}
	}

	findCycle();
	findVertex();
	findEdge();

	FOR (i, 1, 1000000) {
		FOR (j, 2, 1000000 / i) {
			E[i] += E[i * j];
			V[i] += V[i * j];
			F[i] += F[i * j];
		}
	}


	FOR (z, 1, q) {
		int x;
		cin >> x;
		cout << V[x] - E[x] + F[x] << endl;
	}


	return 0;
}