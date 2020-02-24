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
#define flog2(n) 615 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int r, c;
int res;
bool solve(bool firstMove, char a[15][15]) {
	// FOR (i, 0, r - 1) {
	// 	FOR (j, 0, c - 1) {
	// 		cout << a[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	FOR (i, 0, r - 1) {
		FOR (j, 0, c - 1) {
			if (a[i][j] == '#' || a[i][j] == '*') continue;

			// vertical
			char b[15][15];
			FOR (u, 0, r - 1) FOR (v, 0, c - 1) b[u][v] = a[u][v];
			int ok = 1;

			FOR (u, i, r - 1) {
				if (b[u][j] == '*') break;
				if (b[u][j] == '#') ok = 0; 
				b[u][j] = '*';
			}
			FORD (u, i - 1, 0) {
				if (b[u][j] == '*') break;
				if (b[u][j] == '#') ok = 0; 
				b[u][j] = '*';	
			}

			if (ok && !solve(0, b)) {
				if (firstMove) res++;
				else return 1;
			}

			// horizontal
			ok = 1;
			FOR (u, 0, r - 1) FOR (v, 0, c - 1) b[u][v] = a[u][v];
			
			FOR (u, j, c - 1) {
				if (b[i][u] == '*') break;
				if (b[i][u] == '#') ok = 0; 
				b[i][u] = '*';
			}
			FORD (u, j - 1, 0) {
				if (b[i][u] == '*') break;
				if (b[i][u] == '#') ok = 0; 
				b[i][u] = '*';	
			}

			if (ok && !solve(0, b)) {
				if (firstMove) res++;
				else return 1;
			}
		}
	}
	return 0;
}

char a[15][15];

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {	
		res = 0;
		cout << "Case #" << z << ": ";
		cin >> r >> c;
		FOR (i, 0, r - 1) {
			FOR (j, 0, c - 1) {
				cin >> a[i][j];
			}
		} 

		solve(1, a);
		cout << res << endl;
	}

	return 0;
}