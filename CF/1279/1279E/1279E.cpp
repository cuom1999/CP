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

ll d[55], g[55];

vector<int> solve(int st, int n, ll k) {
    vector<int> res;
    ll curG = 0;
    FOR (i, 1, n) {
        curG += d[i] * g[n - i];
        if (curG > k) 
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    d[1] = g[1] = 1;
    d[0] = g[0] = 1;

    FOR (i, 2, 50) g[i] = (1e18) + 1;
    FOR (i, 2, 50) {
        g[i] = 0;
        if (i >= 3) d[i] = d[i - 1] * (i - 2);
        else d[i] = 1;
        FOR (j, 1, i) {
            g[i] += d[j] * g[i - j];
        }
        // cout << g[i] << " ";
        if (g[i] > 1e18) break;
    }
    // cout << endl;

    int t;
    cin >> t;
    FOR (z, 1, t) {
        int n;
        ll k;
        cin >> n >> k;
        if (k > g[n]) {
            cout << -1 << "\n";
        }
        else {

        }
    }
    return 0;
}