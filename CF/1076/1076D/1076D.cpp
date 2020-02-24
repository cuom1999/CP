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

struct edge{
	int x, ind;
	ll c;
	edge (int __x = 0, int __ind = 0, ll __c = 0){
		x = __x;
		ind = __ind;
		c = __c;
	}
};
vector < edge > e[300005];

ll d[300004];

int n,m;

priority_queue < II, vector<II> , greater<II> > pq;
vector < II > V[300005];
int par[300005];
int t[300005];
void dij(ll a){
    FOR (i,1,n) d[i] = 1e18;
    d[a] = 0;

    ll du, uv, u, v;
    pq.push(II(0, a));
    while (!pq.empty()){
        du=pq.top().first;
        u=pq.top().second;
        pq.pop();
        if (d[u] != du) continue;
        for (auto i: e[u]){
            v = i.x;
            uv = i.c;
            if (d[v] > du+uv){
                d[v] = du+uv;
                pq.push(II(d[v], v));
                par[v] = u;
                t[v] = i.ind;
            }
        }
    }
}

priority_queue <II, vector < II >, greater < II > > pq1;
int dd[300005];
int deg[300005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int k;
    cin >> n >> m >> k;
    FOR (i, 1, m){
    	int x, y;
    	ll c;
    	cin >> x >> y >> c;
    	e[x].pb(edge(y, i, c));
    	e[y].pb(edge(x, i, c));
    }
    dij(1);
    FOR (i, 1, n) {
		deg[par[i]]++; 
		deg[i]++;   	
    }

    FOR (i, 2, n) {
    	pq1.push(II(deg[i], i));
    }

    if (k >= n - 1){
    	cout << n - 1 << endl;
    	FOR (i, 2, n) cout << t[i] << " "; 
    }
    else{
    	int cnt = n - 1;
    	while (cnt > k){
    		int x = pq1.top().second;
    		pq1.pop();
    		if (dd[x]) continue;
    		else{
    			cnt--;
    			dd[x] = 1;
    			deg[par[x]]--;
    			if (par[x] != 1) pq1.push(II(deg[par[x]], par[x]));
    		}
    	}
    	cout << k << endl;
    	FOR (i, 2, n) if (!dd[i]) cout << t[i] << " ";
    }
	
         return 0;
}