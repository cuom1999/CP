
struct CentroidDecomposition {
    int n, cenRoot;
    vector<int> cenDad, subCD;
    vector<vector<int>> cenChild, adj;
    vector<set<int>> s;

    CentroidDecomposition(int n, vector<vector<int>> adj): n(n), adj(adj) {
        cenDad.resize(n + 1);
        cenChild.resize(n + 1);
        s.resize(n + 1);
        subCD.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            for (auto j: adj[i]) s[i].insert(j);
        }
        centroidDec(1, 0);
    }

    int dfsCD(int a, int par) {
        subCD[a] = 1;
        for (int i: s[a]) {
            if (i != par) {
                dfsCD(i, a);
                subCD[a] += subCD[i];
            }
        }
        return subCD[a];
    }

    int centroid(int a, int p, int n) {
        for (auto i: s[a]) {
            if (i != p && subCD[i] > n / 2) {
                return centroid(i, a, n);
            }
        }
        return a;
    }

    void centroidDec(int a, int p) {
        int n = dfsCD(a, p);
        int cen = centroid(a, p, n);
        cenDad[cen] = p;
        if(p) cenChild[p].push_back(cen);
        else cenRoot = cen;

        for (int i:s[cen]){
            s[i].erase(cen);
            centroidDec(i,cen);
        }
    }

};

