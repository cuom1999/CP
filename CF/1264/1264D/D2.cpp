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
ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}

ll fact[1000005], inv[1000005];
int a[1000005], b[1000005], pre[1000005], suf[1000005];

ll combi(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();

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


    int total = pre[n];
    vector<int> sum0(n + 1), sum1(n + 1);

    fact[0] = inv[0] = 1;
    FOR (i, 1, total) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }

    sum0[0] = sum1[0] = 1;
    FOR (i, 1, total) {
        sum0[i] = (sum0[i - 1] + combi(total - 1, i)) % MOD;
        sum1[i] = (sum1[i - 1] + combi(total, i)) % MOD;
    }

    ll res = 0;
    FOR (i, 1, n) {
        ll oldRes = res;
        ll valA = b[i + 1] + suf[i + 1] - a[i - 1];
        ll valB = a[i - 1] + pre[i - 1] - b[i + 1];
        valA = min(valA, (ll)total + 1);
        valB = min(valB, (ll)total + 1);
        if (s[i - 1] == '(' && valA >= 1) {
            res = (res + sum1[valA - 1]) % MOD;
        }
        if (s[i - 1] == '?') {
            if (valA >= 1) {
                res = (res + sum0[valA - 1]) % MOD;
            }
        }
        // cout << i << " " << valA << " " << valB << endl;
        // cout << i << " " << res - oldRes << endl;
    }   

    cout << res << endl;

    return 0;
}