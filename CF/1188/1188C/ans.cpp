#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;
int sum(int a, int b) {
    int s = (a + b);
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 1005;
int a[maxN];
int n, k;
// a * (k - 1) > n
int dp[maxN][maxN];
int pref[maxN][maxN];
int le[maxN];
int solve(int val) {
    // all >= a
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    le[0] = 0;
    for (int i = 1; i <= n; i++) {
        le[i] = le[i - 1];
        while (a[i] - a[le[i] + 1] >= val) le[i]++;
    }
    dp[0][0] = 1;
    for (int i = 0; i + 1 <= k; i++) {
        pref[i][0] = dp[i][0];
        for (int j = 1; j <= n; j++) {
            pref[i][j] = sum(pref[i][j - 1], dp[i][j]);
        }
        for (int j = 1; j <= n; j++) {
            dp[i + 1][j] = pref[i][le[j]];
        }
    }
    int f = 0;
    for (int i = 1; i <= n; i++) f = sum(f, dp[k][i]);
    return f;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int a = 1; a * (k - 1) <= 100000 + 10; a++) {
        ans = sum(ans, solve(a));
        if (solve(a)) cout << solve(a) << " ";
    }
    cout << endl;
    cout << ans;
    return 0;
}