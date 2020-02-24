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

const ll K = 1e9 + 7;
ll a[100005], fact[100005], rev[100005];

ll pw(ll a, ll n) {
	if (n == 0) return 1;
	ll q = pw(a, n / 2);
	if (n % 2 == 0) {
		return q * q % K;
	}
	return q * q % K * a % K;
}

ll combi(int n, int k) {
	if (k < 0 || n < k) return 0;
	return fact[n] * rev[n - k] % K * rev[k] % K;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = rev[0] = 1;

	FOR (i, 1, 100000) {
		fact[i] = fact[i - 1] * i % K;
		rev[i] = pw(fact[i], K - 2);
	}

	int n, k;

	cin >> n >> k;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	vector<ll> A(n + 1), B(n + 1), C(n + 1);
	FOR (i, 0, n) {
		A[i] = a[i];
		B[n - i] = a[i];
		C[i] = combi(i, k - 2);
	}

	vector<ll> D;
	D = multiply(A, B, K);
	D = multiply(D, C, K);

	cout << D[n - 1] << endl;

	return 0;
}