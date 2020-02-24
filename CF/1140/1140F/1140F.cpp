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

const int MAXN = 300000;

int sub[2 * MAXN + 5][2];
int par[2 * MAXN + 5];

int getRoot(int a) {
	while (par[a] > 0) {
		a = par[a];
	}
	return a;
}

ll ans = 0;

void dsu(int a, int b) {
	int x0 = sub[a][0] + sub[b][0];
	int x1 = sub[a][1] + sub[b][1];

	ans -= sub[a][0] * 1ll * sub[a][1] + sub[b][0] * 1ll * sub[b][1];
	ans += x0 * 1ll * x1;

	if (sub[a][0] + sub[a][1] < sub[b][0] + sub[b][1]) {
		sub[b][0] = x0;
		sub[b][1] = x1;
		par[a] = b;
	}
	else {
		sub[a][0] = x0;
		sub[a][1] = x1;
		par[b] = a;
	}
}

void removeDSU(int a, int b) {
	if (sub[a][0] + sub[a][1] < sub[b][0] + sub[b][1]) {
		sub[b][0] -= sub[a][0];
		sub[b][1] -= sub[a][1];
		par[a] = -1;
	}
	else {
		sub[a][0] -= sub[b][0];
		sub[a][1] -= sub[b][1];
		par[b] = -1;
	}	

	ans -= (sub[a][0] + sub[b][0]) * 1ll * (sub[a][1] + sub[b][1]);
	ans += sub[a][0] * 1ll * sub[a][1] + sub[b][0] * 1ll * sub[b][1];
}

vector<II> st[8 * MAXN];

void addEdge(int id, int l, int r, int u, int v, int x, int y) {
	if (v < l || r < u) return;

	if (u <= l && r <= v) {
		st[id].pb(II(x, y));
		return;
	}

	int mid = (l + r) / 2;

	addEdge(id * 2, l, mid, u, v, x, y);
	addEdge(id * 2 + 1, mid + 1, r, u, v, x, y);
}

unordered_map<int, int> prevApp[MAXN + 4];
ll res[MAXN + 5];

// dfs on Segment tree
void dfs(int id, int l, int r) {
	vector<II> operations;
	// dsu
	for (auto i: st[id]) {
		int m = getRoot(i.first);
		int n = getRoot(i.second);
		if (m == n) {
			continue;
		}

		operations.pb(II(m, n));
		dsu(m, n);
	}

	int mid = (l + r) / 2;

	if (l == r) {
		res[l] = ans;
	}
	else {
		dfs(id * 2, l, mid);
		dfs(id * 2 + 1, mid + 1, r);
	}
	
	// roll back
	reverse(all(operations));
	for (auto i: operations) {
		removeDSU(i.first, i.second);
	}
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
    int q;
    cin >> q;

    FOR (i, 1, q) {
		int x, y;
		cin >> x >> y;
		if (prevApp[x][y] == 0) {
			prevApp[x][y] = i;
		}
		else {
			addEdge(1, 1, q, prevApp[x][y], i - 1, x, y + MAXN);
			prevApp[x][y] = 0;
		}
    } 

    FOR (i, 1, MAXN) {
    	for (auto j: prevApp[i]) {
    		if (j.second > 0) {
    			addEdge(1, 1, q, j.second, q, i, j.first + MAXN);
    		}
    	}
    }

    memset(par, -1, sizeof(par));
    FOR (i, 1, MAXN) {
    	sub[i][0] = 1;
    	sub[i + MAXN][1] = 1;
    }

    dfs(1, 1, q);

    FOR (i, 1, q) cout << res[i] << " ";

    return 0;
}