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
        int n, x;
        cin >> n >> x;

        vector<int> a(n + 1);

        int maxVal = 0;
        FOR (i, 1, n) {
            cin >> a[i];
            maxVal = max(maxVal, a[i]);
        }
        int res = INF;
        if (x % maxVal == 0) {
            res = x / maxVal;
        }
        else {
            res = (x - 1) / maxVal + 1 + 1;
        }
        FOR (i, 1, n) {
            if (x < a[i]) continue;
            int y = (x - a[i]);
            int cur = 1;
            if (y > 0) {
                cur += (y - 1) / maxVal + 1;
            }
            res = min(res, cur);
        }
        cout << res << "\n";

    }

    return 0;
}