#include <bits/stdc++.h>
 
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
 
int c[105][105];
 
struct Spaceship {
	int x, a, f;
} spaceship[1005];
 
struct Base {
	int x, a;
} base[1005];
 
typedef vector<ll> VI;
typedef vector<vector<ll>> VVI;
 
vector<II> edges;
int s, b, k, h;
 
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
		if (u != v) {
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
 
 
ll calc(int S) {
	int source = 0;
	int sink = s + b + S + 1;
	Dinic dinic(s + b + S + 2);
 
	for (auto i: edges) {
		dinic.addEdge(i.first, i.second + s, 1);
	}
	FOR (i, 1, s) {
		FOR (j, s + b + 1, s + b + S) {
			dinic.addEdge(i, j, 1);
		} 
	}
 
	FOR (i, 1, s) dinic.addEdge(source, i, 1);
	FOR (i, s + 1, s + b + S + 1) {
		dinic.addEdge(i, sink, 1);
	}
 
	ll mf = dinic.maxFlow(source, sink);
	// cout << mf << " " << S << endl;
	// return mf - S;
	return (mf - S) * 1ll * k + h * 1ll * S;
}
 
int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
 
	int n, m;
	cin >> n >> m;
 
	FOR (i, 1, n) {
		FOR (j, 1, n) c[i][j] = INF;
		c[i][i] = 0;
	}
 
	FOR (i, 1, m) {
		int x, y;
		cin >> x >> y;
		c[x][y] = c[y][x] = 1;
	}
 
	FOR (k, 1, n) {
		FOR (i, 1, n) {
			FOR (j, 1, n) {
				c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
			}
		}
	}
 
	cin >> s >> b >> k >> h;
 
	FOR (i, 1, s) {
		cin >> spaceship[i].x >> spaceship[i].a >> spaceship[i].f;
	}
 
	FOR (i, 1, b) {
		cin >> base[i].x >> base[i].a;
	}
 
	FOR (i, 1, s) {
		FOR (j, 1, b) {
			if (c[spaceship[i].x][base[j].x] <= spaceship[i].f && spaceship[i].a >= base[j].a) {
				// cout << i << " " << j << endl;
				// cost[i - 1][j - 1] = k;
				edges.pb({i, j});
			}
		}
	}
	cout << min(calc(0), calc(s)) << endl;
	return 0;
}