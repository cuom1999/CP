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

struct Game {
    int n, m;
    vector<int> adj[100005];
    vector<int> win, dp, vs;

    Game(int N, int M) {
        n = N;
        m = M;
        win.resize(n + 1);
        dp.resize(n + 1);
        vs.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adj[u].pb(v);
    }

    void dfs(int u) {
        vs[u] = 1;
        for (auto i: adj[u]) {
            if (!vs[i]) dfs(i);
            if (!win[i]) win[u] = 1;
        }

        if (win[u]) {
            dp[u] = INF;
            for (auto i: adj[u]) {
                if (!win[i]) {
                    dp[u] = min(dp[u], dp[i] + 1);
                }
            }
        }
        else {
            for (auto i: adj[u]) {
                dp[u] = max(dp[u], dp[i] + 1);
            }
        }
    }

    void solve() {
        FOR (i, 1, n) {
            if (!vs[i]) dfs(i);
        }
    }
};

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n1, m1;
    cin >> n1 >> m1;

    Game g1(n1, m1);
    FOR (i, 1, m1) {
        int x, y;
        cin >> x >> y;
        g1.addEdge(x, y);
    } 
    g1.solve();

    int n2, m2;
    cin >> n2 >> m2;
    Game g2(n2, m2);

    FOR (i, 1, m2) {
        int x, y;
        cin >> x >> y;
        g2.addEdge(x, y);
    }

    g2.solve();

    int q;
    cin >> q;

    FOR (z, 1, q) {
        int x, y;
        cin >> x >> y;

        if (g1.win[x] && g2.win[y]) {
            cout << "first\n";
        }
        else if (!g1.win[x] && !g2.win[y]) {
            cout << "second\n";
        }
        else if (g1.win[x]) {
            if (g1.dp[x] < g2.dp[y]) {
                cout << "first\n";
            }
            else cout << "second\n";
        }
        else {
            if (g2.dp[y] < g1.dp[x]) {
                cout << "first\n";
            } 
            else cout << "second\n";
        }
    }


    return 0;
}