/**
 *	Author: Thien
 *	Tre Trau Cop Code
**/

#include <bits/stdc++.h>
#define maxn 100000
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define fi first
#define se second
#define MOD 1000000007
#define reset(d) memset(d, 0, sizeof d)
#define endl "\n"
#define Task "dance"

using namespace std;

int n, l, m, w;
int a[11][maxn], b[11][maxn];

void xuly1() {
    int res = 0;
    ll sum;
    for(int i = 1; sum = 0, i <= n - l + 1; i++) {
        for(int j = i; j <= i + l - 1; j++)
            for(int k = 1; k <= m; k++)
                sum += a[k][j] * b[k][j - i + 1];
        if( sum > w ) res++;
    }
    cout << res;
}

void xuly2() {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> n >> l >> m >> w;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= l; j++) cin >> b[i][j];
    xuly1();

    return 0;
}
