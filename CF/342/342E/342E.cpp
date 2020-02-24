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

int h[N];
int p[N][20];
int n;

void dfs(int a, int par){
	p[a][0]=par;
	for (int i:v[a]){
		if (i!=par){ 
			h[i]=h[a]+1;
			dfs(i,a);
		}
	}
}

void init(){
    FOR (i,1,18){
        FOR (j,1,n){
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

int dist(int u, int v){
	int a = LCA(u,v);
	return h[u]+h[v]-2*h[a];
}

int color[N];
int d[N];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int m;
    cin>>n>>m;
    FOR (i,1,n-1){
    	int x,y;
    	cin>>x>>y;
    	v[x].pb(y);
    	v[y].pb(x);
    }
    FOR (i,1,n){
    	for (auto j:v[i]) s[i].insert(j);
    }
    centroidDecomposition(1,0);


    color[1]=1;

    h[1]=1;
    dfs(1,0);
    init();
    FOR (i,1,n) d[i]=INF;

    int cur=1;
    d[1]=0;
    while (cenDad[cur]){
    	cur=cenDad[cur];
    	d[cur]=min(d[cur],dist(cur,1));
    }

    FOR (z,1,m){
    	int t,x;
    	cin>>t>>x;
    	if (t==1){
    		if (color[x]) continue;
    		color[x]=1;
    		int cur=x;
    		d[x]=0;
    		while (cenDad[cur]){
    			cur=cenDad[cur];
    			d[cur]=min(d[cur],dist(cur,x));
    		}
    	}
    	else{
    		int cur = x;
    		int res=d[cur];
    		while (cenDad[cur]){
    			cur=cenDad[cur];
    			res=min(res,d[cur]+dist(cur,x));
    		}
    		cout<<res<<endl;
    	}
    }
    
         return 0;
}