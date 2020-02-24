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
ll fact[200005], inv[200005];
ll catalan[200005];

ll combi(int n, int k) {
    if (n < k || k < 0) return 0;
    return fact[n] * inv[n - k] % MOD * inv[k] % MOD;
}

ll pw(ll a, ll n) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD; 
}

typedef complex<double> base;
void fft(vector<base> &a, bool inv)
{
    int n = a.size(), j = 0;
    vector<base> roots(n/2);
    for(int i=1; i<n; i++)
    {
        int bit = (n >> 1);
        while(j >= bit)
        {
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for(int i=0; i<n/2; i++)
    {
        roots[i] = base(cos(ang * i), sin(ang * i));
    }

    for(int i=2; i<=n; i<<=1)
    {
        int step = n / i;
        for(int j=0; j<n; j+=i)
        {
            for(int k=0; k<i/2; k++)
            {
                base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w)
{
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int n = 2;
    while(n < v.size() + w.size()) n <<= 1;
    fv.resize(n);
    fw.resize(n);
    fft(fv, 0);
    fft(fw, 0);
    for(int i=0; i<n; i++) fv[i] *= fw[i];
    
    fft(fv, 1);
    n = v.size() + w.size() - 1;
    vector<ll> ret(n);
    for(int i=0; i<n; i++) ret[i] = (ll)round(fv[i].real());
    return ret;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w, ll mod)
{
    int n = 2;
    while(n < v.size() + w.size()) n <<= 1;
    vector<base> v1(n), v2(n), r1(n), r2(n);
    for(int i=0; i<v.size(); i++)
    {
        v1[i] = base(v[i] >> 15, v[i] & 32767);
    }
    for(int i=0; i<w.size(); i++)
    {
        v2[i] = base(w[i] >> 15, w[i] & 32767);
    }
    fft(v1, 0);
    fft(v2, 0);
    for(int i=0; i<n; i++)
    {
        int j = (i ? (n - i) : i);
        base ans1 = (v1[i] + conj(v1[j])) * base(0.5, 0);
        base ans2 = (v1[i] - conj(v1[j])) * base(0, -0.5);
        base ans3 = (v2[i] + conj(v2[j])) * base(0.5, 0);
        base ans4 = (v2[i] - conj(v2[j])) * base(0, -0.5);
        r1[i] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
        r2[i] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
    }
    fft(r1, 1);
    fft(r2, 1);
    n=v.size()+w.size()-1;
    vector<ll> ret(n);
    for(int i=0; i<n; i++)
    {
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) +
        (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        av %= mod, bv %= mod, cv %= mod;
        ret[i] = (av << 30) + (bv << 15) + cv;
        ret[i] %= mod;
        ret[i] += mod;
        ret[i] %= mod;
    }
    return ret;
}


ll d[100005], sum[100005];

void solve(int l, int r) {
    if (l == r) {
        if (l) sum[l] = (sum[l - 1] + d[l]) % MOD;
        return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    vector<ll> A(r - l + 1), B(r - l + 1);

    FOR (i, l, mid) {
        A[i - l] = sum[i];
    }
    FOR (i, 1, r - l) {
        B[i] = catalan[i];
    }

    A = multiply(A, B, MOD);
    A.resize(r - l + 1);

    FOR (i, mid + 1, r) {
        d[i] = (d[i] + A[i - l]) % MOD;
    }
    solve(mid + 1, r);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    fact[0] = inv[0] = 1;
    FOR (i, 1, 200000) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = pw(fact[i], MOD - 2);
    }

    int n, k;
    cin >> n >> k;
    FOR (i, 0, k - 1) {
        catalan[i * 2 + 2] = (combi(i * 2, i) - combi(i * 2, i - 1) + MOD) % MOD;
    }

    d[0] = 1;
    sum[0] = 1;
    // FOR (i, 1, n) {
    //     FOR (j, 1, i) {
    //         d[i] = (d[i] + catalan[j] * sum[i - j] % MOD) % MOD;
    //     }
    //     sum[i] = (sum[i - 1] + d[i]) % MOD;
    //     // cout << i << " " << d[i] << endl;
    // }
    solve(0, n);

    cout << sum[n] << endl;

    return 0;
}