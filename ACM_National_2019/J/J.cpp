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
//  if (e.flow && e.cap) {
//      cout << e.u << " " << e.v << " " << e.flow << endl;
//  }
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

vector<int> adj[200005];
vector<II> edges;
int match[100005], matched[100005];
int vs[200005];

int cc[200005];

void dfs(int u, int c) {
    vs[u] = 1;
    cc[u] = c;
    for (auto i: adj[u]) {
        if (!vs[i]) dfs(i, c);
    }
}

vector<int> allAdj[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    FOR (i, 1, m) {
        int x, y;
        cin >> x >> y;
        edges.pb({x, y});
    }

    int source = 0;
    int sink = 2 * n + 1;
    Dinic dinic(sink + 1);

    for (auto i: edges) {
        dinic.addEdge(i.first, i.second + n, 1);
    }

    FOR (i, 1, n) dinic.addEdge(source, i, 1);
    FOR (i, 1, n) dinic.addEdge(i + n, sink, 1);

    // cout << dinic.maxFlow(source, sink) << endl;
    dinic.maxFlow(source, sink);

    for (auto e: dinic.E) {
        if (e.flow && e.cap) {
            if (e.u != source && e.v != sink) {
                // cout << e.u << " " << e.v << endl;
                match[e.u] = e.v - n;
                matched[e.v - n] = e.u;
            }
        }
    }

    sort(all(edges));
    vector<II> newE;

    for (int i = 0; i < edges.size(); i++) {
        if (!i || edges[i] != edges[i - 1]) {
            if (edges[i].second != match[edges[i].first]) {
                newE.pb(edges[i]);
            }
        }
        else {
            newE.pb(edges[i]);
        }
    }

    int res = newE.size();

    for (auto i: newE) {
        allAdj[i.second].pb(i.first);

        adj[i.first].pb(matched[i.second]);
        cout << i.first << " " << matched[i.second] << endl;
        adj[matched[i.second]].pb(i.first);
    }

    int c = 0;
    FOR (i, 1, n) {
        if (!vs[i]) {
            dfs(i, ++c);
        }
    } 

    FOR (i, 1, n) {
        for (auto j: allAdj[match[i]]) {
            // cout << i << " " << j << endl;
            if (cc[i] == cc[j]) {
                res++;
                break;
            }
        }
    }

    cout << res << endl;
    

    return 0;
}