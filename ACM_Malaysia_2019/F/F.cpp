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

const ll MOD = 1e9 + 7;
ll d[2005][606];
vector<int> banned[2005];
int n, dist;  

int get(int bit, int pos) {
    pos += 4;
    return (bool) (bit & (1 << pos));
}

ll dp(int index, int bit) {
    if (index == n + 1) {
        // FOR (i, -dist - 1, dist - 1) {
        //     if (get(bit, 0))
        // }
        return 1;
    }
    ll &res = d[index][bit];
    if (res != -1) return res;

    vector<int> unused(9);
    for (auto i: banned[index]) {
        unused[i - index + 4] = 1;
    }
    res = 0;
    FOR (j, -dist, dist) {
        int i = index + j;
        if (i < 1 || i > n) continue; 
        if (unused[i - index + 4]) continue;
        if (get(bit, i - index) == 0) {
            int newBit = bit / 2 + (1 << (i - index + 3));
            res = (res + dp(index + 1, newBit)) % MOD;
        }
    }
    // cout << index << " " << bit << " " << res << endl;
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int m;
    cin >> n >> dist >> m;
    FOR (i, 1, m) {
        int u, v;
        cin >> u >> v;
        if (abs(u - v) > dist) continue;
        banned[u].pb(v);
    }
    memset(d, -1, sizeof(d));
    cout << dp(1, 0) << endl;

    return 0;
}