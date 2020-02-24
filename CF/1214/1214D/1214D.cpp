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

vector<vector<char>> c, vs;
vector<vector<int>> p, s;
int n, m;
    
void dfs1(int i, int j) {
    vs[i][j] = 1;
    if (j + 1 <= m && !vs[i][j + 1] && c[i][j + 1] == '.') {
        dfs1(i, j + 1);
        p[i][j + 1] = 2;
    }
    if (i + 1 <= n && !vs[i + 1][j] && c[i + 1][j] == '.') {
        dfs1(i + 1, j);
        p[i + 1][j] = 1;
    }
}

void dfs2(int i, int j) {
    vs[i][j] = 1;
    if (i + 1 <= n && !vs[i + 1][j] && c[i + 1][j] == '.') {
        dfs2(i + 1, j);
        p[i + 1][j] = 1;
    }

    if (j + 1 <= m && !vs[i][j + 1] && c[i][j + 1] == '.') {
        dfs2(i, j + 1);
        p[i][j + 1] = 2;
    }
}



int solve() {
    dfs1(1, 1);
    
    if (!vs[n][m]) return 0;

    int x = n, y = m;
    while (max(x, y) > 1) {
        s[x][y]++;
        if (p[x][y] == 1) x--;
        else y--;
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            vs[i][j] = 0;
        }
    }

    dfs2(1, 1);

    x = n, y = m;
    while (max(x, y) > 1) {
        s[x][y]++;
        if (p[x][y] == 1) x--;
        else y--;
    }

    s[n][m] = 0;
    
    int res = 0;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            res = max(res, s[i][j]);
        }
    }


    return 3 - res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;

    c.resize(n + 1);
    vs.resize(n + 1);
    p.resize(n + 1);
    s.resize(n + 1);

    FOR (i, 1, n) {
        c[i].resize(m + 1);
        vs[i].resize(m + 1);
        p[i].resize(m + 1);
        s[i].resize(m + 1);

        FOR (j, 1, m) {
            cin >> c[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}