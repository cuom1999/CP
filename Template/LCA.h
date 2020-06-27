
struct LCA {
    vector<vector<int>> adj, p;
    vector<int> h; // h[1] = 1
    int n, logn, root = 1;

    LCA(int n, const vector<vector<int>>& adj): n(n), adj(adj) {
        while ((1 << logn) <= n) logn++;
        p = vector<vector<int>>(n + 1, vector<int>(logn + 1));
        h = vector<int>(n + 1);
        dfs(1, 0);
        initJumps();
    }

    void dfs(int u, int par) {
        h[u] = h[par] + 1;
        p[u][0] = par;
        for (auto i: adj[u]) {
            if (i != par) dfs(i, u);
        }
    }

    void initJumps() {
        for (int j = 1; j <= logn; j++) {
            for (int i = 1; i <= n; i++) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }    
    }
    int lca(int u, int v){
        if (h[u] < h[v]) swap(u, v);
        if (h[v] < h[u]) {
            for (int i = logn; i >= 0; i--) {
                if (h[p[u][i]] >= h[v]) u = p[u][i];
            }
        }

        for (int i = logn; i >= 0; i--) {
            if (p[u][i] != p[v][i]) {
                u = p[u][i]; 
                v = p[v][i];
            }
        }
        
        while (u != v){
            u = p[u][0]; 
            v = p[v][0];
        }

        return u;
    }

};

