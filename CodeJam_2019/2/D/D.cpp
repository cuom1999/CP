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

vector<int> v[N];

int num[N],low[N],vs[N];
int TIME,numSCC;
vector<int> SCC[100005], STACK;

void dfs(int a){
    low[a]=num[a]=++TIME;
    STACK.pb(a);
    for (auto i:v[a]){
        if (!num[i]) dfs(i);
        if (!vs[i]) low[a]=min(low[a],low[i]);
    }

    if (num[a]==low[a]) {
        numSCC++;
        while (STACK.size()){
            int b=STACK.back(); SCC[numSCC].pb(b);
            STACK.pop_back();
            vs[b]=1;
            if (b==a) break;
        }
    }
}

ll g[N];
int c1[N], c2[N];
int cycle[N];
int belongSCC[N];
vector<int> SCC_v[N];
vector<int> topo;

bool visited[N];
int n;

void dfs2(int v) {
    visited[v] = true;
    for (int u : SCC_v[v]) {
        if (!visited[u])
            dfs2(u);
    }
    topo.push_back(v);
}

void topological_sort() {
	FOR (i, 1, n) visited[i] = 0;
    topo.clear();
    for (int i = 1; i <= numSCC; ++i) {
        if (!visited[i])
            dfs2(i);
    }
    reverse(topo.begin(), topo.end());
}

ll sum[N];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		cin >> n;
		FOR (i, 1, n) {
			cin >> c1[i] >> c2[i];
			if (i == c1[i] || i == c2[i]) {
				cycle[i] = 1;
				if (g[i]) g[i] = -1;
			}
			v[i].pb(c1[i]);
			v[i].pb(c2[i]);
		}
		FOR (i, 1, n) cin >> g[i];

		FOR (i, 1, n) {
			if (!num[i]) dfs(i);
		}
		FOR (i,1,numSCC){
			for (auto j: SCC[i]) {
				belongSCC[j] = i;
			}
	    }

	    FOR (i, 1, numSCC) {
	    	for (auto j: SCC[i]) {
	    		for (auto k: v[j]) {
	    			SCC_v[i].pb(belongSCC[k]);
	    		}
	    	}
	    	for (auto j: SCC[i]) {
	    		sum[i] += g[j];
	    		if (g[j] == -1) {
	    			sum[i] = -1;
	    			break;
	    		}
	    	}
	    	if (sum[i] && SCC[i].size() > 1) sum[i] = -1;
	    }

	    topological_sort();

	    FOR (k, 0, numSCC - 1) {
	    	int i = topo[k];
	    	if (sum[i] && SCC[i].size() > 1) sum[i] = -1;
	    	if (i == belongSCC[1]) {
	    		if (sum[i] == -1) {
	    			cout << "UNBOUNDED" << endl;
	    		}
	    		else {
	    			cout << sum[i] << endl;
	    		}
	    	}
	    	for (auto j: SCC_v[i]) {
	    		if (sum[i] == -1) sum[j] = -1;
	    		else {
	    			sum[j] += sum[i];
	    		}
	    	}
	    }

		FOR (i, 1, n) {
			v[i].clear();
			SCC[i].clear();
			SCC_v[i].clear();
			low[i] = num[i] = 0;
			cycle[i] = 0;
			vs[i] = 0;
			sum[i] = 0;
		}
		numSCC = 0;
		topo.clear();
		STACK.clear();
		TIME = 0;
	}
	return 0;
}