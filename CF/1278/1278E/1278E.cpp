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

vector<int> adj[500005];
int open[500005], close[500005];
int TIME = 1;
void dfs(int a, int p) {
    for (auto i: adj[a]) {
        if (i == p) continue;
        open[i] = ++TIME;
    }
    close[a] = ++TIME;
    reverse(all(adj[a]));
    for (auto i: adj[a]) {
        if (i == p) continue;
        dfs(i, a);
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);  

    int n;
    cin >> n;

    FOR (i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // int TIME = 1;
    // vector<int> open(n + 1), close(n + 1);
    open[1] = 1;
    FOR (i, 1, n) {
        sort(all(adj[i]));
        reverse(all(adj[i]));
    }
    dfs(1, 0);
    // FOR (i, 1, n) {
    //     for (auto j: adj[i]) {
    //         open[j] = ++TIME;
    //         // cout << i << " " << j << " " << open[j] << endl;
    //     }
    //     close[i] = ++TIME;
    // }
    FOR (i, 1, n) cout << open[i] << " " << close[i] << "\n";

    return 0;
}