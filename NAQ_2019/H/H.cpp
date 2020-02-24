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

bool c[505][505];
int d[505][505];

int dp(int x, int y) {
    if (x >= y) return 0;
    if (d[x][y] != -1) return d[x][y];

    int &res = d[x][y];
    res = dp(x + 1, y);
    FOR (i, x + 1, y) {
        if (c[x][i]) {
            res = max(res, dp(x + 1, i - 1) + dp(i + 1, y) + 1);
        }
    }
    return res;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    FOR (i, 1, n) {
        FOR (j, 1, n) {
            cin >> c[i][j];
        }
    }
    memset(d, -1, sizeof(d));
    cout << dp(1, n) << endl;

    return 0;
}