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

int grass[5005], f[5005], h[5005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    FOR (i, 1, n) {
        int x;
        cin >> x;
        grass[x]++;
    }

    FOR (i, 1, m) {
        cin >> f[i] >> h[i];
    }

    int cnt = 0;
    FOR (bit, 0, (1 << m) - 1) {
        for (int mask = bit; mask; mask = bit & (mask - 1)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}