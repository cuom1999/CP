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

const int MAXN = 505;
const int K = 1e9 + 7;

// unordered_map<int, int> d[MAXN][MAXN][2];
int d[MAXN][MAXN][2][MAXN];
int n, m;
char c[MAXN][MAXN];
int sufRow[MAXN][MAXN], sufCol[MAXN][MAXN];
int cnt = 0;

int dp(int x, int y, int a, int type) {
    if (d[x][y][type][a] != -1) return d[x][y][type][a];
    // if (res != -1) return res;
    if (x == n && y == m) return 1;
    // int res = d[x][y][type][a];
    int oldA = a;
    int res;
    // cout << x << " " << y << " " << type << endl;
    cnt++;
    int b;
    if (type == 0) {
        b = sufRow[x][y];
    }
    else {
        b = sufCol[x][y];
        swap(a, b);
    }

    res = 0;
    if (n - x > a) {
        res += dp(x + 1, y, a, 0);
        res %= K;
    }
    if (m - y > b) {
        res += dp(x, y + 1, b, 1);
        res %= K;
    }

    cout << x << " " << y << " " << a << " " << b << ": " << res << endl;
    return d[x][y][type][oldA] = res;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(0));

    memset(d, -1, sizeof(d));
    
    cin >> n >> m;
    FOR (i, 1, n) {
        FOR (j, 1, m) {
            // cin >> c[i][j];
            if (rand() % 2 == 0) c[i][j] = 'R';
            else c[i][j] = '.';
        }
    }

    FOR (i, 1, n) {
        FORD(j, m, 1) {
            sufRow[i][j - 1] = sufRow[i][j] + (c[i][j] == 'R');
        }
    }

    FORD (i, n, 1) {
        FOR (j, 1, m) {
            sufCol[i - 1][j] = sufCol[i][j] + (c[i][j] == 'R');
        }
    } 
    cout << dp(1, 1, sufRow[1][1], 0) << endl;
    cout << cnt << endl;
    return 0;
}