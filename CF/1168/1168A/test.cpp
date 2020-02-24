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

int n, m;

ll cost(int u, int k) {
	if (k >= u) return k - u;
	return m - u + k;
}

ll d[105][105];
int a[105];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;

	FOR (i, 1, n) {
		cin >> a[i];
	}


	FOR (i, 1, n) {
		FOR (k, 0, m - 1) {
			d[i][k] = 1e18;
			FOR (u, 0, k) {
				d[i][k] = min(d[i][k], max(d[i - 1][u], cost(a[i], k)));
			}
		}
	}

	ll res = 1e18;

	FOR (k, 0, m - 1) {
		res = min(res, d[n][k]);
	}

	cout << res << endl;


	return 0;
}