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
#define popcnt(n) __builtin_popcountll(n)

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

const ll K = 998244353;

ll gt[100005], rev[100005];

ll mu(ll a, ll n) {
	if (n == 0) return 1;
	ll q = mu(a, n / 2);

	if (n % 2 == 0) return q * q % K;
	return q * q % K * a % K;
}

vector<ll> invP, U, res, A, P;

struct Matrix {
	ll coef[105][105];
	Matrix () {
		memset(coef, 0, sizeof(coef));
	}

	Matrix operator *(const Matrix &a) {
		Matrix res;
		FOR (i, 0, 20) {
			FOR (j, 0, 20) {
				FOR (k, 0, 20) {
					res.coef[i][j] += coef[i][k] * a.coef[k][j] % K;
					res.coef[i][j] %= K;
				}
			}
		}
		return res;
	}
};

Matrix mu(Matrix a, ll n) {
	if (n == 1) return a;
	Matrix Q = mu(a, n / 2);
	if (n % 2 == 0) return Q * Q;
	return Q * Q * a;
}

Matrix matA, matU;
ll p[100005];

int main()
{IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	
	gt[0] = rev[0] = 1;

	FOR (i, 1, 100000) {
		gt[i] = gt[i - 1] * 1ll * i % K;
		rev[i] = mu(gt[i], K - 2);
	}

	ll n, m;
	cin >> n >> m;

	FOR (i, 0, n) {
		cin >> p[i];
		U.pb(p[i] * gt[i] % K);
	}

	invP.resize(n + 1);

	FOR (i, 0, n) {
		invP[n - i] = rev[i];
	}

	A = multiply(invP, U, K);

	res.resize(n + 1);
	FOR (i, 0, n) {
		res[i] = rev[i] * A[i + n] % K;
		ll eigen = mu(i + 1, K - 2);
		res[i] = res[i] * mu(eigen, m) % K; 
	}

	P.resize(n + 1);

	FOR (i, 0, n) {
		U[i] = res[i] * gt[i] % K;
		P[i] = rev[n - i];
		if ((n - i) % 2) {
			P[i] = (K - P[i]) % K;
		}
	}

	A = multiply(P, U, K);

	FOR (i, 0, n) {
		res[i] = rev[i] * A[i + n] % K; 
	}

	FOR (i, 0, n) cout << res[i] << " "; cout << endl;

	
    return 0;
}