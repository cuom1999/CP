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

ll K;
int n;

ll d[100005][2], sub[100005];
vector<int> v[100005];
ll mu_2[100005];
int par[100005];
ll prod[100005];
ll prefixP[100005], sufP[100005];

void dfs(int a, int p) {
	sub[a] = 1;
	par[a] = p;

	for (int i = 0; i < v[a].size(); i++) {
		if (v[a][i] == p) {
			v[a].erase(v[a].begin() + i);
			break;
		}
	}

	for (auto i: v[a]) {
		dfs(i, a);
		sub[a] += sub[i];
	}
	d[a][0] = 1;

	for (auto i: v[a]) {
		d[a][0] = d[a][0] * (d[i][0] + 1) % K;
	}
	d[a][1] = (mu_2[sub[a]] - 1 - d[a][0] + K) % K;

	if (v[a].size() == 0) return;
	if (v[a].size() == 1) {
		prod[v[a][0]] = 1;
		return;
	}

	for (int i = 0; i < v[a].size(); i++) {
		if (i == 0) {
			prefixP[i] = d[v[a][0]][0] + 1;
		}
		else {
			prefixP[i] = prefixP[i - 1] * (d[v[a][i]][0] + 1) % K;
		}
	}

	for (int i = v[a].size() - 1; i >=0; i--) {
		if (i == v[a].size() - 1) {
			sufP[i] = d[v[a][i]][0] + 1;
		}
		else {
			sufP[i] = sufP[i + 1] * (d[v[a][i]][0] + 1) % K;
		}
	}

	FOR (i, 0, v[a].size() - 1) {
		if (i == 0) {
			prod[v[a][i]] = sufP[1];
		}
		else if (i == v[a].size() - 1) {
			prod[v[a][i]] = prefixP[v[a].size() - 2];
		}
		else {
			prod[v[a][i]] = prefixP[i - 1] * sufP[i + 1] % K;
		}
 	}
}

int vs[100005];
ll f[100005], g[100005]; // f = g * d[a][0]

void dfs2(int a) {
	if (vs[a] || a == 1) {
		return;
	}
	vs[a] = 1;
	dfs2(par[a]);
	g[a] = (prod[a] * g[par[a]] % K + 1) % K;
	f[a] = g[a] * d[a][0] % K;
}



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> K;

    FOR (i, 1, n - 1) {
    	int x, y;
    	cin >> x >> y;
    	v[x].pb(y);
    	v[y].pb(x);
    }

    mu_2[0] = 1;
    FOR (i, 1, n) mu_2[i] = mu_2[i - 1] * 2LL % K;

    dfs(1, 0);
    f[1] = d[1][0];
    g[1] = 1;

    FOR (i, 1, n) dfs2(i);

    FOR (i, 1, n) cout << f[i] << "\n";

 	
    return 0;
}