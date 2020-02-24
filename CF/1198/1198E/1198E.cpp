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

int y_1[55], y2[55], x1[55], x2[55];
map<int, int> yIndex, xIndex; 
vector<II> E;
int leftVal[105], rightVal[105];

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



int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<int> yVal, xVal;

	FOR (i, 1, m) {
		cin >> x1[i] >> y_1[i] >> x2[i] >> y2[i];
		yVal.insert(y_1[i]);
		// yVal.insert(y_1[i] - 1);
		
		// yVal.insert(y2[i]);
		yVal.insert(y2[i] + 1);

		// xVal.insert(x1[i] - 1);
		xVal.insert(x1[i]);
		
		// xVal.insert(x2[i]);
		xVal.insert(x2[i] + 1);
	}

	if (m == 0) {
		cout << 0 << endl;
		return 0;
	}

	int ind = 0;
	for (auto y: yVal) {
		if (y < 1) continue;
		yIndex[y] = ++ind; 
		leftVal[ind] = y;
	}

	ind = 0;
	for (auto x: xVal) {
		if (x < 1) continue;
		xIndex[x] = ++ind;
		rightVal[ind] = x;
	}

	int leftNum = yIndex.size();
	int rightNum = xIndex.size();

	// FOR (i, 1, leftNum) cout << leftVal[i] << " ";
	// cout << endl;

	// FOR (i, 1, rightNum) cout << rightVal[i] << " ";
	// cout << endl;

	FOR (i, 1, leftNum - 1) {
		FOR (j, 1, rightNum - 1) {
			bool isGood = 0;

			FOR (k, 1, m) {
				if (y_1[k] <= leftVal[i] && leftVal[i + 1] - 1 <= y2[k] && x1[k] <= rightVal[j] && rightVal[j + 1] - 1 <= x2[k]) {
					isGood = 1;
					break;
				}
			}

			if (isGood) {
				E.pb({i, j});
				// cout << i << " " << j << endl;
			}
		}
	}

	int source = 0;
	int sink = leftNum + rightNum - 1;

	Dinic dinic(sink + 1);

	for (auto e: E) {
		dinic.addEdge(e.first, e.second + leftNum - 1, 1e18);
	}

	FOR (i, 1, leftNum - 1) {
		dinic.addEdge(source, i, leftVal[i + 1] - leftVal[i]);
	}

	FOR (i, 1, rightNum - 1) {
		dinic.addEdge(i + leftNum - 1, sink, rightVal[i + 1] - rightVal[i]);
	}

	cout << dinic.maxFlow(source, sink) << endl;


	return 0;
}