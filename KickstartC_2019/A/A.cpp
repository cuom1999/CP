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


string s;
const int MAXN = 50005;

map<int, II> goUp[MAXN], goDown[MAXN], goLeft[MAXN], goRight[MAXN];

II getLeft(int r, int c) {
	if (goLeft[r].count(c)) return goLeft[r][c];
	return II(r, c - 1);
}

II getRight(int r, int c) {
	if (goRight[r].count(c)) return goRight[r][c];
	return II(r, c + 1);
} 

II getUp(int r, int c) {
	if (goUp[r].count(c)) return goUp[r][c];
	return II(r - 1, c);
}

II getDown(int r, int c) {
	if (goDown[r].count(c)) return goDown[r][c];
	return II(r + 1, c);
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";

		int n, r, c, curR, curC;

		cin >> n >> r >> c >> curR >> curC;

		cin >> s;
		s = '0' + s;

		FOR (i, 1, n) {
			II l = getLeft(curR, curC);
			II r = getRight(curR, curC);
			II u = getUp(curR, curC);
			II d = getDown(curR, curC);

			goRight[l.first][l.second] = r;
			goLeft[r.first][r.second] = l;
			goDown[u.first][u.second] = d;
			goUp[d.first][d.second] = u; 

			if (s[i] == 'E') {
				curC = r.second;
			}
			else if (s[i] == 'W') {
				curC = l.second;
			}
			else if (s[i] == 'N') {
				curR = u.first;
			}
			else if (s[i] == 'S') {
				curR = d.first;
			}
			// cout << curR << " " << curC << endl;
		}

		cout << curR << " " << curC << endl;
		FOR (i, 1, 50000) {
			goUp[i].clear();
			goDown[i].clear();
			goLeft[i].clear();
			goRight[i].clear();
		}
	}
	return 0;
}