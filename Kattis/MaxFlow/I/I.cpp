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

// use: 
// Constructor: PushRelabel flow(n)
// 
// trace:
// 
// for (int i = 0; i < flow.g.size(); i++) {
// 	for (auto e: flow.g[i]) {
// 		if (e.f > 0) {
// 			cout << i << " " << e.dest << " " << e.f << endl;
// 		} 
// 	}
// }


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
		// cout << s << " " << t << " " << cap << endl;
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


int n, m, startLoc, numPeople, maxTime, numHospital;
bool isHospital[1005];

int vertex(int location, int time) {
	if (time == 0) return n * maxTime + 1;
	return (location - 1) * maxTime + time;
}

string trans(int vertex) {
	int loc = vertex / maxTime + 1;
	int time = vertex % maxTime;
	if (vertex == 0) {
		return "source";
	}
	if (vertex == maxTime * n + 2) {
		return "sink";
	}
	if (vertex == maxTime * n + 1) {
		loc = startLoc;
		time = 0;
	}
	if (vertex % maxTime == 0) {
		time += maxTime;
		loc -= 1;
	}

	return "(" + to_string(loc) + ", " + to_string(time) + ")";
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		memset(isHospital, 0, sizeof(isHospital));
		cin >> n;

		cin >> startLoc >> numPeople >> maxTime;

		cin >> numHospital;

		FOR (i, 1, numHospital) {
			int x;
			cin >> x;
			isHospital[x] = 1;
		}

		cin >> m;
		int source = 0;
		int sink = maxTime * n + 2;

		PushRelabel flow(sink + 1);

		flow.addEdge(source, vertex(startLoc, 0), numPeople);
		FOR (i, 1, m) {
			int u, v, cap, len;
			cin >> u >> v >> cap >> len;
			if (isHospital[u]) continue;
			if (u == startLoc) {
				FOR (t, 0, maxTime - len) {
					flow.addEdge(vertex(u, t), vertex(v, t + len), cap);
				}
			}
			else {
				FOR (t, 1, maxTime - len) {
					flow.addEdge(vertex(u, t), vertex(v, t + len), cap);
				}
			}
		}

		if (isHospital[startLoc]) {
			cout << numPeople << endl;
		}
		else {
			FOR (i, 1, n) {
				if (i == startLoc) {
					FOR (t, 0, maxTime - 1) {
						flow.addEdge(vertex(i, t), vertex(i, t + 1), numPeople);
					}
				}
				else {
					FOR (t, 1, maxTime - 1) {
						flow.addEdge(vertex(i, t), vertex(i, t + 1), numPeople);
					}
				}
			}
			FOR (i, 1, n) {
				if (isHospital[i]) {
					FOR (t, 1, maxTime) {
						flow.addEdge(vertex(i, t), sink, numPeople);
					}
				}
			}
			cout << flow.maxFlow(source, sink) << endl;

			// for (int i = 0; i < flow.g.size(); i++) {
			// 	for (auto e: flow.g[i]) {
			// 		if (e.f > 0) {
			// 			cout << trans(i) << " " << trans(e.dest) << " " << e.f << endl;
			// 		} 
			// 	}
			// }

		}
	}

	return 0;
}