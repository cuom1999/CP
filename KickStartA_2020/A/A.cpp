#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t; 
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, b;
        cin >> n >> b;
        vector<int> a(n);
        for (int i = 1; i <= n; i++) {
            cin >> a[i - 1];
        }
        sort(a.begin(), a.end());
        int sum = 0;
        int res = n;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum > b) {
                res = i;
                break;
            }
        }

        cout << "Case #" << z << ": " << res << "\n";


    }
    return 0;
}