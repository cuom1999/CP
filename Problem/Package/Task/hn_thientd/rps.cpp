/**
 *	Author: Thien
 *	Tre Trau Cop Code
**/

#include <bits/stdc++.h>
#define maxn 2002
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define se second
#define MOD 1000000007
#define reset(d) memset(d, 0, sizeof d)
#define endl "\n"
#define Task "rps"

using namespace std;

int n, res;
int a[maxn][maxn];
map <int, int> m;

bool check(int x, int y, int z) {
    if( x == y || x == z || y == z ) return false;
    if( !a[x][y] || !a[y][z] || !a[z][x] ) return false;
    if( a[x][y] == a[y][x] || a[x][z] == a[z][x] || a[y][z] == a[z][y] ) return false;
    if( a[x][y] == a[x][z] || a[y][x] == a[y][z] || a[z][x] == a[z][y] ) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    for(int i = 1; i <= n; i++) m[i]++;
    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= n; y++)
            for(int z = 1; z <= n; z++)
                if( check(x, y, z) ) res += m[x] + m[y] + m[z], m[x] = m[y] = m[z] = 0;
    cout << res;

    return 0;
}
