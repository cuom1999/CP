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
typedef pair < ll, ll > II;
typedef pair < ll, II > III;
typedef pair < II, II > IIII;

II cost[2][1 << 9];
III d[1 << 9];
int cnt[1 << 9];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;

	FOR (i, 1, n) {
		int k;
		cin >> k;

		int bit = 0;
		FOR (j, 1, k) {
			int x;
			cin >> x;
			bit |= (1 << (x - 1));
		}
		cnt[bit]++;
	}
	FOR (i, 0, (1 << 9) - 1) {
		cost[0][i] = cost[1][i] = II(1e18, 0);
	}

	FOR (i, 1, m) {
		int k;
		ll c;
		cin >> c;
		cin >> k;

		int bit = 0;
		FOR (j, 1, k) {
			int x;
			cin >> x;
			bit |= (1 << (x - 1));
		}
		cost[1][bit] = min(cost[1][bit], II(c, i));
		if (cost[1][bit] < cost[0][bit]) swap(cost[0][bit], cost[1][bit]);
	}

	FOR (i, 0, (1 << 9) - 1) d[i] = III(1e18, II(0, 0));

	FOR (i, 0, 1) {
		FOR (j, 0, 1) {
			FOR (bit1, 0, (1 << 9) - 1) {
				FOR (bit2, 0, (1 << 9) - 1) {
					if (i == j && bit1 == bit2) continue;
					int bit = bit1 | bit2;
					d[bit] = min(d[bit], III(cost[i][bit1].first + cost[j][bit2].first, II(cost[i][bit1].second, cost[j][bit2].second)));
				}
			}
		}
	}

	IIII res = {{-1, 1e18}, {0, 0}};

	FOR (i, 0, (1 << 9) - 1) {
		int ans = 0;
		for (int j = i; j; j = (j - 1) & i) {
			ans += cnt[j];
		}
		if (d[i].first < 1e18) res = max(res, {{ans, -d[i].first}, d[i].second});
	}

	// cout << res.first.first << endl;
	// cout << res.first.second << endl;

	cout << res.second.first << " " << res.second.second << endl;
	return 0;
}