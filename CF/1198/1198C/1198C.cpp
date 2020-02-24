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

struct  Edge {
	int x, y, index;
};

bool dd[300005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {
		vector<Edge> edges;

		int n, m;
		cin >> n >> m;

		FOR (i, 1, n * 3) dd[i] = 0;

		FOR (i, 1, m) {
			int x, y;
			cin >> x >> y;
			edges.pb({x, y, i});
		}

		vector<int> res;

		while (edges.size()) {
			auto e = edges.back();
			edges.pop_back();
			if (dd[e.x] || dd[e.y]) continue;
			res.pb(e.index);
			dd[e.x] = dd[e.y] = 1;
		}

		if (res.size() >= n) {
			cout << "Matching\n";
			FOR (i, 0, n - 1) cout << res[i] << " ";
			cout << endl;
		}
		else {
			cout << "IndSet\n";
			int cnt = 0;
			FOR (i, 1, 3 * n) {
				if (!dd[i] && cnt < n) {
					cout << i << " ";
					cnt++;
				}
			}
			cout << endl;
		}
	}


	return 0;
}