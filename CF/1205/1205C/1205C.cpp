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

int a[55][55];

struct Edge {
	int x, y;
};
vector<Edge> v[55][55];

int n;
	
bool check(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= n);
}

bool isPalin(vector<int> v) {
	return (v[0] == v[3] && v[1] == v[2]);
}

int x[55][55];

int ask2(int x1, int y1, int x2, int y2) {
	if (x1 + y1 > x2 + y2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	int k = x2 + y2 - x1 - y1;
	if (k == 2) {
		return x[x1][y1] == x[x2][y2];
	}
	else {
		vector<int> v(4);
		if (x2 == x1 + 1) {
			return isPalin({x[x1][y1], x[x1 + 1][y1], x[x1 + 1][y1 + 1], x[x1 + 1][y1 + 2]})
			|| isPalin({x[x1][y1], x[x1][y1 + 1], x[x1 + 1][y1 + 1], x[x1 + 1][y1 + 2]})
			|| isPalin({x[x1][y1], x[x1][y1 + 1], x[x1][y1 + 2], x[x1 + 1][y1 + 2]});
		}
		else {
			return isPalin({x[x1][y1], x[x1 + 1][y1], x[x1 + 1][y1 + 1], x[x1 + 2][y1 + 1]})
			|| isPalin({x[x1][y1], x[x1 + 1][y1], x[x1 + 2][y1], x[x1 + 2][y1 + 1]})
			|| isPalin({x[x1][y1], x[x1][y1 + 1], x[x1 + 1][y1 + 1], x[x1 + 2][y1 + 1]});	
		}
	}
}

int ask(int x1, int y1, int x2, int y2) {
	if (x1 + y1 > x2 + y2) {
		swap(x1, x2);
		swap(y1, y2);
	}
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	int res;
	cin >> res;
	return res;	
}

void dfs(int x, int y) {
	for (auto i: v[x][y]) {
		int u = ask(x, y, i.x, i.y);
		a[i.x][i.y] = a[x][y];
		if (!u) a[i.x][i.y] ^= 1;
		dfs(i.x, i.y);
	}
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(0));

	cin >> n;

	a[1][1] = 1;
	a[n][n] = 0;

	FOR (i, 1, n) {
		FOR (j, 1, n) {
			if (minmax(i, j) != minmax(1, 1) && minmax(i, j) != minmax(n, n) && II(i, j) != II(1, 2)) {
				if (check(i - 1, j - 1)) {
					v[i - 1][j - 1].pb({i, j});
				}
				else if (check(i - 2, j)) {
					v[i - 2][j].pb({i, j});
				}
				else {
					v[i][j - 2].pb({i, j});
				}
			}
		}
	}

	v[2][3].pb({2, 1});

	dfs(1, 1);
	dfs(1, 2);

	bool q = 0;
	
	int u1 = ask(1, 1, 2, 3);
	int u2 = ask(n - 1, n - 2, n, n);
	int kk = rand() % (n - 2) + 1;
	int u3 = ask(kk, kk, kk + 1, kk + 2);

	FOR (k, 0, 1) {
		FOR (i, 1, n) {
			FOR (j, 1, n) {
				if ((i + j) % 2 == 0) x[i][j] = a[i][j];
				else {
					x[i][j] = a[i][j] ^ k;
				}
			}
		}
		if (u1 == ask2(1, 1, 2, 3) && u2 == ask2(n - 1, n - 2, n, n) && u3 == ask2(kk, kk, kk + 1, kk + 2)) {
			q = k;
			// cout << "q " << q << endl;
			break; 
		}
	}



	cout << "!" << endl;

	FOR (i, 1, n) {
		FOR (j, 1, n) {
			int cur = 0;
			if ((i + j) % 2 == 0) cur = a[i][j];
			else cur = a[i][j] ^ q;
			cout << cur;
		}
		cout << endl;
	}

	return 0;
}