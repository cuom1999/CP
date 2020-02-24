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

ll d[55][55][55];
ll c[55][55];
ll n, m, pos;

ll dp(int i, int j, int k) {
    if (!(k <= j && j <= n - i)) return 0;
    if (j < 0 || k < 0) return 0;
    if (i == n) {
        cout << i << " " << j << " " << k << ": " << 1 << endl;    
        return 1;
    }
    ll &res = d[i][j][k];
    if (res != -1) return res;

    res = 0;
    res = dp(i + 1, j - 1, k) * j;
    res += dp(i + 1, j, k) * (n - i - j);
    res += dp(i + 1, j - 1, k - 1);
    res += dp(i + 1, j - 2, k) * (j - 1);
    res += dp(i + 1, j - 1, k) * (n - i - j);
    cout << i << " " << j << " " << k << ": " << res << endl;    
    return res;
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> pos;

    memset(d, -1, sizeof(d));
    FOR (i, 0, n) {
        dp(0, n, i);
    }

    return 0;
}