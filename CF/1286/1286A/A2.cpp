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

int a[105], used[105];
int dp[105][105][105][2];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> cnt(2);
    FOR (i, 1, n) {
        cin >> a[i];
        used[a[i]] = 1;
    }
    FOR (i, 1, n) {
        if (!used[i]) {
            cnt[i % 2]++;
        }
    }

    FOR (i, 0, n) {
        FOR (j, 0, n) {
            FOR (k, 0, n) FOR (u, 0, 1) dp[i][j][k][u] = n * 2 + 1;
        }
    }
    dp[0][0][0][0] = dp[0][0][0][1] = 0;
    FOR (i, 1, n) {
        FOR (j, 0, cnt[1]) {
            FOR (k, 0, cnt[0]) {
                if (a[i] == 0) {
                    if (k >= 1) {
                        dp[i][j][k][0] = dp[i - 1][j][k - 1][0];
                        dp[i][j][k][0] = min(dp[i][j][k][0], dp[i - 1][j][k - 1][1] + 1);
                    }

                    if (j >= 1) {
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j - 1][k][0] + 1);
                        dp[i][j][k][1] = min(dp[i][j][k][1], dp[i - 1][j - 1][k][1]);
                    }
                }
                else {
                    FOR (u, 0, 1) {
                        int val = dp[i - 1][j][k][u];
                        if ((a[i] - u) % 2) val++;
                        dp[i][j][k][a[i] % 2] = min(dp[i][j][k][a[i] % 2], val);
                    }
                }
                // cout << i << " " << j << " " << k << " " << dp[i][j][k][0] << " " << dp[i][j][k][1] << endl;
            }
        }
    }
    cout << min(dp[n][cnt[1]][cnt[0]][1], dp[n][cnt[1]][cnt[0]][0]) << endl;
    return 0;
}