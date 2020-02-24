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

ld calc (ld a, ld b) {
    if (a == 0) return 0;
    return pow(a, a / b);
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ld a[105];
    int n;
    cin >> n;

    FOR (i, 1, n) {
        cin >> a[i];
        a[i] /= 100;
    }

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    ld p[105][105];
    ld res = 0;
    FOR (m, 1, n) {
        memset(p, 0, sizeof(p));
        p[0][0] = 1;
        FOR (i, 1, m) {
            FOR (j, 0, i) {
                p[i][j] = p[i - 1][j] * (1 - a[i]);
                if (j >= 1) p[i][j] += p[i - 1][j - 1] * a[i];
                // cout << i << " " << j << " " << p[i][j] << endl;
            }
        }

        ld val = 0;
        FOR (i, 0, m) {
            val += calc(i, m) * p[m][i];
        }
        // cout << m << " " << val << endl;
        res = max(res, val);
    }

    cout << fixed << setprecision(9) << res << endl;

    return 0;
}