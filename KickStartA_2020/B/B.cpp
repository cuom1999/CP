#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, k, p;
        cin >> n >> k >> p;

        int dp[52][1505];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            int curSum = 0;
            for (int u = 0; u <= p; u++) {
                dp[i][u] = dp[i - 1][u];
            }

            for (int j = 1; j <= k; j++) {
                int x;
                cin >> x;
                curSum += x;
                for (int u = j; u <= p; u++) {
                    dp[i][u] = max(dp[i][u], dp[i - 1][u - j] + curSum);
                }
            }
        }
        cout << "Case #" << z << ": " << dp[n][p] << "\n";
    }


    return 0;
}