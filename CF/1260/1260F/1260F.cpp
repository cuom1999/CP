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


const int N=100005;

int subCD[N], cenDad[N], cenRoot;
vector<int> v[N], cenChild[N];
set<int> s[N];

int dfsCD(int a, int p){
    subCD[a]=1;
    for (int i:s[a]){
        if (i!=p){
            dfsCD(i,a);
            subCD[a]+=subCD[i];
        }
    }
    return subCD[a];
}

int centroid(int a, int p, int n){
    for (auto i:s[a]){
        if (i!=p && subCD[i]>n/2){
            return centroid(i,a,n);
        }
    }
    return a;
}

//call centroidDecomposition(1,0)
void centroidDecomposition(int a, int p){
    int n = dfsCD(a,p);
    int cen = centroid(a,p,n);
    cenDad[cen] = p;
    if(p) cenChild[p].pb(cen);
    else cenRoot = cen;

    for (int i:s[cen]){
        s[i].erase(cen);
        centroidDecomposition(i,cen);
    }
}

int p[N][20], h[N];

void dfs(int u, int par) {
    h[u] = h[par] + 1;
    p[u][0] = par;
    for (auto i: v[u]) {
        if (i != par) {
            dfs(i, u);
        }
    }
}
int n;
    
void init(){
    FOR (i,1,18){
        FOR (j, 1, n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
//remember h[1]=1
int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,17,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,17,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,17,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}

ll dist(int u, int v) {
    return h[u] + h[v] - 2 * h[LCA(u, v)];
}

const ll K = 1e9 + 7;
vector<int> open[N], close[N];
ll val[N], num[N];



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    FOR (i, 1, n) {
        int l, r;
        cin >> l >> r;
        open[l].pb(i);
        close[r].pb(i);
    }
    FOR (i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    FOR (i, 1, n){
        for (auto j:v[i]) s[i].insert(j);
    }
    centroidDecomposition(1, 0);
    dfs(1, 0);
    ll res = 0;
    ll currSum = 0;
    FOR (i, 1, 100000) {
        for (auto j: open[i]) {
            int curr = j;
            while (curr) {
                ll currDist = dist(curr, j);
                currSum += val[curr] + num[curr] * 1ll * currDist;
                currSum %= K;
                val[curr] += currDist;
                num[curr]++;
                curr = cenDad[curr];
            }
        }
        res += currSum;
        res %= K;

        for (auto j: close[i]) {
            int curr = j;
            while (curr) {
                ll currDist = dist(curr, j);
                val[curr] -= currDist;
                num[curr]--;
                
                currSum -= val[curr] + num[curr] * 1ll * currDist;
                currSum %= K;
                curr = cenDad[curr];
            }
            cout << j << " " << currSum << endl;
        }
    }
    cout << res << endl;
    return 0;
}