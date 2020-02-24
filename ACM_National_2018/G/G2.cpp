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

const int MAXN = 300005;

vector<int> query[MAXN];
vector<int> v[MAXN];
bool marked[MAXN];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n - 1) {
		int x, y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	FOR (i, 1, n) {
		sort(all(v[i]));
		vector<int> tmp;
		for (int j = 0; j < v[i].size(); j++) {
			if (!j || v[i][j] != v[i][j - 1]) {
				tmp.pb(v[i][j]);
			}
		}
		v[i] = tmp;
	}

	ll res = 0;
	FOR (i, 1, n) {
		res += v[i].size() * 1ll * (v[i].size() - 1);
	}
	
	ll cnt = 0;
	FOR (i, 1, n) {
		for (auto j: v[i]) {
			if (i < j) {
				int big = i;
				int small = j;
				if (v[i].size() < v[j].size()) swap(big, small);
				query[big].pb(small);
			}
		}
	}

	FOR (i, 1, n) {
		if (query[i].size()) {
			for (auto j: v[i]) marked[j] = 1;

			for (auto j: query[i]) {
				for (auto u: v[j]) {
					if (marked[u] && u != i) {
						// cout << i << " " << j << " " << u << endl;
						cnt++;
					}
				}
			}

			for (auto j: v[i]) marked[j] = 0;
		}
	}

	// cout << res << " " << cnt << endl;
	cout << res - 2 * cnt << endl;


	return 0;
}