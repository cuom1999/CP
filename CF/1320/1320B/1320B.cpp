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

vector<int> adj[200005], inv[200005];
int p[200005];
ll cnt[200005];

const ll MOD = 1e9 + 9;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    FOR (i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[v].pb(u);
        inv[u].pb(v);
    }
    int k;
    cin >> k;
    FOR (i, 1, k) {
        cin >> p[i];
    } 

    queue<int> q;
    q.push(p[k]);

    vector<int> d(n + 1, -1), order;
    d[p[k]] = 0;

    while (q.size()) {
        int u = q.front();
        q.pop();
        order.pb(u);
        for (auto i: adj[u]) {
            if (d[i] == -1) {
                d[i] = d[u] + 1;
                q.push(i);
            }
        }
    }

    cnt[p[k]] = 1;
    for (auto i: order) {
        for (auto j: adj[i]) {
            if (d[j] == d[i] + 1) {
                cnt[j] = (cnt[j] + cnt[i]) % MOD;
            }
        }
    }

    int minAns = 0, maxAns = 0;
    FOR (i, 1, k - 1) {
        if (d[p[i + 1]] != d[p[i]] - 1) {
            minAns++;
            maxAns++;
        }
        else {
            if (cnt[p[i]] != cnt[p[i + 1]]) {
                maxAns++;
            }
        }
    }

    cout << minAns << " " << maxAns << endl;

    return 0;
}