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
	
void backTrack(int i, vector<int> &v) {
	if (i == m + 1) {
		int u[15][15];
		int maxVal[15];
		FOR (i, 1, n) maxVal[i] = -1;

		int sum = 0;
		FOR (i, 1, n) {
			FOR (j, 1, m) {
				int val = (i + v[j - 1]) % n;
				if (!val) val = n;
				u[i][j] = x[val][j];
				// cout << u[i][j] << " ";
				maxVal[i] = max(maxVal[i], u[i][j]);
			}
			// cout << i << " " << maxVal[i] << endl;
			sum += maxVal[i];
		}

		res = max(res, sum);

		return;
	}

	FOR (j, 0, n - 1) {
		v.pb(j);
		backTrack(i + 1, v);
		v.pop_back();
	} 
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
		vector<int> empty;
		backTrack(1, empty);
		cout << res << "\n";
	}

	return 0;
}