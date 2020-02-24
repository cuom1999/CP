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

const ll MOD = 1e9 + 7;

struct Solver {
    vector<II> edges;
    Solver(vector<II>& e): edges(e){}
    unordered_map<int, int> lab;

    int getRoot(int a) {
        while (lab[a] >= 0) {
            a = lab[a];
        }
        return a;
    }

    void join(int a, int b) {
        if (lab[a] > lab[b]) {
            swap(a, b);
        }
        lab[a] += lab[b];
        lab[b] = a;
    }

    int solve() {
        for (auto e: edges) {
            lab[e.first] = lab[e.second] = -1;
        }
        for (auto e: edges) {
            int r1 = getRoot(e.first);
            int r2 = getRoot(e.second);
            if (r1 != r2) join(r1, r2);
        }
        int res = 0;
        for (auto i: lab) {
            if (i.second >= 0) {
                res++;
            }
        }
        return res;
    }    
};

ll pw2[500005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    pw2[0] = 1;
    FOR (i, 1, 500000) {
        pw2[i] = pw2[i - 1] * 2 % MOD;
    }

    int n, m, k;
    cin >> n >> m >> k;
    
    map<ll, vector<II>> edges;
    vector<ll> a(n + 1);

    FOR (i, 1, n) {
        cin >> a[i];
    }

    FOR (i, 1, m) {
        int u, v;
        cin >> u >> v;
        edges[a[u] ^ a[v]].pb({u, v});
    }

    ll res = 0;
    for (auto e: edges) {
        Solver s(e.second);
        int m = s.solve();

        ll val = n - m;
        res = (res + pw2[val]) % MOD;
    }

    ll rest = (1LL << k) - (ll) edges.size();
    res = (res + rest % MOD * pw2[n] % MOD) % MOD;

    cout << res << endl;
    return 0;
}