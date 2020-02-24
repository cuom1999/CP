#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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

ll pw(ll a, ll n, ll p) {
    if (n == 0) return 1;
    ll q = pw(a, n / 2, p);
    if (n % 2 == 0) return q * q % p;
    return q * q % p * a % p;
}

ll n, p, k;

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
    vector<ll> res(p);
    for (int i = 0; i < ret.size(); i++) {
        res[i % p] = (res[i % p] + ret[i]) % mod; 
    }
    return res;
}


vector<ll> product(vector<vector<ll>>& poly) {
    vector<ll> res(p);
    res[0] = 1;
    for (int i = 0; i < poly.size(); i++) {
        vector<ll> tmp(p);
        for (auto j: poly[i]) {
            // cout << j << " ";
            FOR (i, 0, p - 1) {
                tmp[(i + j) % p] += res[i];
                tmp[(i + j) % p] %= K;
            }
        }
        // cout << endl;
        res = tmp;
    }
    return res;
}

vector<ll> pw(vector<ll>&a, ll n) {
    if (n == 1) {
        return a; 
    }
    vector<ll> q = pw(a, n / 2);
    if (n % 2 == 0) return multiply(q, q, K);
    vector<ll> tmp = multiply(q, q, K);
    return multiply(tmp, a, K);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> p >> k;

    if (n == 1) {
        int res = 0;
        FOR (i, 0, 9) {
            if (i % p == k) res++;
        }
        cout << res;
        return 0;
    }
    if (p != 2 && p != 5) {
        vector<vector<ll>> poly;

        ll m = (n - 2) / 2;
        ll m0 = m / (p - 1) * (p - 1);
        vector<ll> coef(1005);

        for (int i = 0; i < p - 1 && i <= n - 1; i++) {
            coef[i] = (pw(10, i, p) + pw(10, n - 1 - i, p)) % p;
        }

        vector<ll> v[1005];
        FOR (i, 0, p - 2) {
            FOR (j, 0, 9) {
                v[i].pb(j * coef[i] % p);
            }
        }

        vector<ll> firstDigit;
        FOR (i, 1, 9) firstDigit.pb(i * coef[0] % p);
        poly.pb(firstDigit);
        FOR (i, m0 + 1, m) {
            poly.pb(v[i % (p - 1)]);
        }
        if (n % 2) {
            ll val = pw(10, (n - 1) / 2, p);
            vector<ll> tmp;
            FOR (i, 0, 9) {
                tmp.pb(i * val % p);
            }
            poly.pb(tmp);
        }
        vector<ll> res = product(poly);
        // cout << res.size() << endl;

        // (prod(v[i])) ^ (m / (p - 1))
        if (m / (p - 1)) {
            vector<vector<ll>> prod;
            FOR (i, 0, p - 2) prod.pb(v[i]);
            vector<ll> A = product(prod);
            vector<ll> B = pw(A, m / (p - 1));
            res = multiply(res, B, K);
        }
        res.resize(p);
        cout << res[k] << endl;
    }
    else {
        ll cnt = 0;
        ll m = (n - 2) / 2;
        
        FOR (i, 1, 9) {
            if (i % p == k) {
                cnt++;
            }
        }
        ll res = cnt * pw(10, m, K) % K;
        if (n % 2) res = res * 10 % K;
        cout << res << endl;
    }

    return 0;
}