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

ll g[3005 * 3005];
int h[3005][3005], k[3005][3005];

int SPT[3005][25];

void preRMQ(int a[3005], int n) {
	for (int i = 0; (1 << i) <= n ; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			if (i == 0) {
				SPT[j][i] = a[j];
			}
			else{
				SPT[j][i]=min(SPT[j][i-1],SPT[j+(1<<(i-1))][i-1]);
			}
		}
	}
}

inline int getRMQ(int u, int v){
	int k = flog2(v-u+1);
	return min(SPT[u][k], SPT[v-(1<<k)+1][k]);
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m, a, b;

	cin >> n >> m >> a >> b;

	ll x, y, z;
	cin >> g[0] >> x >> y >> z;
	FOR (i, 1, m * n - 1) {
		g[i] = (g[i - 1] * x + y) % z;
	}

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			h[i][j] = g[(i - 1) * m + j - 1];
			// cout << h[i][j] << " ";
		}
		// cout << endl;
	}

	FOR (i, 1, n) {
		preRMQ(h[i], m);
		FOR (j, 1, m - b + 1) {
			k[i][j] = getRMQ(j, j + b - 1);
		}
	}

	FOR (j, 1, m) {
		int tmp[3005];
		FOR (i, 1, n) tmp[i] = k[i][j];
		preRMQ(tmp, n);

		FOR (i, 1, n - a + 1) {
			h[i][j] = getRMQ(i, i + a - 1);
		}
	}

	ll res = 0;
	FOR (i, 1, n - a + 1) {
		FOR (j, 1, m - b + 1) {
			// cout << h[i][j] << " ";
			res += h[i][j];
		}
		// cout << endl;
	}
	cout << res << endl;



	return 0;
}