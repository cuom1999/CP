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

int visited[5005];
vector<int> adj[5005];
int color[5005];

bool dfs(int a) {
    visited[a] = 1;
    
    for (auto i: adj[a]) {
        // cout << a << " " << i << " " << visited[i] << endl;
        if (visited[i] == 1) return 0;
        if (visited[i] == 0 && !dfs(i)) return 0;
    }
    visited[a] = 2;
    return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    FOR (i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        if (x < y) color[i] = 1;
        else color[i] = 2;
    }

    bool is1color = 1;
    FOR (i, 1, n) {
        if (!visited[i]) is1color &= dfs(i);

        // cout << is1color << endl;
    }

    if (is1color) {
        cout << 1 << endl;
        FOR (i, 1, m) cout << 1 << " ";
    }
    else {
        cout << 2 << endl;
        FOR (i, 1, m) cout << color[i] << " "; 
    }

    return 0;
}