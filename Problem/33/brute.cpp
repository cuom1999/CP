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



vector<ld> x;
ld f[105][400005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR (i, 1, n) {
        cin >> a[i];
    }
    for (ld i = -100; i <= 100; i += 0.001) {
        x.pb(i);
    }

    FOR (i, 1, n) {
        f[i][0] = f[i - 1][0] + sq(x[0] - a[i]);
        ld val = 0;
        for (int j = 1; j < x.size(); j++) {
            f[i][j] = min(f[i][j - 1], f[i - 1][j] + sq(x[j] - a[i]));
        }
    }

    cout << fixed << setprecision(8) << f[n][x.size() - 1] << endl;
    return 0;
}