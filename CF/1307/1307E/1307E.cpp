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
int grass[5005];

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

    vector<int> cow[5005];
    FOR (i, 1, m) {
        int x, y;
        cin >> x >> y;
        cow[x].pb(y);
    }

    int res = 0;
    ll cntWays = 1;

    FOR (z, 1, 5000) {
        vector<ll> cnt(3, 0);
        for (int i = 0; i < cow[z].size(); i++) {
            if (cow[z][i] <= grass[z]) cnt[1]++;
            for (int j = i + 1; j < cow[z].size(); j++) {
                if (cow[z][i] + cow[z][j] <= grass[z]) {
                    cnt[2]++;
                }
            }
        }

        if (cnt[2] > 0) {
            res += 2;
            cntWays = cntWays * 2ll * cnt[2] % MOD; 
        }
        else if (cnt[1] > 0) {
            res += 1;
            cntWays = cntWays * 2ll * cnt[1] % MOD;
        }
    }
    cout << res << " " << cntWays << endl;


    return 0;
}