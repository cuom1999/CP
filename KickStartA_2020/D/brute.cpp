#include <bits/stdc++.h>
using namespace std;

int lcp(vector<string> &v) {
    int minLen = 1e9;
    for (auto s: v) {
        minLen = min(minLen, (int) s.size());
    }
    for (int i = 0; i < minLen; i++) {
        set<char> se;
        for (auto s: v) {
            se.insert(s[i]);
        }
        if (se.size() > 1) return i;
    }
    return minLen;
}

int main() {
    freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, k;
        cin >> n >> k;
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        sort(s.begin(), s.end());
        vector<int> dp(n + 1), ma(n + 1);
        for (int i = 1; i <= n; i++) {
            if (i >= k) {
                vector<string> v;
                for (int j = 1; j <= k; j++) {
                    v.push_back(s[i - j]);
                }
                dp[i] = ma[i - k] + lcp(v);
                ma[i] = max(ma[i - 1], dp[i]);
            }
            // cout << i << " " << dp[i] << endl;
        }
        cout << "Case #" << z << ": " << ma[n] << "\n";
    }
}