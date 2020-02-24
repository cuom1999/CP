#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'numberOfPaths' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_CHARACTER_ARRAY maze as parameter.
 */
const int MAXN = 1505;

int m, n;
enum Direction { LEFT, RIGHT, DOWN };

int distMax[3][MAXN][MAXN]; //[nextDir][x][y]: number of valid paths from (x,y) to exit, and the next Direction is nextDir
Direction dir[3][MAXN][MAXN];

char moveDir[3] = {'L', 'R', 'D'};


void update(vector<vector<char>> &maze, Direction d, int i, int j) {
	if (maze[i][j] == '#') return;
	if (d == RIGHT && j < n - 1) {
		int u = distMax[RIGHT][i][j + 1];
		int v = distMax[DOWN][i][j + 1];

		if (u > v) {
			dir[RIGHT][i][j] = RIGHT; 
			distMax[RIGHT][i][j] = u + 1;
		}
		else {
			dir[RIGHT][i][j] = DOWN;
			distMax[RIGHT][i][j] = v + 1;
		}
		//if (i == 1 && j == 0) cout << distMax[RIGHT][i][j] << "A" << endl;
	}
	else if (d == LEFT && j >= 1) {
		int u = distMax[LEFT][i][j - 1];
		int v = distMax[DOWN][i][j - 1];
		if (u > v) {
			dir[LEFT][i][j] = LEFT; 
			distMax[LEFT][i][j] = u + 1;
		}
		else {
			dir[LEFT][i][j] = DOWN;
			distMax[LEFT][i][j] = v + 1;
		}
	}
	else if (d == DOWN) {
		int maxInd = 0;
		int maxVal = -1000000000;

		for (int k = 0; k <= 2; k++) {
			int u = distMax[k][i + 1][j];
			if (u > maxVal) {
				maxVal = u;
				maxInd = k;
			}
		}

		distMax[DOWN][i][j] = maxVal + 1;
		dir[DOWN][i][j] = (Direction) maxInd;
	}
}

string longestPath(vector<vector<char>> &maze) {
	m = maze.size();
	n = maze[0].size();

	//construction: all states are not passed
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= 2; k++) {
				distMax[k][i][j] = -1000000000;
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

	distMax[LEFT][endX][endY] = 0;
	distMax[RIGHT][endX][endY] = 0;
	distMax[DOWN][endX][endY] = 0;

	for (int i = m - 1; i >= 0; i--) {
		if (i == m - 1) {
			for (int j = endY - 1; j >= 0; j--) {
				update(maze, RIGHT, i, j);	
			}

			for (int j = endY + 1; j < n; j++) {
				update(maze, LEFT, i, j);
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				update(maze, DOWN, i, j);
			}

			for (int j = n - 1; j >= 0; j--) {
				update(maze, RIGHT, i, j);
			}

			for (int j = 0; j < n; j++) {
				update(maze, LEFT, i, j);
			}
		}
	}

	int longestPathRes = -1000000000 - 5;
	int startDir = -1;

	for (int i = 0; i < 3; i++) {
		int u = distMax[i][startX][startY];
		if (longestPathRes < u) {
			longestPathRes = u;
			startDir = i; 
		}	
	}

	if (longestPathRes < 0) return "Not_Exist";


	int curX = startX, curY = startY;
	int curDir = startDir;
	int nextDir = dir[curDir][curX][curY];
	string path;

	while (curX != endX || curY != endY) {
		path += moveDir[curDir];
		
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

	return path;
}

#define FOR(i, a, b) for (int i = a; i <= b; i++)

int main() {
	//freopen("input003.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
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

	cout << longestPath(maze) << endl;
}