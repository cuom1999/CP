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

int n, m;
vector<int> row[7], col[7];

vector<int> calc(vector<int>& v) {
    int cnt = 0;
    vector<int> res;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0 && cnt) {
            res.pb(cnt);
            cnt = 0;
        }
        else if (v[i] == 1) {
            cnt++;
        }
    }
    if (cnt) res.pb(cnt);
    return res;
}

vector<vector<int>> sub[7];

inline bool check(vector<vector<int>>& a) {
    FOR (j, 1, m) {
        vector<int> c;
        FOR (i, 1, n) {
            c.pb(a[i - 1][j - 1]);
        }
        if (calc(c) != col[j]) return 0;
    }

    return 1;
}

inline bool check(vector<int>& a) {
    vector<vector<int>> v;
    FOR (i, 0, n - 1) {
        v.pb(sub[i + 1][a[i]]);
    }
    return check(v);
}

ll res = 0;
void backtrack(int r, vector<int>& a) {
    if (r == n + 1) {
        res += check(a);
        return;
    }
    for (int i = 0; i < sub[r].size(); i++) {
        a.pb(i);
        backtrack(r + 1, a);
        a.pop_back();
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    FOR (i, 1, n) {
        int k;
        cin >> k;
        FOR (z, 1, k) {
            int x;
            cin >> x;
            row[i].pb(x);
        }
    }
    FOR (i, 1, m) {
        int k;
        cin >> k;
        FOR (z, 1, k) {
            int x;
            cin >> x;
            col[i].pb(x);
        }
    }

    FOR (i, 1, n) {
        FOR (bit, 0, (1 << m) - 1) {
            vector<int> tmp;
            FOR (j, 0, m - 1) {
                if (bit & (1 << j)) {
                    tmp.pb(1);
                }
                else tmp.pb(0);
            }
            if (calc(tmp) == row[i]) {
                sub[i].pb(tmp);
                // for (auto k: tmp) cout << k << " ";
                // cout << endl;
            }
        }
    }
    vector<int> empty;
    backtrack(1, empty);
    cout << res << endl;

    return 0;
}