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
		if (u != v && cap > 0) {
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



int n, q, s;
int que[105];
ll c[35];
ll m[35];
ll sentData[35][35];

int vertex1(int window, int queueIndex) {
	return (window - 1) * q + queueIndex;
}

int vertex2(int window) {
	return q * n + window;
}


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> q >> s;

	FOR (i, 1, s) {
		cin >> que[i];
	}

	FOR (i, 1, q) {
		cin >> m[i];
	}

	FOR (i, 1, n) {
		cin >> c[i];
		FOR (j, 1, s) {
			ll x;
			cin >> x;
			sentData[i][que[j]] += x;
		}
	}

	ll totalData = 0;

	FOR (i, 1, n) {
		FOR (j, 1, q) {
			// cout << sentData[i][j] << " ";
			totalData += sentData[i][j];
			if (sentData[i][j] > m[j]) {
				cout << "impossible" << endl;
				return 0;
			}
		}
	}

	Dinic dinic(q * n + n + 2);

	int source = 0;
	int sink = q * n + n + 1;

	FOR (i, 1, n) {
		FOR (j, 1, q) {
			dinic.addEdge(source, vertex1(i, j), sentData[i][j]);
			if (i < n) {
				dinic.addEdge(vertex1(i, j), vertex1(i + 1, j), m[j] - sentData[i + 1][j]);
			}
			dinic.addEdge(vertex1(i, j), vertex2(i), m[j]);
		}
		dinic.addEdge(vertex2(i), sink, c[i]);
	}

	// cout << dinic.maxFlow(source, sink) << endl; 
	ll res = dinic.maxFlow(source, sink);
	// cout << res << endl;
	// cout << totalData << endl;

	if (res == totalData) {
		cout << "possible" << endl;
	}
	else {
		cout << "impossible" << endl;
	}


	return 0;
}