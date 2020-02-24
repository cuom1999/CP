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

int a[2005][2005];
int n, m;
bool check(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m);
}

int d[2005][2005];
queue<II> q;
int x[4] = {-1, 1, 0, 0};
int y[4] = {0, 0, -1, 1};
int c[2005][2005], s[2005][2005];

void bfs() {
	FOR (i, 1, n) {
		FOR (j, 1, m) {
			if (a[i][j] && a[i][j] + a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1] > 1) {
				d[i][j] = 0;
				q.push(II(i, j));
			}
			else if (i == 1 || j == 1 || i == n || j == m) {
				d[i][j] = 0;
				q.push(II(i, j));
			}
			else d[i][j] = INF;
		}
	}
	while (q.size()) {
		auto u = q.front();
		q.pop();
		FOR (i, 0, 3) {
			if (check(u.first + x[i], u.second + y[i])) {
				if (d[u.first + x[i]][u.second + y[i]] == INF) {
					d[u.first + x[i]][u.second + y[i]] = d[u.first][u.second] + 1;
					q.push(II(u.first + x[i], u.second + y[i]));
				}
			}
		}
	}
}


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	FOR (i, 1, n) {
		FOR (j, 1, m) {
			char c;
			cin >> c;
			if (c == '*') a[i][j] = 1;
		}
	}
	bfs();
	/*
	FOR (i, 1, n) {
		FOR (j, 1, m) {
			cout << d[i][j];
		}
		cout << endl;
	}
	*/


	FOR (i, 1, n) {
		FOR (j, 1, m) {
			c[i + j][i - j + m] = a[i][j];
		}
	}

	FOR (i, 1, 2000) {
		FOR (j, 1, 2000) {
			s[i][j] = c[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
		}
	}

	int res = -1;
	int X = 0, Y = 0, R = 0;
	FOR (i, 1, n) {
		FOR (j, 1, m) {
			int u = d[i][j];
			int x1 = i + j - u;
			int x2 = i + j + u;
			int y1 = i - u - j + m;
			int y2 = i + u - j + m;
			int ans = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
			if (ans > res) {
				res = ans;
				X = i;
				Y = j;
				R = u;
			}
		}
	}

	cout << res << " " << X << " " << Y << " " << R << endl;





	
	return 0;
}