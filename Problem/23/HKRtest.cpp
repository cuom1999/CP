#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'numberOfPaths' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_CHARACTER_ARRAY maze as parameter.
 */

int m, n;
enum Direction { LEFT, RIGHT, DOWN };

long long numPaths[3][1005][1005]; //[nextDir][x][y]: number of valid paths from (x,y) to exit, and the next Direction is nextDir

const long long MOD = 1e9 + 7;

//top down dp
long long dp(vector<vector<char>> &maze, Direction nextDir, int x, int y) { // row  x, col y
	if (x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == '#') return 0; //unsafe spots

	if (numPaths[nextDir][x][y] != -1) return numPaths[nextDir][x][y]; //already saved states
	cout << nextDir << " " << x << " " << y << endl;
	long long res = 0;
	if (nextDir == LEFT) {
		res = (dp(maze, LEFT, x, y - 1) + dp(maze, DOWN, x, y - 1)) % MOD;
	}
	else if (nextDir == RIGHT) {
		res = (dp(maze, RIGHT, x, y + 1) + dp(maze, DOWN, x, y + 1)) % MOD;
	}
	else { //DOWN
		res = (dp(maze, LEFT, x + 1, y) + dp(maze, RIGHT, x + 1, y) + dp(maze, DOWN, x + 1, y)) % MOD;
	}
	return numPaths[nextDir][x][y] = res;
}

int numberOfPaths(vector<vector<char>> &maze) {
	m = maze.size();
	n = maze[0].size();

	//construction: all states are not passed
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= 2; k++) {
				numPaths[k][i][j] = -1;
			}
		}
	}

	int startX, startY, endX, endY;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == 'S') {
				startX = i;
				startY = j;
			}
			else if (maze[i][j] == 'E') {
				endX = i;
				endY = j;
			}
		}
	}

	numPaths[LEFT][endX][endY] = 0;
	numPaths[RIGHT][endX][endY] = 0;
	numPaths[DOWN][endX][endY] = 1;

	long long res = 0;
	
	res = dp(maze, LEFT, startX, startY) + dp(maze, RIGHT, startX, startY) + dp(maze, DOWN, startX, startY); 
	
	res %= MOD;

	return res;
}

#define FOR(i, a, b) for (int i = a; i <= b; i++)

int main() {
	freopen("input.txt", "r", stdin);
	int r, c;
	cin >> r >> c;
	vector<vector<char>> maze;
	maze.resize(r);
	FOR (i, 0, r - 1) {
		maze[i].resize(c);
		FOR (j, 0, c - 1) {
			cin >> maze[i][j];
		}
	}

	cout << numberOfPaths(maze) << endl;
}