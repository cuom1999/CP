#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;


template<typename flow_t = int, typename cost_t = int>
struct MinCostFlow {
    struct Edge {
        cost_t c;
        flow_t f;
        int to, rev;
        bool real;
        Edge(int _to, cost_t _c, flow_t _f, int _rev, bool _real) : c(_c), f(_f), to(_to), rev(_rev), real(_real) {}
    };

    int N, S, T;
    vector<vector<Edge> > G;
    MinCostFlow(int _N, int _S, int _T) : N(_N), S(_S), T(_T), G(_N), eps(0) {}

    void clear() {
    	FOR (i, 0, N) {
    		G[i].clear();
    	}
    }

    void resize(int N) {
    	G.resize(N);
    }

    void addEdge(int a, int b, flow_t cap, cost_t cost) {
        assert(cap >= 0);
        assert(a >= 0 && a < N && b >= 0 && b < N);
        if (a == b) { assert(cost >= 0); return; }
        cost *= N;
        eps = max(eps, abs(cost));
        G[a].emplace_back(b, cost, cap, G[b].size(), 1);
        G[b].emplace_back(a, -cost, 0, G[a].size() - 1, 0);
    }

    flow_t getFlow(Edge const &e) {
        return G[e.to][e.rev].f;
    }

    pair<flow_t, cost_t> minCostMaxFlow() {
        cost_t retCost = 0;
        for (int i = 0; i<N; ++i) {
            for (Edge &e : G[i]) {
                retCost += e.c*(e.f);
            }
        }
        //find max-flow
        flow_t retFlow = max_flow();
        h.assign(N, 0); ex.assign(N, 0);
        isq.assign(N, 0); cur.assign(N, 0);
        queue<int> q;
        for (; eps; eps >>= scale) {
            //refine
            fill(cur.begin(), cur.end(), 0);
            for (int i = 0; i < N; ++i) {
                for (auto &e : G[i]) {
                    if (h[i] + e.c - h[e.to] < 0 && e.f) push(e, e.f);
                }
            }
            for (int i = 0; i < N; ++i) {
                if (ex[i] > 0){
                    q.push(i);
                    isq[i] = 1;
                }
            }
            // make flow feasible
            while (!q.empty()) {
                int u = q.front(); q.pop();
                isq[u]=0;
                while (ex[u] > 0) {
                    if (cur[u] == G[u].size()) {
                        relabel(u);
                    }
                    for (unsigned int &i=cur[u], max_i = G[u].size(); i < max_i; ++i) {
                        Edge &e = G[u][i];
                        if (h[u] + e.c - h[e.to] < 0) {
                            push(e, ex[u]);
                            if (ex[e.to] > 0 && isq[e.to] == 0) {
                                q.push(e.to);
                                isq[e.to] = 1;
                            }
                            if (ex[u] == 0) break;
                        }
                    }
                }
            }
            if (eps > 1 && eps>>scale == 0) {
                eps = 1<<scale;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (Edge &e : G[i]) {
                retCost -= e.c*(e.f);
            }
        }
        return make_pair(retFlow, retCost / 2 / N);
    }

private:
    static constexpr cost_t INFCOST = numeric_limits<cost_t>::max()/2;
    static constexpr int scale = 2;

    cost_t eps;
    vector<unsigned int> isq, cur;
    vector<flow_t> ex;
    vector<cost_t> h;
    vector<vector<int> > hs;
    vector<int> co;

    void add_flow(Edge& e, flow_t f) {
        Edge &back = G[e.to][e.rev];
        if (!ex[e.to] && f) {
            hs[h[e.to]].push_back(e.to);
        }
        e.f -= f; ex[e.to] += f;
        back.f += f; ex[back.to] -= f;
    }

    void push(Edge &e, flow_t amt) {
        if (e.f < amt) amt = e.f;
        e.f -= amt; ex[e.to] += amt;
        G[e.to][e.rev].f += amt; ex[G[e.to][e.rev].to] -= amt;
    }

    void relabel(int vertex){
        cost_t newHeight = -INFCOST;
        for (unsigned int i = 0; i < G[vertex].size(); ++i){
            Edge const&e = G[vertex][i];
            if(e.f && newHeight < h[e.to] - e.c){
                newHeight = h[e.to] - e.c;
                cur[vertex] = i;
            }
        }
        h[vertex] = newHeight - eps;
    }

    flow_t max_flow() {
        ex.assign(N, 0);
        h.assign(N, 0); hs.resize(2*N);
        co.assign(2*N, 0); cur.assign(N, 0);
        h[S] = N;
        ex[T] = 1;
        co[0] = N-1;
        for (auto &e : G[S]) {
            add_flow(e, e.f);
        }
        if (hs[0].size()) {
            for (int hi = 0; hi>=0;) {
                int u = hs[hi].back();
                hs[hi].pop_back();
                while (ex[u] > 0) { // discharge u
                    if (cur[u] == G[u].size()) {
                        h[u] = 1e9;
                        for(unsigned int i = 0; i < G[u].size(); ++i) {
                            auto &e = G[u][i];
                            if (e.f && h[u] > h[e.to]+1) {
                                h[u] = h[e.to]+1, cur[u] = i;
                            }
                        }
                        if (++co[h[u]], !--co[hi] && hi < N) {
                            for (int i = 0; i < N; ++i) {
                                if (hi < h[i] && h[i] < N) {
                                    --co[h[i]];
                                    h[i] = N + 1;
                                }
                            }
                        }
                        hi = h[u];
                    } else if (G[u][cur[u]].f && h[u] == h[G[u][cur[u]].to]+1) {
                        add_flow(G[u][cur[u]], min(ex[u], G[u][cur[u]].f));
                    } else {
                        ++cur[u];
                    }
                }
                while (hi>=0 && hs[hi].empty()) {
                    --hi;
                }
            }
        }
        return -ex[S];
    }
};

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};
int R[5], C[5];
int n, m;


int check(int r, int c) {
	if (r < 1 || r > n || c < 1 || c > m) return -1;
	FOR (i, 1, 4) {
		if (r == R[i] && c == C[i]) return i;
	}
	return 0;
}

int in[104][104], out[104][104];
II rin[20005], rout[20005];

II nextP[104][105];
MinCostFlow<int, int> mcmf(2, 0, 1);
vector<II> path, path1;

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    while (1) {
	    cin >> n >> m;
	    if (!n && !m) break;
	    path.clear();
	    path1.clear();
	    int CC = 0;


	    FOR (i, 1, 4) cin >> R[i] >> C[i];

	    int S0 = ++CC;
	    int S1 = ++CC;

	    out[R[1]][C[1]] = S0;
	    out[R[3]][C[3]] = S1;
	    rout[S0] = II(R[1], C[1]);
	    rout[S1] = II(R[3], C[3]);
	    int snk = 0;
	    FOR (i, 1, n) {
	    	FOR (j, 1, m) {
	    		int u = check(i, j);
	    		if (!u || u == 2) {
	    			in[i][j] = ++CC;
	    			rin[CC] = II(i, j);
	    			//cout << i << " " << j << " in: " << CC << endl;
	    			if (u == 2) snk = CC;
	    			if (!u) {
	    				out[i][j] = ++CC;
	    				rout[CC] = II(i, j);
	    				//cout << i << " " << j << " out: " << CC << endl;
	    			}
	    		}
	    	}
	    }

	    mcmf.clear();
	    mcmf.N = CC + 1;
	    mcmf.resize(mcmf.N);
	    mcmf.S = 0;
	    mcmf.T = snk;

	    mcmf.addEdge(0, 1, 1, 1);
	    mcmf.addEdge(0, 2, 1, 1);

	    FOR (i, 1, n) {
	    	FOR (j, 1, m) {
	    		int u = check(i, j);
	    		if (u != 4 && u != 2) {
	    			FOR (k, 0, 3) {
	    				int v = check(i + x[k], j + y[k]);
	    				if (v == 0 || v == 2) {
	    					mcmf.addEdge(out[i][j], in[i + x[k]][j + y[k]], 1, 0);
	    				}
	    			}
	    			if (!u) {
	    				mcmf.addEdge(in[i][j], out[i][j], 1, 1);
	    			}
	    		}
	       	}
	    }


	    II res = mcmf.minCostMaxFlow();
	    //cout << res.first << " " << res.second << endl;
	    if (res.first != 2) {
	    	cout << "NO" << endl;
	    	continue;
	    }
	    else {
	    	cout << "YES" << endl;
	    }

	    FOR (i, 1, CC) {
		    for (auto e: mcmf.G[i]) {
		    	if (e.real && mcmf.getFlow(e)) {
		    		nextP[rout[i].first][rout[i].second] = II(rin[e.to].first, rin[e.to].second);
		    	}
		    }
		}

		
		II cur = II(R[1], C[1]);
		path.pb(cur);
		while (cur != II(R[2], C[2])) {
			cur = nextP[cur.first][cur.second];
			path.pb(cur);
		}

		II cur1 = II(R[3], C[3]);
		path1.pb(cur1);
		while (cur1 != II(R[2], C[2])) {
			cur1 = nextP[cur1.first][cur1.second];
			//cout << cur1.first << " " << cur1.second << endl;
			path1.pb(cur1);
		}
		path1.pop_back();
		reverse(all(path1));
		for (auto i: path1) path.pb(i);

		for (int i = 0; i + 1 < path.size(); i++) {
			if (path[i + 1].first == path[i].first) {
				if (path[i + 1].second < path[i].second) {
					cout << "L";
				}
				else cout << "R";
			}
			else {
				if (path[i + 1].first < path[i].first) {
					cout << "D";
				}
				else cout << "U";	
			}
		}
		cout << endl;
	}


    
	
    return 0;
}