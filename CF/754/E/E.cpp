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
// status: not tested with big polynomials :v (~ 500 x 500)
// tested with small ones (100 x 100)
typedef complex<double> base;
	
namespace FFT_2D {
	vector<int> inv_fft;
	vector<base> roots;
		
	void preCalcFFT(int n, bool inv) {
		inv_fft.resize(n);

		int j = 0;
		for(int i=1; i<n; i++)
		{
			int bit = (n >> 1);
			while(j >= bit)
			{
				j -= bit;
				bit >>= 1;
			}
			j += bit;
			inv_fft[i] = j;
		}
		roots.resize(n / 2);
		double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
		
		for(int i=0; i<n/2; i++)
		{
			roots[i] = base(cos(ang * i), sin(ang * i));
		}
	}

	void fft(vector<base> &a, bool inv)
	{
		int n = a.size();
		for(int i=1; i<n; i++)
		{
			if(i < inv_fft[i]) swap(a[i], a[inv_fft[i]]);
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

	void fft2D(vector<vector<base>> &a, bool inv) {
		// fft rows
		preCalcFFT(a[0].size(), inv);
		for (int _row = 0; _row < a.size(); _row++) {
			fft(a[_row], inv);
		}

		// fft columns
		preCalcFFT(a.size(), inv);
		for (int _col = 0; _col < a[0].size(); _col++) {
			vector<base> tmp;
			for (int i = 0; i < a.size(); i++) {
				tmp.pb(a[i][_col]);
			}
			fft(tmp, inv);
			for (int i = 0; i < a.size(); i++) {
				a[i][_col] = tmp[i];
			}
		}
	}

	vector<vector<base>> multiply(vector<vector<base>> &v, vector<vector<base>> &w)
	{
		int _row = 1;
		while (_row < v.size() + w.size()) _row <<= 1;

		vector<vector<base>> fv(_row), fw(_row);
		
		int _colv = 1, _colw = 1;
		FOR (i, 0, _row - 1) {
			if (i < v.size()) fv[i] = vector<base>(all(v[i])), _colv = max(_colv, (int) v[i].size());
			if (i < w.size()) fw[i] = vector<base>(all(w[i])), _colw = max(_colw, (int) w[i].size());
		}

		int _col = 1;
		while(_col < _colv + _colw) _col <<= 1;
		FOR (i, 0, _row - 1) {
			fv[i].resize(_col);
			fw[i].resize(_col);
		}

		fft2D(fv, 0);
		fft2D(fw, 0);

		FOR (i, 0, _row - 1) {
			FOR (j, 0, _col - 1) { 
				fv[i][j] *= fw[i][j];
			}
		}
		
		fft2D(fv, 1);

		return fv;
	}
	vector<vector<ll>> multiply(vector<vector<ll>> &v, vector<vector<ll>> &w, ll mod)
	{
		int _row = 1, _colv = 1, _colw = 1, _col = 1;
		for (int i = 0; i < v.size(); i++) _colv = max(_colv, (int) v[i].size());
		for (int i = 0; i < w.size(); i++) _colw = max(_colw, (int) w[i].size());
		while (_row < v.size() + w.size()) _row <<= 1;
		while (_col < _colw + _colv) _col <<= 1;
		vector<vector<base>> v1(_row), v2(_row), r1(_row), r2(_row);
		FOR (i, 0, _row - 1) {
			v1[i].resize(_col);
			r1[i].resize(_col);
			v2[i].resize(_col);
			r2[i].resize(_col);
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				v1[i][j] = base(v[i][j] >> 15, v[i][j] & 32767);
			}
		}

		for (int i = 0; i < w.size(); i++) {
			for (int j = 0; j < w[i].size(); j++) {
				v2[i][j] = base(w[i][j] >> 15, w[i][j] & 32767);
			}
		}

		fft2D(v1, 0);
		fft2D(v2, 0);

		// multiply 2 ffts
		for(int i=0; i<_row; i++)
		{
			for (int j = 0; j < _col; j++) {
				int i1 = (i ? (_row - i) : i);
				int j1 = (j ? (_col - j) : j);
				base ans1 = (v1[i][j] + conj(v1[i1][j1])) * base(0.5, 0);
				base ans2 = (v1[i][j] - conj(v1[i1][j1])) * base(0, -0.5);
				base ans3 = (v2[i][j] + conj(v2[i1][j1])) * base(0.5, 0);
				base ans4 = (v2[i][j] - conj(v2[i1][j1])) * base(0, -0.5);
				r1[i][j] = (ans1 * ans3) + (ans1 * ans4) * base(0, 1);
				r2[i][j] = (ans2 * ans3) + (ans2 * ans4) * base(0, 1);
			}
		}

		fft2D(r1, 1);
		fft2D(r2, 1);

		_col = _colv + _colw - 1;
		_row = v.size() + w.size() - 1;
		
		vector<vector<ll>> ret(_row);
		for(int i=0; i<_row; i++)
		{
			ret[i].resize(_col);
			for (int j = 0; j < _col; j++) {
				ll av = (ll)round(r1[i][j].real());
				ll bv = (ll)round(r1[i][j].imag()) + (ll)round(r2[i][j].real());
				ll cv = (ll)round(r2[i][j].imag());
				av %= mod, bv %= mod, cv %= mod;
				ret[i][j] = (av << 30) + (bv << 15) + cv;
				ret[i][j] = (ret[i][j] % mod + mod) % mod;
			}
		}
		return ret;
	}
}


char table[405][405], pattern[405][405];
base ans[405][405];

ld value(char c) {
	return 2 * PI * (c - 'a') / 26.0;
}

bool isEqual(base b, int x) {
	return (abs(b.imag()) < eps && fabs(b.real() - x) < eps);
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	int cnt = 0;
	cin >> n >> m;

	FOR (i, 0, n - 1) {
		FOR (j, 0, m - 1) {
			cin >> table[i][j];
		}
	}

	int r, c;
	cin >> r >> c;
	FOR (i, 0, r - 1) {
		FOR (j, 0, c - 1) {
			cin >> pattern[i][j];
			if (pattern[i][j] != '?') cnt++;
		}
	} 

	vector<vector<base>> A(n - 1 + r), B(r), C;
	FOR (i, 0, n - 2 + r) {
		A[i].resize(m - 1 + c);
		FOR (j, 0, m - 2 + c) {
			double u = 2 * PI * (table[i % n][j % m] - 'a') / 26.0;
			A[i][j] = base(cos(u), sin(u));
		}
	}

	FOR (i, 0, r - 1) {
		B[r - 1 - i].resize(c);
		FOR (j, 0, c - 1) {
			if (pattern[i][j] != '?') {
				double u = value(pattern[i][j]);
				B[r - 1 - i][c - 1 - j] = base(cos(u), -sin(u));
			}
		}
	}
	C = FFT_2D::multiply(A, B);

	for (int i = 0; i < n && i + r - 1 < C.size(); i++) {
		for (int j = 0; j < m && j + c - 1 < C[i + r - 1].size(); j++) {
			if (isEqual(C[i + r - 1][j + c - 1], cnt)) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}

	return 0;
}