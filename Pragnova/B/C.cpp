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



int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, s1, s2;
    cin >> n >> s1 >> s2;
    if (s1 > s2) swap(s1, s2);

    vector<int> t(n + 1);

    FOR (i, 1, n) {
        cin >> t[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(s1 + 1, 0));
    dp[0][0] = 1;
    FOR (i, 1, n) {
        FOR (j, 0, s1) {
            dp[i][j] = dp[i - 1][j];
            if (j >= t[i]) {
                dp[i][j] = dp[i][j] | dp[i - 1][j - t[i]];
            }
        }
    }

    int res = 0;
    ll sum = 0;
    FOR (i, 1, n) {
        sum += t[i];
        FOR (j, 0, s1) {
            if (dp[i][j] && sum - j <= s2) {
                res = i;
            }
        }
    }

    cout << res << endl;

    return 0;
}