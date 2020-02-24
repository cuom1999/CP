#include <bits/stdc++.h>

using namespace std;

bool dd[1505], vis[1505];
int listNum[1505];
int r, t;

int process(int x) {
    //cout << x<< endl;
    if (x == 1)
        return vis[1] = true;
    if (vis[x]) return false;
    int temp = x, res = 0;
    while (temp > 0) {
        res += (temp % 10) * (temp % 10);
        temp /= 10;
    }
    vis[x] = true;
    return process(res);
}

/*void solve(int i, int st, int sum) {
    if (dp[i][st][sum] != -1)
        return dp[i][st][num];
    int l = (i == 1);
    if (i < len) {
        for(int i = l; i <= 9; i++) {

        }
    } else {
        if (st != 1)
            if (st == 2) {
                for(int j = 0; j <= a[len]; j++)
                    return 1
            } else
                for(int j = 0; k <= a[len]; j++)
    }
    return
}*/

int main() {
    freopen("pearl.inp", "r", stdin);
    freopen("pearl.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    //memset(dd, -1, sizeof dd);
    dd[1] = 1;
    for(int i = 2; i <= 1500; i++) {
        //cout << "*" << i << endl;
        memset(vis, false, sizeof vis);
        process(i);
        dd[i] = vis[1];
    }
    cin >> t;
    while (t--) {
        long long l, r;
        long long cnt = 0;
        cin >> l >> r;
        for(long long i = l; i <= r; i++) {
            long long temp = i, res = 0;
            while (temp > 0) {
                res += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            //cout << res << endl;
            cnt += dd[res];
        }
        cout << (r - l + 1) - cnt << '\n';
    }
    return 0;
}
