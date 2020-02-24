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
        ll s;
        cin >> n >> s;

        vector<ll> a(n + 1), sum(n + 1), ma(n + 1);
        FOR (i, 1, n) {
            ll x;
            cin >> x;
            a[i] = x;
            sum[i] = sum[i - 1] + a[i];
            ma[i] = max(ma[i - 1], a[i]);
        }
        if (sum[n] <= s) {
            cout << 0 << "\n";
        }
        else {
            int res = 0;
            int index = 0;
            FOR (i, 1, n) {
                if (sum[i] - ma[i] <= s) {
                    res = i - 1;
                    index = i;
                }
            }

            FOR (i, 1, index) {
                if (a[i] == ma[index]) {
                    cout << i << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}