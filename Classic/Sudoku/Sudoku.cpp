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


bool isValid(int a[10][10], int x, int y, int val) {
	FOR (i, 1, 9) {
		if (a[i][y] == val && i != x) return 0;
	}
	FOR (i, 1, 9) {
		if (a[x][i] == val && i != y) return 0;
	}
	int u = (x - (x - 1) % 3);
	int v = (y - (y - 1) % 3);
	FOR (i, u, u + 2) {
		FOR (j, v, v + 2) {
			if (x == i && y == j) continue;
			if (val == a[i][j]) return 0;
		}
	}
	return 1;
}
int ans;
bool solve(int a[10][10]) {
	bool q = 0;
	int X, Y;
	
	// FOR (i, 1, 9) {
	// 	FOR (j, 1, 9) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	

	FOR (i, 1, 9) {
		FOR (j, 1, 9) {
			if (!a[i][j]) {
				q = 1;
				X = i;
				Y = j;
				break; 
			}
		} 
		if (q) break;
	}

	if (!q) {
		FOR (i, 1, 9) {
			FOR (j, 1, 9) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		ans++;
		return 1;
	}
	bool res = 0;
	FOR (val, 1, 9) {
		if (isValid(a, X, Y, val)) {
			a[X][Y] = val;
			//if (solve(a)) return 1;
			res |= solve(a);
			a[X][Y] = 0; 
		}
	}
	return res;
}

int a[10][10];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (i, 1, 9) {
    	FOR (j, 1, 9) {
    		cin >> a[i][j];
    	}
    }
    return 0;
}