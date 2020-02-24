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
typedef pair < ll, ll > II;


vector<II> e[100004];
ll d[50][100004];
int n,m;

priority_queue < II, vector<II> , greater<II> > pq;
void dij(int a, int j){
    FOR (i,1,n) d[j][i]=(1e18);
    d[j][a]=0;

    ll du,uv,u,v;
    pq.push(II(0,a));
    while (!pq.empty()){
        du=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if (d[j][u]!=du) continue;
        for (auto i: e[u]){
            v=i.second;
            uv=i.first;
            if (d[j][v]>du+uv){
                d[j][v]=du+uv;
                pq.push(II(d[j][v],v));
            }
        }
    }
}

struct edge{
	int x,y,c;
	edge(int __x=0, int __y=0, int __c=0){
		x=__x; y=__y; c=__c;
	}
};

vector<edge> E;

int lab[100005];

int getRoot(int a){
	while (lab[a]>=0) a=lab[a];
	return a;
}

void DSU(int a, int b){
	int x=lab[a]+lab[b];
	if (lab[a]>lab[b]){
		lab[a]=b;
		lab[b]=x;
	}
	else{
		lab[b]=a;
		lab[a]=x;
	}
}

vector<II> v[100005];

int p[100005][25], h[100005];
ll w[100005];

void dfs(int a, int par){
	p[a][0]=par;
	for (auto i:v[a]){
		if (i.second==par) continue;
		h[i.second]=h[a]+1;
		w[i.second]=w[a]+i.first;
		dfs(i.second,a);
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

set<int> F;

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>m;
    FOR (i,1,n) lab[i]=-1;
    FOR (i,1,m){
		int x,y,c;
		cin>>x>>y>>c;
		e[x].pb(II(c,y));
		e[y].pb(II(c,x));    	
		E.pb(edge(x,y,c));
    }
    for (auto q:E){
    	int x=getRoot(q.x);
    	int y=getRoot(q.y);
    	if (x==y) {
    		F.insert(q.x);
    		F.insert(q.y);
    	}
    	else{
    		DSU(x,y);
    		v[q.x].pb(II(q.c,q.y));
    		v[q.y].pb(II(q.c,q.x));
    	}
    }

    h[1]=1;
    dfs(1,0);
    init();
    int STT=0;
    for (auto i:F){
    	int q=i;
    	STT++;
    	dij(q,STT);
    }
   	//cout<<STT<<endl;
   	int Q;
   	cin>>Q;
   	FOR (z,1,Q){
   		int x,y;
   		cin>>x>>y;
   		int c=LCA(x,y);	
   		ll res=w[x]+w[y]-2*w[c];
   		FOR (u,1,STT){
   			res=min(res,d[u][x]+d[u][y]);
   		}
   		cout<<res<<endl;
   	}


    
	
         return 0;
}