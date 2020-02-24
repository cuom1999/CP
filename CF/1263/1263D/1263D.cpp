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


string s[200006];
vector<int> cc[30];

vector<int> adj[200005];
bool vs[200005];
void dfs(int a) {
    if (vs[a]) return;
    vs[a] = 1;
    for (auto i: adj[a]) {
        dfs(i);
    }
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) {
        cin >> s[i];
        for (int j = 0; j < s[i].size(); j++) {
            cc[s[i][j] - 'a'].pb(i);
        }
    }

    FOR (i, 0, 25) {
        for (int j = 0; j + 1 < cc[i].size(); j++) {
            int u = cc[i][j];
            int v = cc[i][j + 1];
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    int res = 0;
    FOR (i, 1, n) {
        if (!vs[i]) {
            dfs(i);
            res++;
        }
    }
    cout << res << endl;

    return 0;
}