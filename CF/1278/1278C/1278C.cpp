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
        vector<int> a(n + 1), b(n + 1), x(n + 1), y(n + 2);
        map<int, int> d;
        FOR (i, 1, n) {
            cin >> a[i];
        }
        FOR (i, 1, n) {
            cin >> b[i];
        }
        d[0] = 0;
        
        FOR (i, 1, n) {
            x[i] = x[i - 1] + 1;
            if (a[i] == 2) x[i] -= 2;
            d[x[i]] = i;
        } 
        FORD (i, n, 1) {
            y[i] = y[i + 1] + 1;
            if (b[i] == 1) y[i] -= 2;
        }

        int res = INF;
        FOR (i, 1, n + 1) {
            if (d.count(y[i])) {
                // cout << i << " " << y[i] << " " << d[y[i]] << endl;
                res = min(res, (i - 1 + n - d[y[i]]));
                // cout << res << endl;
            }
        }
        cout << res << endl;
    }

    return 0;
}