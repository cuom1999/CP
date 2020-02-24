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

typedef pair < char, char > CC;
typedef pair < ll, ll > pll;

//HKR: Robot and Maze

int m, n;
ll d[3][1005][1005]; // 0 if move left, 1 if right, 2 if down
int distMax[3][1005][1005];

char c[1005][1005];
const ll K = 1e9 + 7;

ll dp(int next, int x, int y) { // row  x, col y
	if (x < 1 || x > m || y < 1 || y > n || c[x][y] == '#') return 0;
	if (d[next][x][y] != -1) return d[next][x][y];
	ll res = 0;
	if (next == 0) {
		res = (dp(0, x, y - 1) + dp(2, x, y - 1)) % K;
	}
	else if (next == 1) {
		res = (dp(1, x, y + 1) + dp(2, x, y + 1)) % K;
	}
	else {
		res = (dp(0, x + 1, y) + dp(1, x + 1, y) + dp(2, x + 1, y)) % K;
	}
	return d[next][x][y] = res;
}

int dir[3][1005][1005];

char moveDir[3] = {'L', 'R', 'D'};

int longestPath(int next, int x, int y) { // row  x, col y
	if (x < 1 || x > m || y < 1 || y > n || c[x][y] == '#') return -INF;
	if (distMax[next][x][y] != -1) return distMax[next][x][y];
	int res = -INF;
	if (next == 0) {
		int u = longestPath(0, x, y - 1);
		int v = longestPath(2, x, y - 1);
		if (u > v) {
			dir[next][x][y] = 0;
			res = u;
		}
		else {
			dir[next][x][y] = 2;
			res = v;
		}
	}
	else if (next == 1) {
		int u = longestPath(1, x, y + 1);
		int v = longestPath(2, x, y + 1);
		if (u > v) {
			dir[next][x][y] = 1;
			res = u;
		}
		else {
			dir[next][x][y] = 2;
			res = v;
		}
	}
	else {
		int cnt = 0;
		FOR (i, 0, 2) {
			int u = longestPath(i, x + 1, y);
			if (res < u) {
				res = u;
				cnt = i;
			}
		}
		dir[next][x][y] = cnt;
	}
	return distMax[next][x][y] = res + 1;
}

int main()
{//IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    FOR (i, 1, 1000) {
    	FOR (j, 1, 1000) FOR (k, 0, 2) d[k][i][j] = distMax[k][i][j] = -1;
    }

    cin >> m >> n;

    int startX, startY, endX, endY;

    FOR (i, 1, m) {
    	FOR (j, 1, n) {
    		cin >> c[i][j];
    		if (c[i][j] == 'S') {
    			startX = i;
    			startY = j;
    		}
    		else if (c[i][j] == 'E') {
    			endX = i;
    			endY = j;
    		}
    	}
    }
    d[0][endX][endY] = 0;
    d[1][endX][endY] = 0;
	d[2][endX][endY] = 1;

	ll res = 0;
	FOR (i, 0, 2) {
		res += dp(i, startX, startY);
	}
	res %= K;

	printf("%d\n", res);
	
	//find the longest path
	FOR (i, 0, 2) distMax[i][endX][endY] = 0;

	int longestPathRes = -INF - 5;
	int startDir = -1;

	FOR (i, 0, 2) {
		int u = longestPath(i, startX, startY);
		if (longestPathRes < u) {
			longestPathRes = u;
			startDir = i; 
		}	
	}

	if (longestPathRes < 0) return 0;
	//cout << longestPathRes << endl;

	int curX = startX, curY = startY;
	int curDir = startDir;
	int nextDir = dir[curDir][curX][curY];
	vector<char> path;

	while (curX != endX || curY != endY) {
		path.pb(moveDir[curDir]);
		
		if (curDir == 0) {
			curY--;
		}
		else if (curDir == 1) {
			curY++;
		}
		else curX++;

		curDir = nextDir;
		nextDir = dir[curDir][curX][curY];
	}

	for (int i = 0; i < path.size(); i++) {
		printf("%c", path[i]);
	}

    return 0;
}