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

bool d[4005][4005];
int pre[4005][4005];
bool dd[4005];
int a[4005];

vector<int> v[4005];
vector<int> cc[4005];

void dfs(int a, int c) {
	if (dd[a]) return;
	cc[c].pb(a);
	dd[a] = 1;
	for (auto i: v[a]) {
		dfs(i, c);
	}
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int n, m;
		cin >> n >> m;

		FOR (i, 1, m) {
			int x, y;
			cin >> x >> y;
			for (int i = x; i < x + y - i; i++) {
				v[i].pb(x + y - i);
				v[x + y - i].pb(i);
			}
		}

		int C = 0;
		FOR (i, 1, n) {
			if (!dd[i]) dfs(i, ++C);
		} 

		// FOR (i, 1, C) {
		// 	for (auto j: cc[i]) cout << j << " ";
		// 	cout << endl;
		// }

		FOR (i, 1, C) {
			a[i] = cc[i].size();
			// cout << a[i] << " ";
		}

		d[0][0] = 1;

		FOR (i, 1, C) {
			FOR (j, 0, n) {
				d[i][j] = d[i - 1][j];
				if (j >= a[i]) d[i][j] |= d[i - 1][j - a[i]]; 
				if (d[i - 1][j]) {
					pre[i][j] = j;
				}
				if (j >= a[i] && d[i - 1][j - a[i]]) {
					pre[i][j] = j - a[i];
				}
			}
		}

		int res = INF;
		int index = -1;

		FOR (i, 0, n) {
			if (d[C][i] && abs(i * 2 - n) < res) {
				res = abs(i * 2 - n);
				index = i;
			}
		}

		assert(index != -1);

		int cur = index;
		vector<int> group;
		FORD(i, C, 1) {
			if (pre[i][cur] < cur) {
				group.pb(i);
				cur = pre[i][cur];
			} 
		}

		string ans;
		FOR (i, 0, n - 1) ans += '0';

		for (auto i: group) {
			for (auto j: cc[i]) {
				ans[j - 1] = '1';
			}
		}

		cout << ans << endl;

		memset(dd, 0, sizeof(dd));
		memset(pre, 0, sizeof(pre));
		FOR (i, 1, n) {
			v[i].clear();
			cc[i].clear();
		}
	}
	return 0;
}