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

int d[300005][20];
int a[300005];

vector<int> v[20], adj[300006];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	FOR (i, 1, n) {
		cin >> a[i];
		FOR (j, 0, 19) {
			if (a[i] & (1 << j)) {
				v[j].pb(i);
			}
		}
	}

	FOR (i, 1, n) {
		FOR (j, 0, 19) d[i][j] = INF;
	}

	FOR (j, 0, 19) {
		for (int i = 0; i + 1 < v[j].size(); i++) {
			adj[v[j][i]].pb(v[j][i + 1]);
		}
		for (auto i: v[j]) {
			d[i][j] = min(d[i][j], i);
		}
	}

	FORD (i, n, 1) {
		FOR (j, 0, 19) {
			for (auto k: adj[i]) {
				d[i][j] = min(d[i][j], d[k][j]);
			}
		}
	}

	FOR (z, 1, q) {
		int x, y;
		cin >> x >> y;
		bool isGood = 0;

		FOR (j, 0, 19) {
			if (a[y] & (1 << j)) {
				if (d[x][j] <= y) {
					isGood = 1;
					break;
				}
			}
		}
		
		if (isGood) {
			cout << "Shi" << endl;
		}
		else {
			cout << "Fou" << endl;
		}
	}



	return 0;
}