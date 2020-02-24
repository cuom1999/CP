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

int x[1005], y[1005];

void printRes(vector<int> &v) {
    cout << v.size() << "\n";
    for (auto i: v) cout << i << " ";
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> ans;
    FOR (i, 1, n) {
        cin >> x[i] >> y[i];
    }

    while (1) {
        vector<int> v[2][2];
        FOR (i, 1, n) {
            int a = abs(x[i]) % 2;
            int b = abs(y[i]) % 2;
            v[a][b].pb(i);
        }

        int m = v[0][0].size() + v[1][1].size();
        if (0 < m && m < n) {
            for (auto i: v[1][1]) {
                v[0][0].pb(i);
            }
            printRes(v[0][0]);
            return 0;
        }
        bool isGood = 0;
        if (m == n) {
            if (v[0][0].size() > 0 && v[0][0].size() < n) {
                printRes(v[0][0]);
                return 0;
            }
        }
        else if (m == 0) {
            if (v[0][1].size() > 0 && v[0][1].size() < n) {
                printRes(v[0][1]);
                return 0;
            }
        }
        FOR (i, 0, 1) {
            FOR (j, 0, 1) {
                for (auto k: v[i][j]) {
                    x[k] = (x[k] - i) / 2;
                    y[k] = (y[k] - j) / 2;
                }
            }
        }
    }

    
    return 0;
}