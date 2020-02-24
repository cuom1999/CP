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
typedef pair < II, int > III;

struct Table {
    int a[2][305], n;
    vector<II> adj[2][305];
    vector<III> edges;

    Table(int _n) {
        n = _n;
        memset(a, -1, sizeof(a));
    }

    void reset() {
        memset(a, -1, sizeof(a));
    }

    void add(int x, int y, int w) {
        adj[0][x + n].pb({y + n, w});
        adj[1][y + n].pb({x + n, w});
        edges.pb({{x + n, y + n}, w});
    }

    void dfs(int x, int type) {
        for (auto i: adj[type][x]) {
            if (a[type ^ 1][i.first] == -1) {
                a[type ^ 1][i.first] = a[type][x] ^ i.second;
                dfs(i.first, type ^ 1);
            }
        }
    }

    bool check() {
        for (auto i: edges) {
            //cout << i.first.first << " " << i.first.second << " " << i.second << endl;
            if (a[0][i.first.first] ^ a[1][i.first.second] != i.second) return 0;
        }
        return 1;
    }

    int sum() {
        int res = 0;
        FOR (i, 0, 3 * n) {
            FOR (j, 0, 1) {
                res += max(0, a[j][i]);
            }
        }

        return res;
    }
};

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    FOR (z, 1, t)  {
        cout << "Case #" << z << ": ";
        char c[105][105];

        int n;
        cin >> n;
        Table table(n);

        FOR (i, 1, n) {
            FOR (j, 1, n) {
                cin >> c[i][j];
                if (c[i][j] == '.') {
                    table.add(i - j, i + j, 1);
                }
                else {
                    table.add(i - j, i + j, 0);
                }
            }
        }
        int res = INF;

        FOR (i, 0, 1) {
            FOR (j, 0, 1) {
                table.reset();
                table.a[0][1] = i;
                table.a[0][2] = j;
                table.dfs(1, 0);
                table.dfs(2, 0);
                if (table.check()) {
                    // cout << i << " " << j << " " << table.sum() << endl;
                    // FOR (i, 0, 3 * n) {
                    //     cout << i << " " << table.a[i] << endl;
                    // }
                    res = min(res, table.sum());
                }
            }
        }
        cout << res << "\n";

    }

    return 0;
}