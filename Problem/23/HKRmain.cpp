// Complete the 'findNumberOfPathAndPrintAPath' function below.
int m, n;
long long numPaths[3][1005][1005]; // 0 if move left, 1 if right, 2 if down

int distMax[3][1005][1005];

char maze[1005][1005];
const long long K = 1e9 + 7;
const int INF = 1e9;

long long dp(int next, int x, int y) { // row  x, col y
    if (x < 1 || x > m || y < 1 || y > n || maze[x][y] == '#') return 0;
    if (numPaths[next][x][y] != -1) return numPaths[next][x][y];
    long long res = 0;
    if (next == 0) {
        res = (dp(0, x, y - 1) + dp(2, x, y - 1)) % K;
    }
    else if (next == 1) {
        res = (dp(1, x, y + 1) + dp(2, x, y + 1)) % K;
    }
    else {
        res = (dp(0, x + 1, y) + dp(1, x + 1, y) + dp(2, x + 1, y)) % K;
    }
    return numPaths[next][x][y] = res;
}

int dir[3][1005][1005];

char moveDir[3] = {'L', 'R', 'D'};

int longestPath(int next, int x, int y) { // row  x, col y
    if (x < 1 || x > m || y < 1 || y > n || maze[x][y] == '#') return -INF;
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
        for (int i = 0; i <= 2; i++) {
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



void findNumberOfPathAndPrintAPath() {

    //preHandle
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            for (int k = 0; k <= 2; k++) {
                    numPaths[k][i][j] = distMax[k][i][j] = -1;
            }
        }
    }

    cin >> m >> n;

    int startX, startY, endX, endY;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maze[i][j];
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
    numPaths[0][endX][endY] = 0;
    numPaths[1][endX][endY] = 0;
    numPaths[2][endX][endY] = 1;

    long long res = 0;
    for (int i = 0; i <= 2; i++) {
        res += dp(i, startX, startY);
    }
    res %= K;

    printf("%d\n", res);
    
    //find the longest path
    for (int i = 0; i <= 2; i++) distMax[i][endX][endY] = 0;

    int longestPathRes = -INF - 5;
    int startDir = -1;

    for (int i = 0; i <= 2; i++) {
        int u = longestPath(i, startX, startY);
        if (longestPathRes < u) {
            longestPathRes = u;
            startDir = i; 
        }    
    }

    if (longestPathRes < 0) return; // no path
    
    int curX = startX, curY = startY;
    int curDir = startDir;
    int nextDir = dir[curDir][curX][curY];
    vector<char> path;

    while (curX != endX || curY != endY) {
        path.push_back(moveDir[curDir]);
        
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

}

