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

vector<int> adj[100005];
int n;
int curK;

II dp[100005];
int res[100005];

void dfs(int u) {
    int firstMax = 0, secondMax = 0;
    for (int &i: adj[u]) {
        dfs(i);
        if (firstMax == 0) firstMax = dp[i].second;
        else {
            secondMax = max(secondMax, dp[i].second);
            if (firstMax < secondMax) swap(firstMax, secondMax);
        }
        dp[u].first += dp[i].first;
    }
    if (firstMax + secondMax + 1 >= curK) {
        dp[u].first++;
    }
    else {
        dp[u].second = firstMax + 1;
    }
    // cout << u << " " << dp[u].first << " " << dp[u].second << endl;
}

inline int calc(int k) {
    if (res[k] != -1) return res[k];
    memset(dp, 0, sizeof(dp));
    curK = k;
    dfs(1);
    return res[k] = dp[1].first;
}

int par[100005];
void dfs1(int u, int p) {
    par[u] = p;
    for (auto i: adj[u]) {
        if (i != p) dfs1(i, u);
    }
}
void solve(int l, int r, int lower, int upper) {
    if (lower == upper) {
        FOR (i, l, r) res[i] = lower;
        return;
    }
    if (l > r) return;
    int mid = (l + r) / 2;
    int valMid = calc(mid);

    solve(l, mid - 1, valMid, upper);
    solve(mid + 1, r, lower, valMid);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    memset(res, -1, sizeof(res));
    cin >> n;
    FOR (i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs1(1, 0);
    FOR (i, 2, n) {
        adj[i].erase(find(all(adj[i]), par[i]));
    }

    int m = min(400, n);
    curK = m;
    FOR (k, 1, m) {
        res[k] = calc(k);
    }

    solve(m + 1, n, 0, res[m]);

    FOR (i, 1, n) cout << res[i] << '\n';

    return 0;
}