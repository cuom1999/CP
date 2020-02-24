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

    int t;
    cin >> t;

    FOR (z, 1, t) {
        cout << "Case #" << z << ": ";
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n + 1), bitCnt(52);

        FOR (i, 1, n) {
            cin >> a[i];
            FOR (j, 0, 51) {
                if (a[i] & (1LL << j)) {
                    bitCnt[j]++;
                }
            }
        } 

        vector<ll> dp[52];
        FOR (i, 0, 51) dp[i].resize(2);

        dp[0][0] = bitCnt[0];
        dp[0][1] = n - bitCnt[0];

        FOR (i, 1, 51) {
            ll val0 = (1LL << i) * bitCnt[i];
            ll val1 = (1LL << i) * (n - bitCnt[i]);

            ll u = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][0] = u + val0;
            dp[i][1] = u + val1;
        }

        if (dp[51][0] > m && dp[51][1] > m) {
            cout << -1 << "\n";
        }
        else {
            int cur = 51;
            ll res = 0;
            while (cur >= 0) {
                if (dp[cur][1] <= m) {
                    res += (1LL << cur);
                    m -= (1LL << cur) * (n - bitCnt[cur]);
                }
                else {
                    m -= (1LL << cur) * (bitCnt[cur]);
                }
                cur--;
            }
            cout << res  << "\n";
        }
    }


    return 0;
}