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

string c[100005];

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
			cin >> c[i];
			c[i] = '0' + c[i];
		}

		vector<int> row(n + 1);
		vector<int> col(m + 1);
		FOR (i, 1, n) {
			FOR (j, 1, m) {
				row[i] += (c[i][j] == '*');
				col[j] += (c[i][j] == '*');
			}
		}
		int res = INF;
		FOR (i, 1, n) {
			FOR (j, 1, m) {
				int val = row[i] + col[j] - (c[i][j] == '*');
				res = min(res, m + n - 1 - val);
			}
		}
		cout << res << "\n";
	}


	return 0;
}