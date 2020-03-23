#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

set<int> s[100005];
bool isComp[100005];
vector<int> divisors[100005];
int a[100005], trace[100005];


void remove(int i) {
    for (auto j: divisors[a[i]]) {
        s[j].erase(i);
    }
}

void add(int i) {
    for (auto j: divisors[a[i]]) {
        s[j].insert(i);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);

    FOR (i, 2, 100000) {
        if (isComp[i]) continue;
        FOR (j, 1, 100000 / i) {
            isComp[i * j] = 1;
            trace[i * j] = i;
        }
    }

    FOR (i, 2, 100000) {
        int m = i;
        while (m > 1) {
            int p = trace[m];
            divisors[i].push_back(p);
            while (m % p == 0) m /= p;
        }
    }
    int n, q;
    cin >> n >> q;

    FOR (i, 1, n) {
        cin >> a[i];
        add(i);
    }

    FOR (z, 1, q) {
        int ind, x, k;
        cin >> ind >> x >> k;
        remove(ind);
        a[ind] = x;
        add(ind);
        int res = 1e9;
        for (auto i: divisors[a[k]]) {
            auto pos = s[i].find(k);
            if (pos != s[i].begin()) {
                auto cur = pos;
                cur--;
                res = min(res, k - *cur);
            }
            if (pos != (--s[i].end())) {
                auto cur = pos;
                cur++;
                res = min(res, *cur - k);
            }
        }
        if (res == 1e9) {
            cout << -1 << "\n";
        }
        else {
            cout << res << "\n";
        }
    }


    return 0;
}