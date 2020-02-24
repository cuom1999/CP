#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")

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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

int n, m;
vector<vector<char>> c, res, newMap;
vector<vector<int>> s, sum;

inline int max(int x, int y) {
    if (x < y) return y;
    return x;
}

inline int min(int x, int y) {
    if (x < y) return x;
    return y;
}

bool solve(int k) {
    FOR (i, 1, n) FOR (j, 1, m) s[i][j] = sum[i][j] = 0;
    FOR (i, 1, n) {
        FOR (j, 1, m) {
            if (c[i][j] == '.') {
                int x1 = max(1, i - k);
                int y1 = max(1, j - k);
                int x2 = min(n, i + k);
                int y2 = min(m, j + k);
                s[x2 + 1][y2 + 1]++;
                s[x2 + 1][y1]--;
                s[x1][y2 + 1]--;
                s[x1][y1]++;
            }
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            res[i][j] = '.';
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + s[i][j];
        }
    }
    FOR (i, k + 1, n - k) {
        FOR (j, k + 1, m - k) {
            if (!sum[i][j]) {
                res[i][j] = 'X';
            }   
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            s[i][j] = sum[i][j] = 0;
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            if (res[i][j] == 'X') {
                int x1 = max(1, i - k);
                int y1 = max(1, j - k);
                int x2 = min(n, i + k);
                int y2 = min(m, j + k);
                s[x2 + 1][y2 + 1]++;
                s[x2 + 1][y1]--;
                s[x1][y2 + 1]--;
                s[x1][y1]++;
            }
        }
    }

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + s[i][j];
            if (sum[i][j]) {
                newMap[i][j] = 'X';
            }
            else {
                newMap[i][j] = '.';
            }
            if (newMap[i][j] != c[i][j]) return 0;
        }
    }

    return 1;
}

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    c.resize(n + 1);
    res.resize(n + 1);
    newMap.resize(n + 1);
    s.resize(n + 2);
    sum.resize(n + 2);
    FOR (i, 0, n) {
        res[i].resize(m + 1);
        c[i].resize(m + 1);
        newMap[i].resize(m + 1);
    }
    FOR (i, 0, n + 1) {
        s[i].resize(m + 2);
        sum[i].resize(m + 2);
    }
    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cin >> c[i][j];
        }
    }
    int lower = 0, upper = max(m, n);
    while (lower < upper) {
        int mid = (lower + upper + 1) / 2;
        if (solve(mid)) {
            lower = mid;
        } 
        else {
            upper = mid - 1;
        }
    }

    cout << lower << endl;
    solve(lower);
    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cout << res[i][j];
        }
        cout << "\n";
    }

    return 0;
}