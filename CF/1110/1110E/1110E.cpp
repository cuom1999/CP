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

int d[9][9][9], g[9][9][9], ma[9][9];
int a[1000005];

inline int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	FOR (i, 1, n) {
		int x;
		cin >> x;
		a[x]++;
	}
	int res = 0;
	FOR (i, 1, m) {
		if (a[i] > 8) {
			int u = a[i] % 3;
			if (u == 0) {
				res += (a[i] - 6) / 3;
				a[i] = 6;
			}
			else if (u == 1) {
				res += (a[i] - 7) / 3;
				a[i] = 7;
			}
			else {
				res += (a[i] - 8) / 3;
				a[i] = 8;
			}
		}
	}
	//cout << res << endl;
	//FOR (i, 1, m) cout << a[i] << " "; cout << endl; 

	if (m <= 2) {
		res += a[1] / 3 + a[2] / 3;
	}

	FOR (i, 3, m) {
		FOR (u, 0, a[i - 1]) {
			FOR (v, 0, a[i - 2]) {
				FOR (k, 0, a[i - 3]) {
					g[u][v][k] = d[u][v][k];
					ma[u][v] = max(ma[u][v], d[u][v][k]);
				}
			}
		}

		FOR (u, 0, a[i]) {
			FOR (v, 0, a[i - 1]) {
				FOR (k, 0, a[i - 2]) {
					d[u][v][k] = ma[v][k];

					if (u >= 3) {
						d[u][v][k] = max(d[u][v][k], d[u - 3][v][k] + 1); 
					}

					if (u && v && k) {
						d[u][v][k] = max(d[u - 1][v - 1][k - 1] + 1, d[u][v][k]);
					}
					if (i == 3) {
						if (v >= 3) d[u][v][k] = max(d[u][v][k], d[u][v - 3][k] + 1);
						if (k >= 3) d[u][v][k] = max(d[u][v][k], d[u][v][k - 3] + 1);
					}
					if (i == 4) {
						if (k >= 3) d[u][v][k] = max(d[u][v][k], d[u][v][k - 3] + 1);
					}
					//cout << i << " " << u << " " << v << " " << k << " " << d[u][v][k] << endl;
				}
			}
		}
	}
	int ans = 0;

	FOR (u, 0, a[m]) {
		FOR (v, 0, a[m - 1]) {
			FOR (k, 0, a[m - 2]) {
				ans = max(ans, d[u][v][k]);
			}
		}
	}
	cout << ans + res << endl;



	return 0;
}