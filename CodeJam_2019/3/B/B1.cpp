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

const ll K = 1e9 + 7;
const int MAXN = 3005;


ll d[MAXN][MAXN], ma[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];
ll a[MAXN];
int opt[MAXN][MAXN];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;

	cin >> t;


	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int n;
		cin >> n;

		FOR (i, 1, n) {
			cin >> a[i];
		}

		FOR (i, 1, n) {
			FOR (j, i, n) {
				if (i == j) {
					ma[i][j] = a[i];
					continue;
				}
				ma[i][j] = max(ma[i][j - 1], a[j]);
			}
		}

		FOR (i, 1, n) {
			FOR (j, i, n) {
				if (i == j) {
					l[i][j] = 0;
				}
				else {
					l[i][j] = l[i][j - 1];
					if (a[j] < ma[i][j - 1]) {
						l[i][j] += ma[i][j - 1] - a[j];
					}
				}
			}
		}

		FORD (j, n, 1) {
			FORD (i, j, 1) {
				if (i == j) {
					r[i][j] = 0;
				}
				else {
					r[i][j] = r[i + 1][j];
					if (a[i] < ma[i + 1][j]) {
						r[i][j] += ma[i + 1][j] - a[i];
					}
				}
			} 
		}
		ll res = 0;

		FOR (i, 1, n) {
			opt[i][i] = i;
		}

		FOR (len, 1, n - 1) {
			FOR (i, 1, n - len) {
				int j = i + len;
				ll val = 1e18;
				FOR (k, opt[i][j - 1], opt[i + 1][j]) {
					if (l[i][k] + r[k][j] < val) {
						opt[i][j] = k;
						val = l[i][k] + r[k][j];
					}
				}
				d[i][j] = val;
				res = (res + val) % K;
				// cout << i << " " << j << " " << val << endl;
			} 
		}

		cout << res << endl;
	}
	return 0;
}