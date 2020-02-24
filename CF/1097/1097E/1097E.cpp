#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

int p[100005];

int lis(vector<int> &arr, vector<int> &res, vector<int>& remain, vector<vector<int>>& decSet) {
    vector<int> v;
    res.clear();
    remain.clear();
    decSet.clear();

    int n = arr.size();

    vector<int> par(n);
    decSet.resize(n);

    FOR (i, 0, n - 1) {
        p[arr[i]] = i;
    }

    FOR (j, 0, n - 1) {
        int i = arr[j];
        auto pos = lower_bound(all(v), i);
        if (pos == v.end()) {
            if (pos != v.begin()) {
                par[j] = p[*(pos - 1)];
            }
            else {
                par[j] = -1;
            }
            v.pb(i);
            decSet[v.end() - v.begin() - 1].pb(i);
        }
        else {
            *pos = i;
            if (pos != v.begin()) {
                par[j] = p[*(pos - 1)];
            }
            else {
                par[j] = -1;
            }
            decSet[pos - v.begin()].pb(i);
        }
    }

    vector<int> used(n);

    int cur = p[v.back()];

    while (cur >= 0) {
        used[cur] = 1;
        res.pb(arr[cur]);
        cur = par[cur];
    }

    reverse(all(res));
    FOR (i, 0, n - 1) if (!used[i]) remain.pb(arr[i]);
    while (decSet.size()) {
        if (decSet.back().size()) break;
        decSet.pop_back();
    }
    return res.size();
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        FOR (i, 1, n) {
            cin >> a[i - 1];
            a[i - 1]--;
        }
        vector<vector<int>> res;
        while (a.size()) {
            vector<int> resI, remainI;
            vector<vector<int>> decSet;
            int lisLen = lis(a, resI, remainI, decSet);
            if (lisLen * (lisLen + 1) / 2 >= a.size()) {
                a = remainI;
                res.pb(resI);
            }
            else {
                for (auto &v: decSet) {
                    res.pb(v);
                }
                break;
            }
        }

        cout << res.size() << '\n';
        for (auto &i: res) {
            cout << i.size() << " ";
            for (auto j: i) cout << j + 1 << " ";
            cout << "\n";
        }
    }

    return 0;
}