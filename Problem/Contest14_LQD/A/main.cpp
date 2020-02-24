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

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int a[15][15], row[15], col[15], dia1, dia2;

int main()
{//IN; //OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		FOR (j, 1, n) {
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
			if (i == j) dia1 += a[i][j];
			if (i + j == n + 1) dia2 += a[i][j];
		}
	}

	FOR (i, 1, n) {
		if (row[i] != dia1) {
			cout << "NO";
			return 0;
		}
		if (col[i] != dia1) {
			cout << "NO";
			return 0;
		}
	}
	if (dia1 != dia2) {
		cout << "NO";
		return 0;
	} 
	cout << "YES" << endl;
	return 0;
}