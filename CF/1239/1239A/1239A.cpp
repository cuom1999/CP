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
ll f[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    f[1] = 2;
    f[2] = 4;

    FOR (i, 3, 100000) {
        f[i] = (f[i - 1] + f[i - 2]) % K;
    }

    int n, m;
    cin >> n >> m;

    ll res = (f[n] + f[m] + K - 2) % K;

    cout << res << endl;
    return 0;
}