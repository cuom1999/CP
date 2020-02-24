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

ll d[105][105];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    ll g1, g2, g3;
    cin >> n >> k >> g1 >> g2 >> g3;

    string s;
    cin >> s;
    s = '0' + s;

    ll res = 0;
    FOR (i, 1, n) {
        FOR (j, 0, k) {
            d[i][j] = d[i - 1][j];
            if (j) d[i][j] = max(d[i][j], d[i - 1][j - 1] + g1);
            if (i >= 2 && s[i] == '.' && s[i - 1] == '.') {
                d[i][j] = max(d[i][j], d[i - 2][j] + g2);
            }
            if (i >= 3 && s[i] == '.' && s[i - 1] == '#' && s[i - 2] == '.') {
                d[i][j] = max(d[i][j], d[i - 3][j] + g3);
            }
            cout << i << " " << j << " " << d[i][j] << endl;
            if (i == n) {
                // cout << j << " " << d[i][j] << endl;
                res = max(res, d[i][j]);
            }
        }
    }

    cout << res << endl;




    return 0;
}