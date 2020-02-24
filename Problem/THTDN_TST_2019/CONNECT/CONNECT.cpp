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

bool reachTo[100005], reachFrom[100005];
vector<int> adjTo[100005], adjFrom[100005];

void dfs(int a, bool *d, vector<int> *adj) {
	if (d[a]) return;
	d[a] = 1;
	for (auto i: adj[a]) dfs(i, d, adj);
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		memset(reachTo, 0, sizeof(reachTo));
		memset(reachFrom, 0, sizeof(reachFrom));
		int n, m;
		cin >> n >> m;
		FOR (i, 1, m) {
			int u, v;
			cin >> u >> v;
			adjTo[u].pb(v);
			adjFrom[v].pb(u);
		}

		dfs(1, reachTo, adjTo);
		dfs(2, reachFrom, adjFrom);

		int sumTo = 0, sumFrom = 0;
		
		FOR (i, 1, n) {
			sumTo += reachTo[i];
			sumFrom += reachFrom[i];
		}

		if (sumTo == n && sumFrom == n) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
		FOR (i, 1, n) {
			adjTo[i].clear();
			adjFrom[i].clear();
		}

	}
	

	return 0;
}