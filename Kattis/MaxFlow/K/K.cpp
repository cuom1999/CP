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

int n, m, castleX, castleY;
ll a[305][305];

int vertex(int x, int y, bool in) {
	// 0 <= x <= n + 1, 0 <= y <= m + 1
	if (in == 0) {
		return x * (m + 2) + y;
	}
	return x * (m + 2) + y + (n + 2) * (m + 2);
}

string trans(int vertex) {
	if (vertex >= (m + 2) * (n + 2)) {
		vertex -= (m + 2) * (n + 2);
	}

	return "(" + to_string(vertex / (m + 2)) + ", " + to_string(vertex % (m + 2)) + ")";
} 

II trans2(int vertex) {
	if (vertex >= (m + 2) * (n + 2)) {
		vertex -= (m + 2) * (n + 2);
	}

	return II(vertex / (m + 2), vertex % (m + 2));	
}

struct Dinic {
	int N;
	vector<Edge> E;
	vector<vector<int>> g;
	vector<int> d, pt;
	Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
	void addEdge(int u, int v, ll cap) {
		if (u != v && cap && v != vertex(castleX, castleY, 0)) {
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



int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			cin >> a[i][j];
		}
	}

	cin >> castleX >> castleY;
	castleX++;
	castleY++;

	int source = vertex(castleX, castleY, 0);
	int sink = 2 * (n + 2) * (m + 2);
	Dinic flow(sink + 1);

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			flow.addEdge(vertex(i, j, 0), vertex(i, j, 1), a[i][j]);
			flow.addEdge(vertex(i, j, 1), vertex(i, j + 1, 0), 1e14);
			flow.addEdge(vertex(i, j, 1), vertex(i - 1, j, 0), 1e14);
			flow.addEdge(vertex(i, j, 1), vertex(i + 1, j, 0), 1e14);
			flow.addEdge(vertex(i, j, 1), vertex(i, j - 1, 0), 1e14);
		}
	}

	FOR (i, 0, n + 1) {
		flow.addEdge(vertex(i, 0, 0), sink, 1e14);
		flow.addEdge(vertex(i, m + 1, 0), sink, 1e14);
	}
	FOR (j, 1, m) {
		flow.addEdge(vertex(0, j, 0), sink, 1e14);
		flow.addEdge(vertex(n + 1, j, 0), sink, 1e14);
	}

	cout << flow.maxFlow(source, sink) << endl;

	// int d[305][305];
	// memset(d, 0, sizeof(d));

	// FOR (i, 0, sink) {
	// 	if (flow.d[i] != flow.N + 1) {
	// 		// cout << trans(i) << endl;
	// 		d[trans2(i).first][trans2(i).second]++;
	// 	}
	// }

	// FOR (i, 1, n) {
	// 	FOR (j, 1, m) {
	// 		cout << d[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return 0;
}