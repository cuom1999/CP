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
        int n;
        cin >> n;
        if (!n) {
            cout << 0 << "\n";
            continue;
        }

        vector<int> a;
        FOR (i, 0, n - 1) {
            int x;
            cin >> x;
            a.pb(x);
        }

        a.erase(unique(all(a)), a.end());

        n = a.size();

        vector<int> dp(n + 1);

        FOR (i, 1, n) {
            dp[i] = INF;
            for (int j = i - 1; j >= i - 22 && j >= 0; j--) {
                if (a[i - 1] - a[j] <= 20) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
            // cout << i << " " << dp[i] << endl;
        }
        // cout << endl;
        cout << dp[n] << "\n";
    }



    return 0;
}