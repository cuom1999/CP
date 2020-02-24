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

int d[55][55][55][55];
char ch[55][55];

int dp(int x1, int y1, int x2, int y2) {
    int &res = d[x1][y1][x2][y2];

    if (res != -1) return res;
    if (x1 == x2 && y1 == y2 && ch[x1][y1] == '.') return res = 0;

    res = max(x2 - x1 + 1, y2 - y1 + 1);

    FOR (i, x1, x2 - 1) {
        res = min(res, dp(x1, y1, i, y2) + dp(i + 1, y1, x2, y2));
    }

    FOR (i, y1, y2 - 1) {
        res = min(res, dp(x1, y1, x2, i) + dp(x1, i + 1, x2, y2));
    }
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << res << endl;
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
            cin >> ch[i][j];
        }
    }

    memset(d, -1, sizeof(d));

    cout << dp(1, 1, n, n) << endl;

    return 0;
}