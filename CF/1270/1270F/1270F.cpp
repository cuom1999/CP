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

int a[1000005], p[1000005], vs[1000005];

int root = -1;

void dfs(int u) {
    if (root != -1) return;
    if (vs[u]) {
        root = u;
        return;
    }
    vs[u] = 1;
    p[a[u]] = u;
    dfs(a[u]);
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
        FOR (i, 1, n) {
            vs[i] = 0;
            p[i] = 0;
            cin >> a[i];
            a[i] = i - a[i];
        }

        bool isGood = 0;
        root = -1;
        FOR (i, 1, n) {
            if (a[i] == i) {
                cout << 1 << "\n";
                cout << i << "\n";
                isGood = 1;
                break;
            }
        }

        if (isGood) continue;
        FOR (i, 1, n) {
            if (!vs[i]) dfs(i);
        }
        vector<int> res;
        int cur = root;
        cur = p[root];
        res.pb(root);

        while (cur != root) {
            res.pb(cur);
            cur = p[cur];
        }
        cout << res.size() << "\n";
        for (auto i: res) cout << i << " ";
        cout << "\n";
    }

    return 0;
}