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
 
string s;
int n, g1, g2, g3;
ll k;
ll d[100005][55];
    
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
 
    cin >> n >> k >> g1 >> g2 >> g3;
    cin >> s;
    s = '0' + s;
    
    FOR (j, 1, 50) {
        d[0][j] = -1e18;
    }
 
    FOR (i, 1, n) {
        FOR (j, 0, 50) {
            d[i][j] = d[i - 1][j];
            if (i >= 2 && s[i] == '.' && s[i - 1] == '.') {
                d[i][j] = max(d[i][j], d[i - 2][j] + g2);
            }
            if (j && i >= 3 && s[i] == '.' && s[i - 1] == '#' && s[i - 2] == '.') {
                d[i][j] = max(d[i][j], d[i - 3][j - 1] + g3);
            }
        }
    }
 
    int numDot = 0;
    FOR (i, 1, n) {
        if (s[i] == '.') numDot++;
    }
 
    k = min(k, (ll) numDot);
    
    ll res = 0;
    ll oldK = k;
    bool swapped = 0;

    if (g2 > g3) {
        swap(g2, g3);
        swapped = 1;
    }
 
    for (ll ii = 0; ii <= 50; ii++) {
        if (d[n][ii] < 0) continue;
        ll i2, i3;
        if (!swapped) {
            i3 = ii;
            i2 = (d[n][i3] - g3 * i3) / g2;
        }
        else {
            i2 = ii;
            i3 = (d[n][i2] - g2 * i2) / g3;
        }
        ll i1 = numDot - i2 * 2 - i3 * 2;
        k = oldK;
        // cout << i1 << " " << i2 << " " << i3 << endl;
 
        ll val = 0;
 
        ll uu = min(i1 / 2, k / 2);
 
        val = uu * 2ll * g1 + i2 * g2 + i3 * g3;
        k -= uu * 2;
        i1 -= uu * 2;
 
        if (g2 > g3) {
            swap(g2, g3);
            swap(i2, i3);
        }
 
        ll oldVal = val;
        ll oldK1 = k;
        ll I2 = i2;
        ll I3 = i3;
        ll I1 = i1;
 
        FOR (zz, 0, min(i1, k)) {
            i2 = I2;
            i3 = I3;
            k = oldK1;
            val = oldVal;
            k -= zz;
            val += zz * g1;
            // cout << val << endl;
            if (g2 < 2 * g1) {
                val += (2 * g1 - g2) * min(k / 2, i2);
                ll u = min(k / 2, i2);
                k -= 2 * u;
                i2 -= u;
            }  
 
            // cout << val << " " << k << " " << i2 << endl;
 
            if (g3 < 2 * g1) {
                val += (2 * g1 - g3) * min(k / 2, i3);
                ll u = min(k / 2, i3);
                k -= 2 * u;
                i3 -= u;
            }
            
 
            if (g2 < g1 && i2 && k) {
                val += (g1 - g2);
                k--;
            }
 
            if (g3 < g1 && i3 && k) {
                val += (g1 - g3);
                k--;
            }
            res = max(res, val);
        }
        // cout << val << endl;
        
    }
 
    cout << res << endl;
 
    return 0;
}