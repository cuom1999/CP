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

int getRoot(vector<int>& lab, int u) {
    while (lab[u] >= 0) u = lab[u];
    return u;
} 

void dsu(vector<int>& lab, int u, int v) {
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
}

int calc(vector<II>& edges, int a, int n) {
    vector<int> lab(n + 1);
    FOR (i, 1, n) lab[i] = -1;
    for (auto i: edges) {
        int u = getRoot(lab, i.first);
        int v = getRoot(lab, i.second);
        if (u != v) dsu(lab, u, v);
    }
    return n + lab[getRoot(lab, a)] - 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;

    FOR (z, 1, t) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<II> edges;
        FOR (i, 1, m) {
            int x, y;
            cin >> x >> y;
            edges.pb({x, y});
        }

        vector<II> ea, eb;
        for (auto i: edges) {
            if (i.first != a && i.second != a) {
                ea.pb(i);
            } 
            if (i.first != b && i.second != b) {
                eb.pb(i);
            }
        }
        int x = calc(ea, b, n);
        int y = calc(eb, a, n);
        cout << x * 1ll * y << "\n";
    }

    return 0;
}