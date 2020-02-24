#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

typedef complex<double> base;

ll n, p, d; // d = sqrt(n);

ll mul (ll a, ll b){
    a %= p; a = (a + p) % p;
    b %= p; b = (b + p) % p;
    ll b1 = b % 1000000;
    ll b2 = b / 1000000;
    return (a * b1 + a * b2 % p * 1000000 % p) % p;
}

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

vector<ll> multiply1(vector<ll> &v, vector<ll> &w, ll mod)
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
    n=v.size() + w.size() - 1;
    vector<ll> ret(n);
    for(int i=0; i<n; i++)
    {
        ll av = (ll)round(r1[i].real());
        ll bv = (ll)round(r1[i].imag()) +
                  (ll)round(r2[i].real());
        ll cv = (ll)round(r2[i].imag());
        av %= mod, bv %= mod, cv %= mod;
        ret[i] = mul(av, 1LL << 30) + mul(bv, 1LL << 15) + cv;
        ret[i] %= mod;
        ret[i] += mod;
        ret[i] %= mod;
    }
    return ret;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w, ll mod)
{
    vector<ll> res, v1, v2, w1, w2;
    v1.resize(v.size());
    v2.resize(v.size());
    w1.resize(w.size());
    w2.resize(w.size());
    int FOO = 1000000;
    for (int i = 0; i < v.size(); i++) {
        v1[i] = v[i] / FOO;
        v2[i] = v[i] % FOO; 
    }    

    for (int i = 0; i < w.size(); i++) {
        w1[i] = w[i] / FOO;
        w2[i] = w[i] % FOO;
    }

    vector<ll> Q;
    res = multiply1(v1, w1, mod);

    for (int i = 0; i < res.size(); i++){
        res[i] = mul(res[i], FOO);
        res[i] = mul(res[i], FOO);
    }
    Q = multiply1(v1, w2, mod);

    for (int i = 0; i < res.size(); i++){
        res[i] = (res[i] + mul(Q[i], FOO)) % mod;
    }

    Q = multiply1(v2, w1, mod);

    for (int i = 0; i < res.size(); i++){
        res[i] = (res[i] + mul(Q[i], FOO)) % mod;
    }

    Q = multiply1(v2, w2, mod);

    for (int i = 0; i < res.size(); i++){
        res[i] = (res[i] + Q[i]) % mod;
    }
    return res;
}

vector<ll> A,B,C;
ll gt[2000005], rev[2000005], inv[2000005];


ll mu(ll a, ll n){
    if (n == 0) return 1;
    ll q = mu(a, n / 2);
    if (n % 2 == 0) return mul(q, q);
    return mul(mul(q, q), a);
}

// return f[0], f[d],..., f[Nd] in which f(x) = (x + 1)(x + 2)...(x + N)
vector<ll> solve(ll N){
    vector<ll> res;
    if (N == 1){
        res.pb(1);
        res.pb(d + 1);
        return res;
    }
    if (N % 2) {
        vector<ll> old = solve(N - 1);
        FOR (i, 0, N - 1) {
            old[i] = mul(old[i], mul(i, d) + N);
        }
        ll prod = 1;
        ll u = mul(N, d);
        FOR (i, 1, N) {
            prod = mul(prod, u + i);
        }
        old.pb(prod);
        return old;
    }

    ll m = N / 2;
    vector<ll> old = solve(m);
    A.clear();
    A.resize(m + 1);
    FOR (i, 0, m){
        A[i] = mul(old[i], rev[m - i]);
        A[i] = mul(A[i], rev[i]);
        if ((m - i) % 2) A[i] = (p - A[i]) % p; 
    }

    B.resize(N + 1);
    FOR (i, 1 , N) {
        B[i] = inv[i]; 
    }

    //for (auto i: A) cout << i << " "; cout << endl;
    //for (auto i: B) cout << i << " "; cout << endl;

    B = multiply(A, B, p);

    //for (auto i: B) cout << i << " "; cout << endl;

    old.resize(N + 1);
    //old[i] = f(n/2)[id] i = 1 -> N

    FOR (i, 1, m){
        old[i + m] = mul(gt[i + m], rev[i - 1]);
        old[i + m] = mul(old[i + m], B[i + m]);
    }

    vector<ll> g(N + 1); // g[i] = f(N / 2)[id + m], i = 0 -> N;

    C.resize(N + m + 1);
    FOR (i, 0, N + m) {
        ll Q = (mul(i, d) + m - mul(m, d)) % p;
        Q = (Q + p) % p;
        C[i] = mu(Q, p - 2);
    }   
    C = multiply(C, A, p);

    //for (auto i: A) cout << i << " "; cout << endl;
    //for (auto i: C) cout << i << " "; cout << endl;

    ll prod = 1;
    FOR (i, 0, m) prod = mul(prod, m - mul(i, d));

    ll deno = mu(d, m);
    deno = mu(deno, p - 2);

    prod = mul(prod, deno);

    FOR (i, 0, N){
        g[i] = mul(C[i + m], prod);
        prod = mul(prod, mul(i + 1, d) + m);
        prod = mul(prod, mu(mul(i - m, d) + m, p - 2));
        //cout << i << " " << g[i] << endl;
    }

    // f(n)[i] = old[i] * g[i]
    res.resize(N + 1);
    FOR (i, 0, N){
        res[i] = mul(old[i], g[i]);
    }

    return res;
}

vector<ll> test(ll N){
    vector<ll> res;
    if (N == 1){
        res.pb(1);
        res.pb(d + 1);
        return res;
    }
    if (1) {
        vector<ll> old = solve(N - 1);
        FOR (i, 0, N - 1) {
            old[i] = mul(old[i], mul(i, d) + N);
        }
        ll prod = 1;
        ll u = mul(N, d);
        FOR (i, 1, N) {
            prod = mul(prod, u + i);
        }
        old.pb(prod);
        return old;
    }
}

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    FOR (z, 1, t){
        cin >> n >> p;
        gt[0]  = rev[0] = 1;

        if (n == 0) {
            cout << 1 << endl;
            continue;
        }
        if (n >= p) {
            cout << 0 << endl;
            continue;
        }
        
        d = sqrt(n);
        gt[1] = inv[1] = rev[1] = 1;
        FOR (i, 2, 2 * d + 10){
            gt[i] = mul(gt[i - 1], i);
            inv[i] = mul(-inv[p % i], (p / i));
            rev[i] = mul(rev[i - 1], inv[i]);
        }

        if (d > n / d) d--;

        vector<ll> res = solve(d);
        //vector<ll> res1 = test(2);
        //for (auto i: res) cout << i << " "; cout << endl;
        //for (auto i: res1) cout << i << " "; cout << endl;
        //return 0;
        ll ans = 1;

        FOR (i, 0, d - 1) {
            ans = mul(ans, res[i]);
        }
        FOR (i, d * d + 1, n) ans = mul(ans, i);
        cout << ans << endl;
        /*ll ans1 = 1;
        FOR (i, 1, n) {
            ans1 = mul(ans1, i);
        }
        cout << ans1 << endl;*/
    }

    return 0;
}
