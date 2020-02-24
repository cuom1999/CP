#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("gymnastics.in","r",stdin)
#define OUT freopen("gymnastics.out","w",stdout)
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

int a[25][25];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            int x;
            cin >> x;
            a[i][x] = j;
        }
    }
    int res = 0;

    FOR (i, 1, m) {
        FOR (j, i + 1, m) {
            int b = 0, c = 0;
            FOR (k, 1, n) {
                if (a[k][i] > a[k][j]) b++;
                else c++;
            }
            if (!b || !c) {
                res++;
                // cout << i << " " << j << endl;
            }
        }
    }
    cout << res << endl;

    return 0;
}