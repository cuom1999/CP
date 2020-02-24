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

const ll K=1e9+7;


typedef complex<double> base;

ll mu(ll a, ll n){
    if (n==0) return 1;
    ll q=mu(a,n/2);
    if (n%2==0) return q*q%K;
    return q*q%K*a%K;
}
const int MaxN=100005;
ll inv[MaxN];
ll n,k;

namespace Poly{
    inline void fft(vector<base> &a, bool inv)
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
    inline vector<ll> multiply(vector<ll> &v, vector<ll> &w)
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
    inline vector<ll> multiply(vector<ll> &v, vector<ll> &w, ll mod)
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
        n=min(n,(int)k+1);
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
    // mod x^(m+1)
    inline vector<ll> multiply_modx(vector<ll> &v, vector<ll> &w, ll mod, int k )
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
        if (n>k+1) n=k+1;
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

    //take mod x^(m+1)
    inline vector<ll> inverse(vector<ll> &v, int m){
        int n=1;
        vector<ll> R,V,G;
        R.pb(mu(v[0],K-2));
        V.pb(v[0]);
        while (n<=m){
            n<<=1;
            for (int i=n/2; i<v.size() && i<n; i++) V.pb(v[i]);

            G=multiply(R,R,K);
            G=multiply_modx(G,V,K,n-1);

            FOR (i,n/2,n-1){
                R.pb((-G[i]+K)%K);
            }
        }
        R.resize(m+1);
        return R;
    }

    // mod x^(m+1)
    inline vector<ll> sqrt(vector<ll> &v, int m){
        //rt^2=v[0]
        //this only works with v[0]=0,1
        assert(v[0]==1 || v[0]==0);

        ll rev2=mu(2,K-2);
        int n=1;
        vector<ll> V,R,G,P;
        R.pb(v[0]);
        V.pb(v[0]);

        n=1;
        while (n<=m){
            n<<=1;
            for (int i=n/2; i<v.size() && i<n; i++) V.pb(v[i]);
            G=inverse(R,n-1);
            G=multiply_modx(G,V,K,n-1);
            for (int i=n/2; i<n; i++){
                R.pb(G[i]*rev2%K);
            }
        }
        R.resize(m+1);
        return R;
    }

    inline vector<ll> derivative(vector<ll> &a, int m){
        vector<ll> b;
        for (ll i=0; i+1<a.size(); i++){
            b.pb(a[i+1]*(i+1)%K);
        }
        return b;
    }

    inline vector<ll> integrate(vector<ll> &a, int m){
        vector<ll> b;
        b.pb(0);
        for (ll i=1; i-1<a.size() && i<=m; i++){
            b.pb(a[i-1]*inv[i]%K);
        }
        return b;
    }

    vector<ll> ln(vector<ll> &a, int m){
        vector<ll> b=inverse(a,m);
        vector<ll> c=derivative(a,m);
        b=multiply_modx(b,c,K,m);
        b=integrate(b,m);
        return b;
    }
    vector<ll> exp(vector<ll> &v, int m){
        assert (v.size()>1);
        int n=1;
        vector<ll> R,G;
        R.pb(1);
        while (n<=m){
            n<<=1;
            G=ln(R,n-1);
            for (int i=0; i<n && i<=m; i++) G[i]=(v[i]-G[i]+K)%K;
            G[0]++;
            R=multiply_modx (R,G,K,n-1);
        }
        R.resize(m+1);
        return R;
    }
    vector<ll> pw(vector<ll> &a, int n, int m){
        vector<ll> res;
        if (n==0){
            res.pb(1);
            return res;
        }
        ll M=mu(a[0],n);
        res=ln(a,m);
        FOR (i,0,m) res[i]=res[i]*n%K;
        res=exp(res,m);
        FOR (i,0,m) res[i]=res[i]*M%K;
        return res;
    }
};

using namespace Poly;

vector<ll> A,E;

ll gt[60005], rev[60005];

ll Combi(ll n, ll k){
    if (n<k) return 0;
    return gt[n]*rev[n-k]%K*rev[k]%K;
}

vector<ll> solve(ll n){
    if (n==1) return E;
    vector<ll> Q=solve(n/2);
    if (n%2==0){
        vector<ll> P(k+1);
        ll u=mu(2,n/2);
        ll u1=1;
        for (int i=0; i<Q.size(); i++){
            P[i]=u1*Q[i]%K;
            u1=u1*u%K;
        }
        return multiply(P,Q,K);
    }
    else{
        vector<ll> P(k+1);
        ll u=1;
        for (int i=0; i<Q.size(); i++){
            P[i]=Q[i]*u%K;
            u=u*2%K;
        }   
        P=multiply(P,E,K);
        u=mu(2,n/2);
        ll u1=1;
        for (int i=0; i<Q.size(); i++){
            P[i]=u1*P[i]%K;
            u1=u1*u%K;
        }
        return multiply(P,Q,K);
    }
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    inv[1]=1;
    FOR (i,2,100000) inv[i]=(K-K/i)*1ll*inv[K%i]%K;
    gt[0]=rev[0]=1;
    FOR (i,1,60000){
        gt[i]=gt[i-1]*1ll*i%K;
        rev[i]=rev[i-1]*inv[i]%K;
    }

    cin>>n>>k;
    if (n>k) {
        cout<<0; return 0;
    }
    E.resize(k+1);
    FOR (i,1,k) E[i]=rev[i]%K;
    A=solve(n);
    ll res=0;
    FOR (i,0,k){
        res=(res+Combi(k,i)*A[i]%K*gt[i]%K)%K;
    }
    cout<<res<<endl;





         return 0;
}
