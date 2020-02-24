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

vector<int> dp[55][1005];
bool lessThan(vector<int>& a, vector<int> &b) {
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return 0;
    }
    return a.size() < b.size();
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t, n;
    while (cin >> t) {
        if (!t) break;
        FOR (i, 0, 50) FOR (j, 0, 1000) dp[i][j].clear();
        
        cin >> n;
        vector<int> a(n + 1);
        FOR (i, 1, n) {
            cin >> a[i];
        }
        dp[0][0] = {0};
        FOR (i, 1, n) {
            FOR (k, 0, t) {
                dp[i][k] = dp[i - 1][k];
            }
            if (a[i] > t) continue;
            
            FOR (k, 0, t) {
                if (k + a[i] > t) continue;
                if (dp[i - 1][k].size()) {
                    vector<int> tmp = dp[i - 1][k];
                    tmp.pb(i);
                    if (!dp[i][k + a[i]].size() || lessThan(tmp, dp[i][k + a[i]])) {
                        dp[i][k + a[i]] = tmp;
                    }
                }
            }
        }

        FORD (i, t, 0) {
            if (dp[n][i].size()) {
                for (int j = 1; j < dp[n][i].size(); j++) {
                    cout << a[dp[n][i][j]] << " ";
                }
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}