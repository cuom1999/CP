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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

int a[15][2005], ma[2005], x[15][15];
int n, m;
int res = 0;
	
map<vector<int>, int> d[15];

int dp(int i, vector<int>& v) {
	if (d[i].count(v)) return d[i][v];
	if (i == m + 1) {
		int sum = 0;
		for (auto j: v) {
			sum += j;
		}
		return sum;
	}
	
	int res = 0;
	FOR (u, 0, n - 1) {
		vector<int> newV = v;
		int k[15];
		FOR (j, 1, n) {
			int val = (j + u) % n;
			if (!val) val = n;
			k[val] = x[j][i];
		}
		FOR (j, 1, n) {
			newV[j] = max(newV[j], k[j]);
		}
		res = max(res, dp(i + 1, newV));
	}
	return d[i][v] = res;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {

		res = 0;

		cin >> n >> m;

		FOR (i, 1, m) ma[i] = -1;

		FOR (i, 1, n) {
			FOR (j, 1, m) {
				cin >> a[i][j];
				ma[j] = max(ma[j], a[i][j]);
			}
		}
		vector<II> v;
		FOR (i, 1, m) {
			v.pb({ma[i], i});
		}
		sort(all(v));
		reverse(all(v));

		m = min(m, n);
		FOR (i, 0, m - 1) {
			int u = v[i].second;
			FOR (j, 1, n) {
				x[j][i + 1] = a[j][u];
			}
		}
		vector<int> vv(n + 1);
		FOR (i, 1, n) vv[i] = x[i][1];
		cout << dp(2, vv) << "\n";
	}

	return 0;
}