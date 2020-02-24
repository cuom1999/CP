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

const ll K = 1e9 + 7;

ll c[55][55][55][3];

ll calc(int x, int y, int z, int last) {
	if (x < 0 || y < 0 || z < 0) return 0;
	if (x == 0 && y == 0 && z == 0) return 1;
	// cout << x << " " << y << " " << z << endl;
	if (last != -1 && c[x][y][z][last] != -1) return c[x][y][z][last];
	ll res = 0;

	if (0 == last) {
		res = (calc(x, y - 1, z, 1) + calc(x, y, z - 1, 2)) % K;
	}
	else if (1 == last) {
		res = (calc(x - 1, y, z, 0) + calc(x, y, z - 1, 2)) % K;
	}
	else if (2 == last) {
		res = (calc(x - 1, y, z, 0) + calc(x, y - 1, z, 1)) % K;
	}
	else {
		res = (calc(x - 1, y, z, 0) + calc(x, y - 1, z, 1) + calc(x, y, z - 1, 2)) % K;
	}
	if (last != -1) c[x][y][z][last] = res;
	// cout << x << " " << y << " " << z << " " << last << " " << res << endl;
	return res;
}

ll preCalc[55][55][55];
ll d[3][55][2505], gt[2505];
vector<int> v[3];

void process(vector<int> &v, ll a[55][2505]) {
	int n = v.size();
	a[0][0] = 1;
	FOR (i, 0, n - 1) {
		FORD (j, n, 1) {
			FORD (k, 2500, v[i]) {
				a[j][k] = (a[j - 1][k - v[i]] + a[j][k]) % K;
			}
		}
	}
}



int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	memset(c, -1, sizeof(c));

	FOR (i, 0, 50) {
		FOR (j, 0, 50) {
			FOR (k, 0, 50) {
				preCalc[i][j][k] = calc(i, j, k, -1);
			}
		}
	}

	int n, T;
	cin >> n >> T;

	FOR (i, 1, n) {
		int t, x;
		cin >> t >> x;
		x--;
		v[x].pb(t);
	}

	FOR (i, 0, 2) process(v[i], d[i]);

	gt[0] = 1;
	FOR (i, 1, 2500) {
		gt[i] = gt[i - 1] * i % K;
	}

	vector<II> vv[2];

	FOR (i, 0, 1) {
		FOR (j, 1, n) {
			FOR (k, 0, 2500) {
				if (d[i][j][k]) vv[i].pb({j, k});
			}
		}
	}	

	ll res = 0;

	for (auto i: vv[0]) {
		for (auto j: vv[1]) {
			if (i.second + j.second > T) continue;
			res += d[0][i.first][i.second] * d[1][j.first][j.second] % K * d[2][n - i.first - j.first][T - i.second - j.second]
		}
	}

	return 0;
}