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

map<int, string> name;
vector<int> v[65];	
int m, n;
	
bool solve(int k) {
	int s = 0, t = m + n + 1;
	Dinic dinic(m + n + 2);

	FOR (i, 1, n) {
		dinic.addEdge(s, i, 2);
	}

	FOR (i, 1, n) {
		for (auto j: v[i]) {
			dinic.addEdge(i, j + n, 1);
		}
	}

	FOR (i, 1, m) {
		dinic.addEdge(i + n, t, k);
	}
	int maxF = dinic.maxFlow(s, t);

	if (maxF == 2 * n) {
		vector<string> res[33];
		for (auto e: dinic.E) {
			if (e.flow && e.cap && e.u >= 1 && e.u <= n) {
				res[e.u].pb(name[e.v - n]);
			}
		}

		cout << k << endl;
		FOR (i, 1, n) {
			cout << "Day " << i << ": ";
			for (auto j: res[i]) {
				cout << j << " ";
			} 
			cout << endl;
		}
		return 1;
	} 
	return 0;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m >> n;

	FOR (i, 1, m) {
		cin >> name[i];
		int k;
		cin >> k;
		FOR (j, 1, k) {
			int x;
			cin >> x;
			v[x].pb(i);
		}
	}


	FOR (i, 1, 100) {
		if (solve(i)) {
			return 0;
		}
	}



	return 0;
}