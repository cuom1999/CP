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

const ll MOD = 998244353;
ll _combi[2005][2005], sufCombi[2005][2005];

ll combi(int n, int k) {
    if (n < k || k < 0) return 0;
    return _combi[n][k];
}

ll greatEqual(int n, int k) {
    if (n < k) return 0;
    if (k < 0) k = 0;
    return sufCombi[n][k];
}

int a[2005], b[2005], pre[2005], suf[2005];
int n;
ll pw2;
string s;

ll calc(int k) {
    ll res = 0;
    FOR (i, 1, n) {
        // i is the first x[i] + a[i] = k + 1, x[i - 1] + a[i - 1] = k
        // y[i + 1] + b[i + 1] > k
        ll valA, valB;
        if (s[i - 1] == ')') valA = 0;
        else {
            valA = combi(pre[i - 1], k - a[i - 1]);
        }
        valB = greatEqual(suf[i + 1], k - b[i + 1] + 1);
        res = (res + valA * valB % MOD) % MOD;
    }
    res = (pw2 - res) % MOD;
    return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    _combi[0][0] = 1;
    FOR (i, 1, 2000) {
        _combi[i][0] = 1;
        FOR (j, 1, i) {
            _combi[i][j] = (_combi[i - 1][j - 1] + _combi[i - 1][j]) % MOD;
        }
    }

    FOR (i, 0, 2000) {
        FORD (j, i, 0) {
            sufCombi[i][j] = (sufCombi[i][j + 1] + _combi[i][j]) % MOD;
        }
    }

    cin >> s;

    n = s.size();
    FOR (i, 1, n) {
        a[i] = a[i - 1];
        pre[i] = pre[i - 1];
        if (s[i - 1] == '(') {
            a[i]++;
        }
        if (s[i - 1] == '?') {
            pre[i]++;
        }
    }

    FORD (i, n, 1) {
        b[i] = b[i + 1];
        suf[i] = suf[i + 1];
        if (s[i - 1] == ')') {
            b[i]++;
        }
        if (s[i - 1] == '?') {
            suf[i]++;
        }
    }

    pw2 = 1;
    FOR (i, 1, pre[n]) {
        pw2 = pw2 * 2 % MOD;
    }


    vector<ll> le(n + 1);
    FOR (i, 0, n) {
        le[i] = calc(i);
    }

    ll res = 0;
    FOR (i, 1, n) {
        res = (res + i * 1ll * (le[i] - le[i - 1]) % MOD) % MOD;
    }

    res = (res + MOD) % MOD;
    cout << res << endl;
    return 0;
}