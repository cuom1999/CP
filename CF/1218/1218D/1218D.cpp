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

namespace FWT {
    typedef vector<int> Polynomial;
    int pw(int a, ll n, int mod) {
        if (n == 0) return 1;
        int q = pw(a, n / 2, mod);
        if (n % 2 == 0) return q * 1ll * q % mod;
        return q * 1ll * q % mod * a % mod;
    }

    void fwt(Polynomial& a, bool inv, int op, int mod, int n = 1) { // 1 xor 2 and 3 or
        while (a.size() > n) n <<= 1;
        int I2 = pw(2, mod - 2, mod);
        for (int i = 1; 2 * i <= n; i <<= 1) {
            for (int j = 0; j < n; j += 2 * i) {
                for (int k = 0; k < i; k++) {
                    int x = a[j + k]; int y = a[i + j + k];
                    if (!inv) {
                        if (op == 1) a[j + k] = (x + y) % mod, a[i + j + k] = (x - y + mod) % mod;
                        if (op == 2) a[j + k] = (x + y) % mod;
                        if (op == 3) a[i + j + k] = (x + y) % mod;
                    }
                    else {
                        if (op == 1) a[j + k]= 1ll * I2 * (x + y) % mod, a[i + j + k] = 1ll * I2 * (x - y + mod) % mod;
                        if (op == 2) a[j + k]= (x - y + mod) % mod;
                        if (op == 3) a[i + j + k] = (y - x + mod) % mod;
                    }
                }
            }
        }   
    }
    Polynomial multiply(Polynomial& a, Polynomial& b, int op, int mod) {
        int n = 1; 
        while (a.size() > n || b.size() > n) n <<= 1;
        fwt(a, 0, op, mod, n);
        fwt(b, 0, op, mod, n);

        Polynomial res(n);
        for (int i = 0; i < n; i++) {
            res[i] = a[i] * 1ll * b[i] % mod;
        }
        fwt(res, 1, op, mod, n);
        return res;
    }
}

struct Edge {
    int u, v, c;
};

vector<Edge> backEdges;
vector<II> adj[100005];
vector<int> cycle[45];
int vs[100005], h[100005], p[100005], edgeLen[100005];

void dfs(int u) {
    vs[u] = 1;
    for (auto i: adj[u]) {
        if (i.first == p[u]) continue;
        if (vs[i.first]) {
            if (u < i.first) backEdges.pb({u, i.first, i.second});
        }
        else {
            p[i.first] = u;
            h[i.first] = h[u] + 1;
            edgeLen[i.first] = i.second;
            dfs(i.first);
        }
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int xorAll = 0;
    int n, m;
    cin >> n >> m;
    FOR (i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb({v, c});
        adj[v].pb({u, c});
        xorAll ^= c;
    }   


    h[1] = 1;
    dfs(1);
    int numCycle = 0;
    for (auto e: backEdges) {
        int curU = e.u, curV = e.v;
        numCycle++;
        cycle[numCycle].pb(e.c);
        if (h[curU] > h[curV]) swap(curU, curV);
        while(h[curV] > h[curU]) {
            cycle[numCycle].pb(edgeLen[curV]);
            curV = p[curV];
        }
        while (curU != curV) {
            cycle[numCycle].pb(edgeLen[curU]);
            cycle[numCycle].pb(edgeLen[curV]);
            curU = p[curU];
            curV = p[curV];
        }
    }

    vector<int> a[45], b[45];
    const int MAXN = (1 << 17);
    const int MOD = 1e9 + 7;
    const int MOD2 = 77886769;

    FOR (i, 0, numCycle) {
        a[i].resize(MAXN);
        b[i].resize(MAXN);
    }

    FOR (i, 1, numCycle) {
        for (auto j: cycle[i]) {
            a[i][j]++;
            b[i][j]++;
        }
    }

    a[0][0] = 1;
    b[0][0] = 1;
    FOR (i, 0, numCycle) {
        FWT::fwt(a[i], 0, 1, MOD, MAXN);
        FWT::fwt(b[i], 0, 1, MOD2, MAXN);
    }
    FOR (i, 1, numCycle) {
        FOR (j, 0, MAXN - 1) {
            a[0][j] = a[0][j] * 1ll * a[i][j] % MOD;
            b[0][j] = b[0][j] * 1ll * b[i][j] % MOD2;
        }
    }
    FWT::fwt(a[0], 1, 1, MOD, MAXN);
    FWT::fwt(b[0], 1, 1, MOD2, MAXN);

    int minVal = INF;
    int cnt = 0;
    FOR (i, 0, MAXN - 1) {
        if (!a[0][i] && !b[0][i]) continue;
        if (minVal > (i ^ xorAll)) {
            minVal = i ^ xorAll;
            cnt = a[0][i];
        }
    }
    cout << minVal << " " << cnt << endl;

    return 0;
}