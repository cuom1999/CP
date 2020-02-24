#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

int n, m;
char c[255][255];
int a[255][255];

queue<II> q;

int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

int d[255][255];

bool check(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

vector<int> valX, valY;
vector<II> center;

int s[505][505], sum[505][505];

bool solve(int x) {
	center.clear();

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			if (d[i][j] > x) {
				center.pb(II(i, j));
			}
		}
	}


	if (center.size() == 0) return 1;

	FOR (i, 0, 502) {
		FOR (j, 0, 502) {
			s[i][j] = 0;
		}
	}

	for (auto c: center) {
		int x1 = c.first + c.second - x;
		int y1 = c.first - c.second - x + 250;
		int x2 = c.first + c.second + x;
		int y2 = c.first - c.second + x + 250;

		s[max(x1, 0)][max(y1, 0)]++;
		s[min(500, x2) + 1][min(500, y2) + 1]++;
		s[max(x1, 0)][min(500, y2) + 1]--;
		s[min(500, x2) + 1][max(y1, 0)]--;
	}

	FOR (i, 0, 500) {
		FOR (j, 0, 500) {
			if (i >= 1 && j >= 1) {
				sum[i][j] = sum[i][j - 1] + s[i][j] + sum[i - 1][j] - sum[i - 1][j - 1];
			}
			else if (i == 0 && j == 0) {
				sum[i][j] = s[i][j];
			}
			else if (i == 0) {
				sum[i][j] = sum[i][j - 1] + s[i][j];
			}
			else {
				sum[i][j] = sum[i - 1][j] + s[i][j];
			}
		}
	}

	// FOR (i, 1, n) {
	// 	FOR (j, 1, m) {
	// 		cout << sum[i + j][i - j + 250] << " "; 
	// 	}
	// 	cout << endl;
	// }

	FOR (i, 1, n) {
		FOR (j, 1, m) {
			if (sum[i + j][i - j + 250] == center.size())  {
				return 1;
			}
		}
	} 

	return 0;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	int t;
	cin >> t;

	FOR (z, 1, t) {
		cin >> n >> m;
		while (q.size()) q.pop();


		FOR (i, 1, n) {
			FOR (j, 1, m) {
				cin >> c[i][j];
				d[i][j] = -1;

				if (c[i][j] == '1') {
					q.push(II(i, j));
					d[i][j] = 0;
				}
			}
		}


		while (q.size()) {
			II u = q.front();
			q.pop();

			FOR (i, 0, 3) {
				II v = II(u.first + x[i], u.second + y[i]);
				if (check(v.first, v.second) && d[v.first][v.second] == -1) {
					q.push(II(v.first, v.second));
					d[v.first][v.second] = d[u.first][u.second] + 1;
				}
			}
		}

		// cout << solve(1) << endl;

		// return 0;

		int L = 0, R = m + n - 2;

		while (L < R) {
			int mid = (L + R) / 2;

			if (solve(mid)) R = mid;
			else L = mid + 1;
		}

		cout << "Case #" << z << ": " << L << endl;
	}



	
	return 0;
}