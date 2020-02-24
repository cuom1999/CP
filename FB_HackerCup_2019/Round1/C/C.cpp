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

typedef pair < ll, ll > II;
typedef pair < ll, II > III;

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

III lad[55];

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {

		cout << "Case #" << z << ": ";

		int n, h;
		cin >> n >> h;

		FOR (i, 1, n) {
			int x, a, b;
			cin >> x >> a >> b;
			lad[i] = {x, {a, b}};
		}
		sort(lad + 1, lad + n + 1);


		int source = 0;
		int sink = n + 1;

		Dinic dinic(sink + 1);


		FOR (i, 1, n) {
			FOR (j, i + 1, n) {
				ll u = max(lad[i].second.first, lad[j].second.first);
				ll v = min(lad[i].second.second, lad[j].second.second);
				vector<II> s;
				s.pb({u, v});
				if (u >= v) continue;

				FOR (k, 1, n) {
					if (i == k || k == j) continue;
					if (lad[i].first < lad[k].first && lad[k].first < lad[j].first) {
						vector<II> newS;
					
						for (auto l: s) {
							if (l.first < min(l.second, lad[k].second.first)) {
								newS.pb({l.first, min(l.second, lad[k].second.first)});
							}
							if (l.second > max(l.first, lad[k].second.second)) {
								newS.pb({max(l.first, lad[k].second.second), l.second});
							}
						}
						s = newS;
					}
				}
				ll cost = 0;
				for (auto e: s) {
					cost += e.second - e.first;
				}

				if (cost > 0) {
					dinic.addEdge(i, j, cost);
					dinic.addEdge(j, i, cost);
					// cout << i << " " << j << " " << cost << endl;
				}
			}
			if (lad[i].second.first == 0) {
				dinic.addEdge(i, sink, INF);
			}
			if (lad[i].second.second == h) {
				dinic.addEdge(source, i, INF);
			} 
		}

		ll flow = dinic.maxFlow(source, sink);
		if (flow >= INF) cout << -1 << endl;
		else cout << flow << endl;
	}


	return 0;
}