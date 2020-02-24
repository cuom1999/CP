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

typedef pair < int, ll > II;
typedef pair < ll, ll > pll;

const int MAXN = 100005;

ll h[MAXN], s[MAXN];
int fuel[MAXN], p[MAXN][22], n;

vector<II> v[MAXN];

void dfs(int u, int par) {
	h[u] = h[par] + 1;
	p[u][0] = par;
	for (auto i: v[u]) {
		if (i.first == par) continue;
		s[i.first] = s[u] + i.second;
		dfs(i.first, u);
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

ll dist(int u, int v) {
	if (u == v) return 0;
	int l = LCA(u, v);
	return s[u] + s[v] - 2 * s[l];
}

vector<int> hasFuel;
int k, S, F;

vector<int> tree[MAXN];
bool dd[MAXN];


void dfs2(int u) {
	if (dd[u]) return;
	dd[u] = 1;
	for (auto i: tree[u]) {
		dfs2(i);
	}
}
	

bool solve(ll c) {
	FOR (i, 1, n) {
		tree[i].clear();
		dd[i] = 0;
	}

	for (auto i: hasFuel) {
		for (auto j: hasFuel) {
			if (i < j) {
				if (dist(i, j) <= c) {
					tree[i].pb(j);
					tree[j].pb(i);
					// cout << i << " " << j << endl;
				}
			}
		}
		if (!fuel[F]) {
			if (dist(i, F) <= c) {
				tree[i].pb(F);
				tree[F].pb(i);
				// cout << i << " " << F << endl;
			}
		}
		if (!fuel[S]) {
			// cout << i << " " << S << " " << dist(i, S) << endl;
			if (dist(i, S) <= c) {
				tree[i].pb(S);
				tree[S].pb(i);
				// cout << i << " " << S << endl;
			}
		}
	}
	if (dist(S, F) <= c) return 1;
	dfs2(S);
	if (dd[F]) return 1;
	return 0;
}
int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> S >> F;

	FOR (i, 1, k) {
		int x;
		cin >> x;
		fuel[x] = 1;
		hasFuel.pb(x);
	}

	FOR (i, 1, n - 1) {
		int x, y;
		ll c;
		cin >> x >> y >> c;
		v[x].pb({y, c});
		v[y].pb({x, c});
	}

	dfs(1, 0);
	init();
	// FOR (i, 0, 10) {
	// 	cout << solve(i) << " ";
	// }

	ll L = 0, R = 1e18;
	while(L < R) {
		ll mid = (L + R) / 2;
		if (solve(mid)) {
			R = mid;
		}
		else {
			L = mid + 1;
		}
	}

	cout << L << endl;



	return 0;
}