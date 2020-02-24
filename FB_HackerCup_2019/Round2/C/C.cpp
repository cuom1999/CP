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

const int MAXN = 305;

int x[MAXN][MAXN], y[MAXN][MAXN];
int a[MAXN][MAXN], b[MAXN][MAXN];

void process(string &s, int index) {
	s += '#';
	int cnt = 0;

	vector<int> cost;

	for (int i = 0; i < s.length(); i++) {
		if (!i || s[i] != s[i - 1]) {
			cost.pb(cnt);
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	int n = cost.size();
	n--;

	FOR (i, 1, n) {
		FOR (j, 0, 300) x[i][j] = y[i][j] = INF;
	}	

	FOR (j, 0, 300) a[index][j] = b[index][j] = INF;

	x[1][0] = y[1][0] = cost[1];

	if (s[0] == 'A') {
		FOR (i, 1, n) x[i][i] = 0;
	} 
	else {
		FOR (i, 1, n) y[i][i] = 0;
	}

	int st = 0;
	if (s[0] == 'B') st = 1;

	FOR (i, 2, n) {
		FOR (j, 0, n) {
			x[i][j] = min(x[i][j], x[i - 1][j] + cost[i]);
			if (j && (i - st) % 2 == 0 && (j) % 2 == 0) x[i][j] = min(x[i][j], x[i - 1][j - 1]);
			if (j && (i - st) % 2 && (j) % 2) x[i][j] = min(x[i][j], x[i - 1][j]);
			if (j == 1 && (i - st) % 2) x[i][j] = min(x[i][j], x[i - 1][0]);

			y[i][j] = min(y[i][j], y[i - 1][j] + cost[i]);
			if (j && (i - st) % 2 && (j) % 2 == 0) y[i][j] = min(y[i][j], y[i - 1][j - 1]);
			if (j && (i - st) % 2 == 0 && (j) % 2) y[i][j] = min(y[i][j], y[i - 1][j]);
			if (j == 1 && (i - st) % 2 == 0) y[i][j] = min(y[i][j], y[i - 1][0]);

			// cout << i << " " << j << " " << y[i][j] << endl;
		}
	}

	FOR (j, 0, n) {
		a[index][j] = min(a[index][j], x[n][j]);
		b[index][j] = min(b[index][j], y[n][j]);
	}

	FOR (i, 1, 300) {
		a[index][i] = min(a[index][i - 1], a[index][i]);
		b[index][i] = min(b[index][i - 1], b[index][i]);
	}

	// FOR (i, 0, 10) {
	// 	cout << a[index][i] << " ";
	// }
	// cout << endl;

	// FOR (i, 0, 10) {
	// 	cout << b[index][i] << " ";
	// }
	// cout << endl << endl;
}

string s[MAXN];
int res[MAXN * MAXN], n, m;

int solve(int x) {
	int res1 = 0;
	int res2 = 0;
	FOR (i, 1, m) {
		// cout << a[i][x] << " " << b[i][x] << endl;
		if (x) {
			res1 += min(a[i][x], b[i][x - 1]);
			res2 += min(a[i][x - 1], b[i][x]);
		}
		else {
			res1 += a[i][x];
			res2 += b[i][x];
		}
	}
	return min(res1, res2);
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int k;
		cin >> n >> m >> k;

		FOR (i, 1, 300) s[i].clear();
		FOR (i, 1, n) {
			FOR (j, 1, m) {
				char x;
				cin >> x;
				s[j] += x;
			}
		}
		FOR (i, 1, m) {
			process(s[i], i);
		}

		// FOR (i, 0, n + 1) cout << solve(i) << " ";
		FOR (i, 0, n * m + 1) res[i] = INF;

		FOR (i, 0, n + 1) {
			int u = solve(i);
			res[u] = min(res[u], i);
		}

		FOR (i, 1, m * n - 1) {
			res[i] = min(res[i], res[i - 1]);
		}

		FOR (i, 1, k) {
			int x;
			cin >> x;
			cout << res[x] << " ";
		}
		cout << endl;
	}

	return 0;
}