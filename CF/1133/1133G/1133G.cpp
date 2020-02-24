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

vector<int> v[200005];
int par[200005];
vector<II> edges, remainEdges;


void dfs(int a, int p) {
	for (auto i: v[a]) {
		if (i == 1) continue;

		if (!par[i]) {
			edges.pb(II(i, a));
			par[i] = p;
			dfs(i, p);
		}
		else {
			if (i < a) remainEdges.pb(II(i, a));
		}
	}
}

int getRoot(int a) {
	while (par[a] > 0) a = par[a];
	return a; 
}

void dsu(int a, int b) {
	if (par[a] < par[b]) {
		par[b] += par[a];
		par[a] = b;
	}
	else {
		par[a] += par[b];
		par[b] = a;
	}
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	int n, m, deg1;
	cin >> n >> m >> deg1;

	FOR (i, 1, m) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}   

	if (deg1 > v[1].size()) {
		cout << "NO" << endl;
		return 0;
	}

	par[1] = -1;
	for (auto i: v[1]) par[i] = -1;

	for (auto i: v[1]) {
		dfs(i, i);
	}

	int D = v[1].size();

	for (auto i: remainEdges) {
		if (D == deg1) break;

		int u1 = getRoot(i.first);
		int u2 = getRoot(i.second);

		if (u1 == u2) continue;

		dsu(u1, u2);

		edges.pb(i);

		D--;
	}

	if (D != deg1) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	for (auto i: v[1]) {
		if (par[i] < 0) {
			cout << 1 << " " << i << endl;
		}
	}

	for (auto i: edges) {
		cout << i.first << " " << i.second << endl;
	}

    return 0;
}