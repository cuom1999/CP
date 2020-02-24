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


// Use:
// Constructor: Dinic dinic(n)
// 
// add edges: dinic.addEdge(u, v, c)
// 
// trace: for (auto e: dinic.E) {
// 	if (e.flow && e.cap) {
// 		cout << e.u << " " << e.v << " " << e.flow << endl;
// 	}
// }
// 
// minCut: i from (0 to dinic.N - 1): dinic.d[i] != dinic.N + 1
struct Edge {
	int u, v;
	ll cap, flow;
	Edge() {}
	Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
	void addEdge(int u, int v, ll cap) {
		if (u != v && cap) {
			E.emplace_back(Edge(u, v, cap));
			g[u].emplace_back(E.size() - 1);
			E.emplace_back(Edge(v, u, 0));
			g[v].emplace_back(E.size() - 1);
		}
	}
	bool bfs(int S, int T) {
		queue<int> q({S});
		fill(d.begin(), d.end(), N + 1);
		d[S] = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			if (u == T) break;
			for (int k: g[u]) {
				Edge &e = E[k];
				if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
					d[e.v] = d[e.u] + 1;
					q.emplace(e.v);
				}
			}
		}
		return d[T] != N + 1;
	}
	ll dfs(int u, int T, ll flow = -1) {
		if (u == T || flow == 0) return flow;
		for (int &i = pt[u]; i < g[u].size(); ++i) {
			Edge &e = E[g[u][i]];
			Edge &oe = E[g[u][i]^1];
			if (d[e.v] == d[e.u] + 1) {
				ll amt = e.cap - e.flow;
				if (flow != -1 && amt > flow) amt = flow;
				if (ll pushed = dfs(e.v, T, amt)) {
					e.flow += pushed;
					oe.flow -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}
	ll maxFlow(int S, int T) {
		ll total = 0;
		while (bfs(S, T)) {
			fill(pt.begin(), pt.end(), 0);
			while (ll flow = dfs(S, T))
				total += flow;
		}
		return total;
	}
};



ll lowerBound[205][25], upperBound[205][25], res[205][25];
ll a[205], b[25];

bool update(int x, int y, char c, ll val) {
	if (c == '<') {
		if (val - 1 < lowerBound[x][y]) {
			cout << "IMPOSSIBLE\n\n";
			return 0;
		}
		upperBound[x][y] = val - 1;
	}
	else if (c == '>') {
		if (val + 1 > upperBound[x][y]) {
			cout << "IMPOSSIBLE\n\n";
			return 0;
		}
		lowerBound[x][y] = val + 1; 
	}
	else {
		if (val < lowerBound[x][y] || val > upperBound[x][y]) {
			// cout << x << " " << y << endl;
			// cout << val << " " << lowerBound[x][y] << " " << upperBound[x][y] << endl;
			cout << "IMPOSSIBLE\n\n";
			return 0;
		}
		lowerBound[x][y] = upperBound[x][y] = val;
	}
	return 1;
}

void solve() {
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	FOR (i, 1, n) {
		cin >> a[i];
		sum += a[i];
	}

	ll sum1 = 0;
	FOR (i, 1, m) {
		cin >> b[i];
		sum1 += b[i];
	}

	int k;
	int x[1005], y[1005], val[1005];
	char c[1005];

	cin >> k;
	FOR (i, 1, k) {
		cin >> x[i] >> y[i] >> c[i] >> val[i];
	}


	FOR (i, 1, n) {
		FOR (j, 1, m) {
			lowerBound[i][j] = 0;
			upperBound[i][j] = min(a[i], b[j]);
		}
	}

	if (sum != sum1) {
		cout << "IMPOSSIBLE" << endl << endl;
		return;
	}
	
	FOR (z, 1, k) {

		if (x[z] && y[z]) {
			if (!update(x[z], y[z], c[z], val[z])) {
				return;
			}	
 		}
 		else if (x[z] == 0 && y[z]) {
 			FOR (i, 1, n) {
 				if (!update(i, y[z], c[z], val[z])) {
 					return;
 				}
 			}
 		}
 		else if (x[z] && y[z] == 0) {
 			FOR (i, 1, m) {
 				if (!update(x[z], i, c[z], val[z])) {
 					return;
 				}
 			}
 		}
 		else {
 			FOR (i, 1, n) {
 				FOR (j, 1, m) {
 					if (!update(i, j, c[z], val[z])) {
 						return;
 					}
 				}
 			}
 		}
	}


	FOR (i, 1, n) {
		FOR (j, 1, m) {
			a[i] -= lowerBound[i][j];
			b[j] -= lowerBound[i][j];
			upperBound[i][j] -= lowerBound[i][j];
		}
	}

	FOR (i, 1, n) {
		if (a[i] < 0) {
			cout << "IMPOSSIBLE\n\n";
			return;
		}
	}

	FOR (i, 1, m) {
		if (b[i] < 0) {
			cout << "IMPOSSIBLE\n\n";
			return;
		}
	}

	sum = 0;
	FOR (i, 1, n) sum += a[i];

	int source = 0;
	int sink = m + n + 1;
	Dinic dinic(sink + 1);

	FOR (i, 1, n) {
		dinic.addEdge(source, i, a[i]);
	}
	FOR (i, 1, m) {
		dinic.addEdge(n + i, sink, b[i]);
	}

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			dinic.addEdge(i, n + j, upperBound[i][j]);
		}
	}
	ll maxF = dinic.maxFlow(source, sink);

	if (maxF != sum) {
		cout << "IMPOSSIBLE\n\n";
		return;
	}

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			res[i][j] = 0;
		}
	}
	for (auto e: dinic.E) {
		if (e.cap && e.flow && e.u && e.v != sink) {
			res[e.u][e.v - n] = e.flow;
		}
	}

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			cout << res[i][j] + lowerBound[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) solve();

	return 0;
}