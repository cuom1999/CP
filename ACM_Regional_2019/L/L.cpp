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

const int MAXN = 105;

struct MaxMatching {
    // everything is 1-index
    // v[i]: adj set of right vertex i
    // match[i]: adj of left vertex i

    int match[MAXN], vs[MAXN];
    vector<int> v[MAXN];
    void addEdge(int a, int b) {
        v[b].pb(a);
    }
    // find an augmenting path
    bool findPath(int u, int t) { // u: a right vertex, t: time
        if (vs[u] != t){
            vs[u] = t;
        }
        else return 0;

        for (auto i: v[u]){
            if (!match[i] || findPath(match[i], t)) {
                match[i] = u;
                return 1;
            }
        }
        return 0;
    }

    int biMatching (int m, int n) {
        FOR (i, 1, max(m,n)) match[i] = vs[i] = 0;

        int cnt=0;

        FOR (i, 1, m) {
            cnt += findPath(i,i);
        }

        return cnt;
    }
};

bool used[105];
int a[105][105];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    vector<int> remained;
    FOR (i, 1, n) {
        FOR (j, 1, n) {
            cin >> a[i][j];
            used[a[i][j]] = 1;
        }
    }

    FOR (i, 1, n) {
        if (!used[i]) {
            remained.pb(i);
        }
    }

    while (remained.size()) {
        int k = remained.back();
        remained.pop_back();
        MaxMatching mm;
        FOR (i, 1, n) {
            FOR (j, 1, n) {
                if (a[i][j] == 0) {
                    // cout << i << " " << j << endl;
                    mm.addEdge(i, j);
                }
            }
        }

        if (mm.biMatching(n, n) != n) {
            cout << "NO";
            return 0;
        }

        FOR (i, 1, n) {
            a[i][mm.match[i]] = k;
        }
        // FOR (i, 1, n) {
        //     FOR (j, 1, n) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
    cout << "YES\n";
    FOR (i, 1, n) {
        FOR (j, 1, n) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}