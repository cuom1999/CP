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

vector<int> tree1[2005], tree2[2005];
int connect1[1005], connect2[1005];

int p[2005][15];
int h[2005];
int n, a, b;


void dfs2(int a, int par) {
    h[a] = h[par] + 1;
    p[a][0] = par;

    for (auto i: tree2[a]) {
        if (i != par) {
            dfs2(i, a);
        }
    }
}

void init(){
    FOR (i,1,12){
        FOR (j,2,b){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
//remember h[1]=1
int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,12,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,12,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,12,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}

int cost[1005][1005];
int l[2005], r[2005];

void dfs1(int a, int par) {
    for (auto i: tree1[a]) {
        if (i != par) {
            dfs1(i, a);
            l[a] = min(l[a], l[i]);
            r[a] = max(r[a], r[i]);
        }
    }
}

int dp(int a, int par) {
    int res = 0;
    for (auto i: tree1[a]) {
        if (i != par) {
            res += min(1 + dp(i, a), cost[l[i]][r[i]]);
        }
    }
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;

    cin >> a;
    FOR (i, 2, a) {
        int p;
        cin >> p;
        tree1[i].pb(p);
        tree1[p].pb(i);
    }    

    FOR (i, 1, a) l[i] = INF;

    FOR (i, 1, n) {
        int x;
        cin >> x;
        connect1[i] = x;
        l[x] = r[x] = i;
    }

    cin >> b;

    FOR (i, 2, b) {
        int p;
        cin >> p;
        tree2[i].pb(p);
        tree2[p].pb(i);
    }    

    FOR (i, 1, n) {
        int x;
        cin >> x;
        connect2[i] = x;
    }

    dfs2(1, 0);
    init();

    FOR (i, 1, n) {
        cost[i][i] = h[connect2[i]] - 1;
        FOR (j, i + 1, n) {
            cost[i][j] = cost[i][j - 1] + h[connect2[j]] - h[LCA(connect2[j], connect2[j - 1])];
        }
    }
    dfs1(1, 0);

    cout << a - 1 + b - 1 - dp(1, 0) << endl;
    return 0;
}