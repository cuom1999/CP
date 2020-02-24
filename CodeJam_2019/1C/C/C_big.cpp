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

int r, c;
int sumVertical[16][16], sumHorizontal[16][16];
char a[16][16];

bool checkVertical(int y1, int y2, int x) {
	return sumVertical[y2][x] == sumVertical[y1 - 1][x];
}

bool checkHorizontal(int x1, int x2, int y) {
	return sumHorizontal[y][x1 - 1] == sumHorizontal[y][x2];
}

int d[16][16][16][16];
int ans = 0;

int solve(int x1, int y1, int x2, int y2, bool firstMove) {
	if (x1 > x2 || y1 > y2) return 0;
	if (d[x1][y1][x2][y2] != -1) return d[x1][y1][x2][y2];
	
	// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

	set<int> S;

	FOR (i, y1, y2) {
		if (checkHorizontal(x1, x2, i)) {
			// cout << "H" << endl;
			int u = solve(x1, y1, x2, i - 1, 0);
			int v = solve(x1, i + 1, x2, y2, 0);
			S.insert(u ^ v);
			if ((u ^ v) == 0 && firstMove) {
				ans += c;
			}
		}
	}

	FOR (i, x1, x2) {
		if (checkVertical(y1, y2, i)) {
			// cout << "V" << endl;
			int u = solve(x1, y1, i - 1, y2, 0);
			int v = solve(i + 1, y1, x2, y2, 0);
			S.insert(u ^ v);
			if ((u ^ v) == 0 && firstMove) {
				ans += r;
			}
		}
	}
	int res = 100;
	FOR (i, 0, 100){
		if (S.find(i) == S.end()) {
			res = i;
			break;
		}
	}
	// cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << res << endl;

	return d[x1][y1][x2][y2] = res;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		ans = 0;
		cin >> r >> c;
		memset(d, -1, sizeof(d));

		FOR (i, 1, r) {
			FOR (j, 1, c) {
				cin >> a[i][j];
			}
		}

		FOR (i, 1, r) {
			FOR (j, 1, c) {
				sumVertical[i][j] = sumVertical[i - 1][j] + (a[i][j] == '#');
				sumHorizontal[i][j] = sumHorizontal[i][j - 1] + (a[i][j] == '#');
			}
		}
		solve(1, 1, c, r, 1);
		cout << ans << endl;
	}

	return 0;
}