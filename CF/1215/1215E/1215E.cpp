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

ll cost[25][25], occ[25], f[25][(1 << 20) + 5], d[1 << 20];
int n;
int a[400005];

inline ll calcCost(int x, int y) {
    ll cnt = 0;
    ll res = 0;
    FOR (i, 1, n) {
        if (a[i] == x) cnt++;
        if (a[i] == y) res += cnt;
    }   
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    
    cin >> n;

    FOR (i, 1, n) {
        cin >> a[i];
        occ[a[i]]++;
    }

    FOR (i, 1, 20) {
        FOR (j, i + 1, 20) {
            cost[i][j] = calcCost(i, j);
            cost[j][i] = occ[i] * occ[j] - cost[i][j];
        }
    }
    
    vector<int> allBits;
    int N = (1 << 20) - 1;
    FOR (i, 0, N) {
        allBits.pb(i);
    }

    FOR (i, 1, 20) {
        FOR (j, 0, N) {
            if (j == 0) {
                f[i][j] = 0;
            }
            else {
                int u = j - (1 << flog2(j));
                f[i][j] = f[i][u] + cost[flog2(j) + 1][i];
            }
        }
    }

    FORD (bit, N, 0) {
        if (bit != N) d[bit] = 1e18;
        FOR (i, 0, 19) {
            if (((1 << i) & bit) == 0) {
                d[bit] = min(d[bit], d[bit | (1 << i)] + f[i + 1][N ^ bit ^ (1 << i)]);
            }
        }
    }

    cout << d[0] << endl;
    return 0;
}