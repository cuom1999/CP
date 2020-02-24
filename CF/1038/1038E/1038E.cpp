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

vector<II> adj[5];
vector<int> cc[5];
int used[5];
ll w[5];

void dfs(int a, int c) {
    if (used[a]) return;
    used[a] = 1;
    cc[c].pb(a);
    for (auto i: adj[a]) {
        dfs(i.first, c);
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    int minEdge = INF;

    FOR (i, 1, n) {
        int u, val, v;
        cin >> u >> val >> v;
        adj[u].pb({v, val});
        adj[v].pb({u, val});
        w[u] += val;
        w[v] += val;
        minEdge = min(minEdge, val);
    }

    int numCC = 0;
    FOR (i, 1, 4) {
        if (!used[i]) {
            dfs(i, ++numCC);
        }
    }

    if (numCC > 1) {
        ll res = 0;
        FOR (i, 1, numCC) {
            ll total = 0;
            for (auto j: cc[i]) {
                total += w[j];
            }
            res = max(res, total / 2);
        }
        cout << res << endl;
    }
    else {
        int oddCnt = 0;
        FOR (i, 1, 4) {
            oddCnt += adj[i].size() % 2;
        }
        ll totalW = 0;
        FOR (i, 1, 4) {
            totalW += w[i];
        }
        totalW /= 2;
        if (oddCnt == 4) {
            cout << totalW - minEdge << endl;
        }
        else {
            cout << totalW << endl;
        }
    }




    return 0;
}