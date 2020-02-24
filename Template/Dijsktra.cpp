// for every edge u, v with length c:
// adj[u].push_back(II(v, c));
// adj[v].push_back(II(u, c)); if 2-way edge

typedef pair <int, int> II;
vector<II> adj[100005];
int d[100005]; // will be the shortest dist from a
int n; // number of vertices

priority_queue < II, vector<II>, greater<II> > pq;

void dijkstra(int a) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    d[a] = 0;

    pq.push(II(0, a));
    while (!pq.empty()) {
        int du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d[u] != du) continue;
        
        for (auto i: adj[u]){
            int v = i.first;
            int uv = i.second;

            // this v is better
            if (d[v] > du + uv){
                d[v] = du + uv;
                pq.push(II(d[v],v)); // push the better one
            }
        }
    }
}
