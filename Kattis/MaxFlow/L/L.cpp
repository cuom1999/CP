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
		if (u != v) {
			// cout << u << " " << v << " " << cap << endl;
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

map<string, int> ind;
int s, r, f, t;

int raw(int i) {
	return i;
}

int factory(int i) {
	return i + r; 
}

int midState(int i) {
	return r + f + i;
}

int transportation(int i, bool in) {
	if (!in) return s + i;
	return s + t + i;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> s >> r >> f >> t;
	int C = 0;

	FOR (i, 1, r) {
		string s;
		cin >> s;
		ind[s] = ++C;
	}

	FOR (i, 1, f) {
		string s;
		cin >> s;
		ind[s] = ++C;
	}

	int source = 0;
	int sink = s + 2 * t + 1;
	Dinic dinic(sink + 1);


	FOR (i, 1, t) {
		int k;
		cin >> k;
		vector<int> l;

		FOR (j, 1, k) {
			string s;
			cin >> s;
			if (!ind[s]) {
				ind[s] = ++C;
			}
			l.pb(ind[s]);
		}

		for (auto j: l) {
			dinic.addEdge(transportation(i, 1), j, 1);
			dinic.addEdge(j, transportation(i, 0), 1);
		}
		dinic.addEdge(transportation(i, 0), transportation(i, 1), 1);
	}
	
	FOR (i, 1, r) {
		dinic.addEdge(source, i, 1);
	}

	FOR (i, 1, f) {
		dinic.addEdge(r + i, sink, 1);
	}

	cout << dinic.maxFlow(source, sink) << endl;

	// for (auto e: dinic.E) {
	// 	if (e.flow && e.cap) {
	// 		cout << e.u << " " << e.v << " " << e.flow << endl;
	// 	}
	// }

	return 0;
}