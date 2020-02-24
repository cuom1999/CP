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

bool cmp(vector<int>& a, vector<int>& b) {
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return 0;
    }
    return (a.size() <= b.size());
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        cout << "Case #" << z << ": ";
        int n, s;
        cin >> n >> s;

        vector<int> v[50005];
        vector<vector<int>> allVec;

        FOR (i, 1, n) {
            int a;
            cin >> a;

            int x;
            FOR (j, 1, a) {
                cin >> x;
                v[i].pb(x);
            }
            sort(all(v[i]));
            allVec.pb(v[i]);
        }
        sort(all(allVec));

        ll res = n * 1ll * n;

        FOR (i, 1, n) {
            int m = v[i].size();

            FOR (bit, 1, (1 << m) - 1) {
                vector<int> tmp;
                FOR (j, 0, m - 1) {
                    if (bit & (1 << j)) {
                        tmp.pb(v[i][j]);
                    }
                }
                ll val = upper_bound(all(allVec), tmp) - lower_bound(all(allVec), tmp);
                res -= val;
            }
        }

        cout << res << "\n";
    }

    return 0;
}