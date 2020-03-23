#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        auto isGood = [&](int dist) {
            int need = 0;
            for (int i = 0; i + 1 < n; i++) {
                need += (a[i + 1] - a[i] - 1) / dist;
            }
            return need <= k;
        };
        int lower = 1, upper = 1e9;
        while (lower < upper) {
            int mid = (lower + upper) / 2;
            if (isGood(mid)) {
                upper = mid;
            }
            else {
                lower = mid + 1;
            }
        }

        cout << "Case #" << z << ": " << lower << "\n";

    } 

    return 0;
}