#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

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
    /* In NTT, let prr = primitive root. Then,
    int ang = ipow(prr, (mod - 1) / n);
    if(inv) ang = ipow(ang, mod - 2);
    for(int i=0; i<n/2; i++){
    roots[i] = (i ? (1ll * roots[i-1] * ang % mod) : 1);
    }
    Others are same. If there is /= n, do *= ipow(n, mod - 2).
    In XOR convolution, roots[*] = 1.
    */
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
    n=v.size()+w.size()-1;
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
vector<ll> A,B,C;
const ll K = 1e9 + 7;
ll pw[100005];
int N, p;
ll b;
vector<int> asciiValues;
    
vector<ll> solve(int n) {
    if (n == 0) {
        vector<ll> A;
        A.pb(1);
        return A;
    }
    if (n % 2) {
        vector<ll> A = solve(n - 1);
        vector<ll> B(p);
        for (int c = 0; c < asciiValues.size(); c++) {
            B[pw[n - 1] * asciiValues[c] % p]++;
        }
        A = multiply(A, B, K);
        for (int i = 0; i < A.size(); i++) {
            if (i >= p) {
                A[i % p] = (A[i % p] + A[i]) % K;
            }
        }
        A.resize(p);
        return A;
    }
    else {
        vector<ll> A = solve(n / 2);
        A.resize(p);
        vector<ll> B(p);
        FOR (i, 0, p - 1) {
            B[pw[n / 2] * i % p] = (B[pw[n / 2] * i % p] + A[i]) % K;
        }
        A = multiply(A, B, K);
        for (int i = 0; i < A.size(); i++) {
            if (i >= p) {
                A[i % p] = (A[i % p] + A[i]) % K;
            }
        }
        A.resize(p);
        return A;
    }
}

int main()
{IN;//OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    FOR (i, 'a', 'z') asciiValues.pb(i);
    FOR (i, 'A', 'Z') asciiValues.pb(i);

    cin >> N >> p >> b;
    pw[0] = 1;
    FOR (i, 1, 100000) {
        pw[i] = pw[i - 1] * 1ll * b % p;
    }
    vector<ll> res = solve(N);
    FOR (i, 0, p - 1) {
        cout << res[i] << " ";
    }

    return 0;
}
