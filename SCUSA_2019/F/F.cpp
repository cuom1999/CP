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

char c[1055][1055];
bool vs[1055][1055];
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, -1, 1, -1};

int dx1[4] = {1, 0, 0, 1};
int dy1[4] = {1, 0, 1, 0};
char wall[4] = {'/', '/', '\\', '\\'};

int n, m;
bool isValid(int x, int y) {
    return (0 <= x && x <= n + 10 && 0 <= y && y <= m + 10);
}

void dfs(int x, int y) {
    if (x == -1) {
        int n1 = n / 2 * 2 + 8;
        int m1 = m / 2 * 2 + 8;
        dfs(0, 0);
        dfs(n1, 0);
        dfs(0, m1);
        dfs(n1, m1);
        return;
    }
    if (x == -2) {
        dfs(0, 1);
        dfs(1, 0);
        int n1 = n / 2 * 2 + 9;
        int m1 = m / 2 * 2 + 9;
        dfs(n1, 0);
        dfs(0, m1);
        dfs(n1, m1 + 1);
        dfs(n1 + 1, m1);
        return;
    }
    if (vs[x][y]) {
        return;
    }

    vs[x][y] = 1;
    FOR (i, 0, 3) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY) && c[x + dx1[i]][y + dy1[i]] != wall[i]) {
            dfs(newX, newY);
        }
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    FOR (i, 0, n + 10) {
        FOR (j, 0, m + 10) c[i][j] = '.';
    }
    int start = -1;
    FOR (i, 4, n + 3) {
        FOR (j, 4, m + 3) {
            cin >> c[i][j];
            if (c[i][j] != '.') {
                if (c[i][j] == '/' && (i + j) % 2) {
                    start = -2;
                } 
                if (c[i][j] == '\\' && (i + j) % 2 == 0) {
                    start = -2;
                }
            }
        }
    }

    // point (x, y) is (x + .5, y + .5);
    int res = 0;
    dfs(start, start);
    // FOR (i, 0, n + 8) {
    //     FOR (j, 0, m + 8) {
    //         if ((i + j + start) % 2) {
    //             cout << vs[i][j];
    //         }
    //         else cout << "#";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    FOR (i, 0, n + 7) {
        FOR (j, 0, m + 7) {
            if (!vs[i][j] && (i + j + start) % 2) {
                dfs(i, j);
                res++;

                // FOR (ii, 0, n + 8) {
                //     FOR (jj, 0, m + 8) {
                //         if ((ii + jj + start) % 2) {
                //             cout << vs[ii][jj];
                //         }
                //         else cout << "#";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
            }
        }
    }

    cout << res << endl;
    return 0;
}