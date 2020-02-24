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

vector<int> v[100005];
struct edge{
	int x, y, c;
	edge(){}
	edge(int __x, int __y, int __c) {
		x = __x; y = __y;
		c = __c;
	}
};
vector<edge> E;

int dd[100005];
int num[100005], low[100005], out[100005];
int n, m;
	
int CC = 0;

int dfs(int a) {
	if (dd[a] == 1) return 1;
	if (dd[a] == -1) return 0;
	dd[a] = -1;	
	for (auto i: v[a]) {
		if (!dfs(i)) return 0;
	}
	dd[a] = 1;
	return 1;
}

bool solve(int C) {
	CC = 0;
	FOR (i, 1, n) {
		v[i].clear(), dd[i] = 0;
		out[i] = 0;
		//low[i] = num[i] = 0;
	}
	for (auto e: E) {
		if (e.c > C) {
			v[e.x].pb(e.y);
			out[e.y] = 1;
		}
	}
	bool q = 0;
	FOR (i, 1, n) {
		if (!dd[i]) {
			if (!dfs(i)) return 0;
		}
	}
	return 1;
}

vector<int> res;
vector<int> topo;

void topoSort(int a) {
	//cout << a << endl;
	if (dd[a]) return;
	dd[a] = 1;
	for (auto i: v[a]) {
		if (!dd[i]) topoSort(i);
	}
	topo.pb(a);
}
int ind[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >> m;    
	FOR (i, 1, m) {
		int x, y, c;
		cin >> x >> y >> c;
		E.pb(edge(x, y, c));
	}

	int L = 0, R = 1e9;
	while (L < R) {
		int mid = (L + R) / 2;
		//cout << L << " " << R << " " << " " << mid << solve(mid) << endl;
		if (solve(mid)) R = mid;
		else L = mid + 1;
	}
	
	cout << L << " ";
	solve(L);
	FOR (i, 1, n) {
		dd[i] = 0;
	}

	FOR (i, 1, n) {
		if (!dd[i]) topoSort(i);
	}

	reverse(all(topo));
	//for (auto i: topo) cout << i << " "; cout << endl;
	for (int i = 0; i < topo.size(); i++) {
		ind[topo[i]] = i;
	}

	for (int i = 0; i < E.size(); i++) {
		if (E[i].c <= L) {
			if (ind[E[i].x] > ind[E[i].y]) res.pb(i + 1);		
		}
	}

	cout << res.size() << endl;
	for (auto i: res) cout << i << " ";
	
    return 0;
}