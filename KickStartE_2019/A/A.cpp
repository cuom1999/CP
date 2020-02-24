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

vector<int> adj[100005];
bool visited[100005];

void dfs(int u) {
	visited[u] = 1;
	for (auto i: adj[u]) {
		if (!visited[i]) dfs(i);
	}
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		int n, m;
		cin >> n >> m;

		FOR (i, 1, n) {
			visited[i] = 0;
			adj[i].clear();
		}
		FOR (i, 1, m) {
			int x, y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}

		int cnt = 0;
		FOR (i, 1, n) {
			if (!visited[i]) {
				dfs(i);
				cnt++;
			}
		}

		cout << "Case #" << z << ": " << n - 1 + cnt - 1 << endl;
	}

	return 0;
}