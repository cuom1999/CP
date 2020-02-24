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
typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};

struct PushRelabel {
	vector<vector<Edge>> g;
	vector<Flow> ec;
	vector<Edge*> cur;
	vector<vector<int>> hs; vector<int> H;
	PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		g[s].push_back({t, (int) g[t].size(), 0, cap});
		g[t].push_back({s, (int) g[s].size()-1, 0, rcap});
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
		if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f; ec[back.dest] -= f;
	}
	Flow maxFlow(int s, int t) {
		int v = g.size(); H[s] = v; ec[t] = 1;
		vector<int> co(2*v); co[0] = v-1;
		FOR(i,0,v - 1) cur[i] = g[i].data();
		for(auto &e: g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (ec[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + (int)(g[u].size())) {
					H[u] = 1e9;
					for(auto &e: g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						FOR(i,0,v-1) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

int n, m;
int a[1005], b[1005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	int source = 0;
	int sink = m + n + 1;

	PushRelabel dinic(sink + 1);

	int sum = 0;
	FOR (i, 1, n) {
		cin >> a[i];
		sum += a[i];
	}

	int sum1 = 0;

	FOR (i, 1, m) {
		cin >> b[i];
		sum1 += b[i];
	}

	if (sum != sum1) {
		cout << "NO\n";
		return 0;
	}

	FOR (i, 1, n) {
		dinic.addEdge(source, i, a[i]);
		FOR (j, 1, m) {
			dinic.addEdge(i, n + j, 1);
		}
	}
	FOR (i, 1, m) {
		dinic.addEdge(n + i, sink, b[i]);		
	}

	int res = dinic.maxFlow(source, sink);

	// cout << res << endl;
	
	if (res == sum) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}




	return 0;
}