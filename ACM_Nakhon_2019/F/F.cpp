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

int c[17][17];

ll calc(ll n) {
    ll res = 1;
    ll N = n;
    while (n) {
        ll val = n % 7;
        n /= 7;
        res *= (val + 1);
    }
    // return N + 1 - res;
    return res;
}

ll sum(ll n) {
    ll res = 0;
    FOR (i, 0, n) {
        res = (res + i + 1 - calc(i));
    }
    return res;
}

const ll MOD = 1e9 + 7;
ll d[35][2];
int pos[35];

vector<int> a;
ll dp(int index, bool tight) {
    if (index == a.size()) {
        // cout << index << " " << tight << " " << 1 << endl;
        return d[index][tight] = 1;
    }
    ll &res = d[index][tight];
    if (res != -1) return res;
    
    int startDig = 6;
    if (tight) startDig = a[index];    

    res = 0;
    FOR (i, 0, startDig) {
        bool newTight = 0;
        if (i == startDig && tight) newTight = 1;
        
        res += (i + 1) * dp(index + 1, newTight);
        res %= MOD;
        // cout << i << " " << index << " " << res << endl;
    }
    // cout << index << " " << tight << " " << res << endl;
    return res;
}

ll calc2(ll n) {
    a.clear();
    ll N = n;
    while (n) {
        a.pb(n % 7);
        n /= 7;
    }
    reverse(all(a));
    memset(d, -1, sizeof(d));
    
    ll zero = dp(0, 1);
    // cout << zero << endl;
    
    N++;
    N %= MOD;
    ll total = N * (N + 1) / 2 % MOD;
    return (total - zero + MOD) % MOD;
}

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;
    FOR (z, 1, t) {
        cout << "Case " << z << ": ";
        ll n;
        cin >> n;
        cout << calc2(n) << "\n";
    }
    return 0;
}