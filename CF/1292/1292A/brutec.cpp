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

int a[3][100005];
bool vs[3][100005];
void dfs(int x, int y) {
    if (vs[x][y] || a[x][y]) return;
    vs[x][y] = 1;
    dfs(3 - x, y);
    dfs(x, y + 1);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    FOR (i, 1, q) {
        int x, y;
        cin >> x >> y;
        a[x][y] ^= 1;
        memset(vs, 0, sizeof(vs));
        dfs(1, 1);
        if (vs[2][n]) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}