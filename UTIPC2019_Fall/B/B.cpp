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

const ll K = 1e9 + 7;

ll f[50005][4][4];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    f[1][1][1] = f[1][2][1] = 6;
    int n;
    cin >> n;   

    if (n == 0) {
        cout << 1;
        return 0;
    }


    FOR (i, 2, n) {
        FOR (j, 1, 2) {
            f[i][1][1] = (f[i][1][1] + 6 * f[i - 1][2][j] % K) % K;
        }
        FOR (j, 1, 2) {
            f[i][2][1] = (f[i][2][1] + 6 * f[i - 1][1][j] % K) % K;
        }
        f[i][1][2] = 5 * f[i - 1][1][1] % K;
        f[i][2][2] = 5 * f[i - 1][2][1] % K;
    }

    ll s = 0;
    FOR (i, 1, 2) {
        FOR (j, 1, 3) {
            s = (s + f[n][i][j]) % K;
        }
    }
    cout << s << endl;
    return 0;
}