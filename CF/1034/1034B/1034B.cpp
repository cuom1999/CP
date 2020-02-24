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


const int maxv = 1000;
const int maxe = 50000;
struct EdmondsLawler {
	int n, E, start, finish, newRoot, qsize, adj[maxe], next[maxe],
	last[maxv], mat[maxv], que[maxv], dad[maxv], root[maxv];
	bool inque[maxv], inpath[maxv], inblossom[maxv];
	void init(int _n) {
		n = _n; E = 0;
		for(int x=1; x<=n; ++x) { last[x] = -1; mat[x] = 0; }
	}
	void addEdge(int u, int v) {
		adj[E] = v; next[E] = last[u]; last[u] = E++;
	}
	int lca(int u, int v) {
		for(int x=1; x<=n; ++x) inpath[x] = false;
		while (true) {
			u = root[u];
			inpath[u] = true;
			if (u == start) break;
			u = dad[mat[u]];
		} 
		while (true) {
			v = root[v];
			if (inpath[v]) break;
			v = dad[mat[v]];
		} 
		return v;
	} 
	void trace(int u) {
		while (root[u] != newRoot) {
			int v = mat[u];
			inblossom[root[u]] = true;
			inblossom[root[v]] = true;
			u = dad[v];
			if (root[u] != newRoot) dad[u] = v;
		}
	} 
	void blossom(int u, int v) {
		for(int x=1; x<=n; ++x) inblossom[x] = false;
			newRoot = lca(u, v);
		trace(u); trace(v);
		if (root[u] != newRoot) dad[u] = v;
		if (root[v] != newRoot) dad[v] = u;
		for(int x=1; x<=n; ++x) if (inblossom[root[x]]) {
			root[x] = newRoot;
			if (!inque[x]) {
				inque[x] = true;
				que[qsize++] = x;
			}
		}
	} 
	bool bfs() {
		for(int x=1; x<=n; ++x){
			inque[x] = false;
			dad[x] = 0;
			root[x] = x;
		} 
		qsize = 0;
		que[qsize++] = start;
		inque[start] = true;
		finish = 0;
		for(int i=0; i<qsize; ++i) {
			int u = que[i];
			for (int e = last[u]; e != -1; e = next[e]) {
				int v = adj[e];
				if (root[v] != root[u] && v != mat[u]) {
					if (v == start || (mat[v] > 0 && dad[mat[v]] > 0)) blossom(u, v);
					else if (dad[v] == 0) {
						dad[v] = u;
						if (mat[v] > 0) que[qsize++]= mat[v];
						else {
							finish = v;
							return true;
						}
					}
				}
			}
		} 
		return false;
	} 
	void enlarge() {
		int u = finish;
		while (u > 0) {
			int v = dad[u], x = mat[v];
			mat[v] = u;
			mat[u] = v;
			u = x;
		}
	} 
	int maxmat() {
		for(int x=1; x<=n; ++x) if (mat[x] == 0) {
			start = x;
			if (bfs()) enlarge();
		} 
		int ret = 0;
		for(int x=1; x<=n; ++x) if (mat[x] > x) ++ret;
			return ret;
	}
};
EdmondsLawler edmon;
int m,n;
int has(int x, int y){
	return x*n+y+1; 
}
int abs(int x){
	if (x<0) x=-x;
	return x;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>m>>n;
    if (m>n) swap(m,n);
    if (m==1){
    	if (n%6==0) {
    		cout<<m*1ll*n;
    	}
    	if (n%6==1){
    		cout<<m*1ll*n-1;
    	}
    	if (n%6==2){
    		cout<<m*1ll*n-2;
    	}
    	if (n%6==3){
    		cout<<m*1ll*n-3;
    	}
    	if (n%6==4){
    		cout<<m*1ll*n-2;
    	}
    	if (n%6==5){
    		cout<<m*1ll*n-1;
    	}
    }
    else{
	    if (m<=10 && n<=10){
	    	edmon.init(m*n);
	    	FOR (i,0,m-1){
	    		FOR (j,0,n-1){
	    			FOR (i1,0,m-1){
	    				FOR (j1,0,n-1){
	    					if (abs(i-i1)+abs(j-j1)==3){
	    						edmon.addEdge(has(i,j),has(i1,j1));
	    						//cout<<i<<" "<<j<<" "<<i1<<" "<<j1<<endl;
	    						//cout<<has(i,j)<<" "<<has(i1,j1)<<endl;
	    					}
	    				}
	    			}
	    		}
	    	}
	    	cout<<2*edmon.maxmat()<<endl;
	    	//FOR (i,1,m*n) cout<<edmon.mat[i]<<" ";
	  	}
	  	else{
	  		ll u=m*1ll*n;
	  		if (u%2==0) cout<<u;
	  		else cout<<u-1;
	  	}
	}


	    
	
         return 0;
}