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

int sub[100005];
vector<int> adj[100005];
bool dp[100005];

void dfs(int u, int p) {
    sub[u] = 1;
    for (auto i: adj[u]) {
        if (i == p) continue;
        dfs(i, u);
        sub[u] += sub[i];
    }
    dp[u] = 1;
    int cntOdd = 0;
    for (auto i: adj[u]) {
        if (i == p) continue;
        dp[u] &= dp[i];
        cntOdd += sub[i] % 2;
    }
    if (!dp[u]) return;
    if (cntOdd > 1) dp[u] = 0;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0);
    if (n % 2) {
        cout << "Alice" << endl;
        return 0;
    }
    if (dp[1]) {
        cout << "Bob" << endl;
    }
    else {
        cout << "Alice" << endl;
    }


    return 0;
}