#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int M = 7e4 + 10;

int n, l, m, w, res, cnt;
int a[N][M], t[N][M];

int main() {
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> l >> m >> w;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
         //   v[i][a[i][j]].push_back(j);
        }
    }
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= l; j++)
            cin >> t[i][j];
    //for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
        if (j + l - 1 <= n) {
            //cout << j << endl;
            int res = 0;
            for(int i = 1; i <= m; i++) {
                for(int k = j; k <= j + l - 1; k++) {
                    res += a[i][k] * t[i][k - j + 1];
            //        cout << a[i][k] <<" " << t[i][k - j + 1] << endl;
                    if (res > w)
                        break;
                }
                if (res > w) break;
            }
            //cout << res << endl;
            if (res > w) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
