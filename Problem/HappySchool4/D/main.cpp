#include <bits/stdc++.h>
using namespace std;

vector<int> adj[300005];
int a[300005];
bool vs[300005];

void dfsCheck(int a, int par) {
    if (vs[a]) {
        cout << "Not a tree" << endl;
        exit(1);
    }
    vs[a] = 1;
    for (auto i: adj[a]) {
        if (i != par) {
            dfsCheck(i, a);
        }
    }
}

int dp[300005][2], maxPath[300005];

void dfs(int u, int par) {
    vs[u] = 1;
    dp[u][0] = dp[u][1] = 1;
    for (auto i: adj[u]) {
        if (i == par) continue;
        dfs(i, u);
        if (a[i] < a[u]) {
            dp[u][0] = max(dp[u][0], dp[i][0] + 1);
        }
        else {
            dp[u][1] = max(dp[u][1], dp[i][1] + 1);
        }
    }
    maxPath[u] = dp[u][0] + dp[u][1] - 1;
}

int solve(int d, vector<pair<int, int>> edges) {
    for (auto e: edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
        vs[e.first] = vs[e.second] = 0;
    }

    for (auto e: edges) {
        if (!vs[e.first]) dfs(e.first, 0);
        if (!vs[e.second]) dfs(e.second, 0);
    }
    int res = 0;
    for (auto e: edges) {
        res = max(res, maxPath[e.first]);
        res = max(res, maxPath[e.second]);
        adj[e.first].clear();
        adj[e.second].clear();
    }
    return res;
}   

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<pair<int, int>> edges;

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            dfsCheck(i, 0);
        }
    }

    map<int, vector<pair<int, int>>> groups;  
    for (auto e: edges) {
        groups[abs(a[e.first] - a[e.second])].push_back({e.first, e.second});
    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vs[i] = 0;
    }

    for (auto e: groups) {
        cout << e.first << " " << solve(e.first, e.second) << "\n"; 
    }
    return 0;
}