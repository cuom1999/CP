#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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


/// Remember dfs and hld first

const ll N=250005;

int nChain=1, chainHead[N], chainInd[N],p[N][20],sub[N],pos[N],h[N];
int nBase;
int n;
vector<int> v[N];
vector<int> Base;

void dfs(int a, int par){
    sub[a]=1;
    for (auto i:v[a]){
        if (i==par) continue;
        p[i][0]=a;
        h[i]=h[a]+1;
        dfs(i,a);
        sub[a]+=sub[i];
    }
}

void hld(int a, int par){
    if (chainHead[nChain]==0) chainHead[nChain]=a;
    chainInd[a]=nChain;
    pos[a]=++nBase;
    Base.pb(a);

    int mx=-1;
    for (auto i:v[a]){
        if (i!=par){
            if (mx==-1 || sub[mx]<sub[i]) mx=i;
        }
    }
    if (mx>-1) hld(mx,a);
    for (auto i:v[a]){
        if (i!=par && i!=mx){
            nChain++;
            hld(i,a);
        }
    }
}

int st[4 * N], lz[4 * N];

void down(int id, int l, int r) {
	if (l == r || (!lz[id])) return;
	lz[id] = 0;
	int mid = (l + r) / 2; 
	st[id * 2] = mid - l + 1 - st[id * 2];
	lz[id * 2] ^= 1;
	st[id * 2 + 1] = r - mid - st[id * 2 + 1];
	lz[id * 2 + 1] ^= 1;
}

void update(int id, int l, int r, int u, int v) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[id] = r - l + 1 - st[id];
		lz[id] ^= 1;
		return;
	}
	down(id, l, r);
	int mid = (l + r) / 2;
	update(id * 2, l, mid, u, v);
	update(id * 2 + 1, mid + 1, r, u, v);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

void query(int a, int u){ // u la LCA cua a
    int ac=chainInd[a];
    int uc=chainInd[u];
    while (1){
        if (uc==ac){
            //res=max(res,get(1,1,n,pos[u],pos[a]));
            update(1, 1, n, pos[u], pos[a]);
            break;
        }
        //res=max(res,get(1,1,n,pos[chainHead[ac]],pos[a]));
        update(1, 1, n, pos[chainHead[ac]], pos[a]);
        a=p[chainHead[ac]][0];
        ac=chainInd[a];
    }
}

void init(){
    FOR (i,1,19){
        FOR (j,1,n){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}

int LCA(int u, int v){
    if (h[v]<h[u]) FORD(i,19,0) if (h[p[u][i]]>=h[v]) u=p[u][i];
    if (h[u]<h[v]) FORD(i,19,0) if (h[p[v][i]]>=h[u]) v=p[v][i];

    FORD(i,19,0)if (p[u][i]!=p[v][i]) {u=p[u][i]; v=p[v][i];}
    while (u!=v){
        u=p[u][0]; v=p[v][0];
    }
    return u;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    FOR (i, 1, n - 1) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    dfs(1, 0);
    init();
    hld(1, 0);
    int m ;
 	cin >> m;
 	FOR (i, 1, m) {
 		int x, y;
 		cin >> x >> y;
 		query(x, 1);
 		query(y, 1);
 		cout << st[1] << endl;
 	}
	
    return 0;
}