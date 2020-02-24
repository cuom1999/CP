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

vector<int> adj[2005];
vector<int> v[2005];
int num[2005], c[2005], sub[2005];

void dfs1(int u) {
    for (auto i: adj[u]) {
        dfs1(i);
        sub[u] += 1 + sub[i];
    }
}

void dfs(int u) {
    for (auto i: adj[u]) {
        dfs(i);
        for (auto j: v[i]) {
            v[u].pb(j);
        }
    }
    // cout << u << endl;
    v[u].insert(v[u].begin() + c[u], u);
    // cout << u << ": ";
    // for (auto i: v[u]) cout << i << " ";
    // cout << endl;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    int root; 
    FOR (i, 1, n) {
        int p;
        cin >> p >> c[i];
        if (p) adj[p].pb(i);
        else root = i;
    }

    dfs1(root);
    FOR (i, 1, n) {
        if (sub[i] < c[i]) {
            cout << "NO";
            return 0;
        }
    }
    dfs(root);
    FOR (i, 0, n - 1) {
        num[v[root][i]] = i + 1;
    }
    cout << "YES\n";
    FOR (i, 1, n) cout << num[i] << " ";  

    return 0;
}