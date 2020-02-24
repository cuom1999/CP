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

struct Edge {
	int x, y, c;
};

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int n, m;
		ll d[55][55];
		vector<Edge> e;
		cin >> n >> m;

		FOR (i, 1, n) {
			FOR (j, 1, n) {
				if (i == j) d[i][j] = 0;
				else d[i][j] = INF;
			}
		}


		FOR (i, 1, m) {
			int u, v, c;
			cin >> u >> v >> c;
			d[u][v] = d[v][u] = min(d[u][v], (ll) c);
			e.pb({u, v, c});
		}
		FOR (k, 1, n) {
			FOR (i, 1, n) {
				FOR (j, 1, n) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}

		bool isGood = 1;

		for (auto i: e) {
			if (d[i.x][i.y] != i.c) {
				isGood = 0;
				break;
			}
		}
		if (!isGood) {
			cout << "Impossible\n";
		}
		else {
			cout << e.size() << endl;
			for (auto i: e) {
				cout << i.x << " " << i.y << " " << i.c << endl;
			}
		}
	}

	return 0;
}