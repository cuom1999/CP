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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

const int MAXN = 100000;

ll openH[5 * MAXN + 5], openV[5 * MAXN + 5], closeH[5 * MAXN + 5], closeV[5 * MAXN + 5];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    FOR (i, 1, n) {
        char c;
        int t, m, a;
        cin >> c >> t >> m >> a;
        if (c == 'h') {
            openH[t - a + MAXN]++;
            closeH[t - a + MAXN + m]++;
            // cout << t - a << " h " << t - a + m << endl;
        }
        else {
            openV[t - a + MAXN]++;
            closeV[t - a + m + MAXN]++;
            // cout << t - a << " v " << t - a + m << endl; 
        }
    }

    ll res = 0;
    ll curH = 0, curV = 0;
    FOR (i, 0, 5 * MAXN) {
        curH -= closeH[i];
        curV -= closeV[i];

        res += openH[i] * curV;
        curH += openH[i];

        res += openV[i] * curH;
        curV += openV[i];
    }

    cout << res << endl;
    return 0;
}