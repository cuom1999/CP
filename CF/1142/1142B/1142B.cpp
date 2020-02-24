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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

const int MAXN = 200005;

int d[MAXN], st[MAXN], p[MAXN], pos[MAXN], a[MAXN], last[MAXN], res[MAXN];
vector<II> query[MAXN];
vector<int> v[MAXN];
int par[MAXN][20];

void dfs(int a) {
	for (auto i: v[a]) {
		d[i] = d[a] + 1;
		par[i][0] = a;
		dfs(i);
	}
}

int getPar(int a, int h) {
	if (h == 0) return a;
	int res = a;
	FOR (i, 0, 19) {
		if (h & (1 << i)) {
			res = par[res][i];
		}
	}	
	return res;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, q;

    cin >> n >> m >> q;

    FOR (i, 1, n) {
    	cin >> p[i];
    	pos[p[i]] = i;
    }

    FOR (i, 1, m) {
    	int x;
    	cin >> x;
    	a[i] = pos[x];
    }

    FOR (i, 1, m) {
    	int u = a[i] - 1;
    	if (!u) u = n;

    	v[last[u]].pb(i);
    	
    	last[a[i]] = i;
    }

    dfs(0);

    FOR (i, 1, m) {
    	FOR (j, 1, 19) {
    		par[i][j] = par[par[i][j - 1]][j - 1];
    	}
    }

    FOR (i, 1, m) {
    	if (d[i] >= n) {
    		d[i] = n;
    		st[i] = getPar(i, n - 1);
    	}
    }

    FOR (i, 1, q) {
    	int x, y;
    	cin >> x >> y;
    	query[y].pb({x, i});
    }

    int maxSt = 0;

    FOR (i, 1, m) {
    	if (d[i] == n) maxSt = max(maxSt, st[i]);
    	for (auto q: query[i]) {
    		if (q.first <= maxSt) {
    			res[q.second] = 1;
    		}
    	}
    }

    if (n == 1) {
    	FOR (i, 1, q) res[i] = 1;
    }

    FOR (i, 1, q) cout << res[i];


	
    return 0;
}