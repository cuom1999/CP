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
typedef pair < ll, ll > II;

ll x[500005];
const ll K = 1e18;

struct BigInt {
	ll x, y; 
	BigInt(ll x, ll y): x(x), y(y){}
	bool operator < (BigInt a) {
		if (x == a.x) return y < a.y;
		return x < a.x;
	}
	bool operator == (BigInt a) {
		return (x == a.x) && y == a.y;
	}
};

BigInt mul(ll a, ll b) {
	ll k = 1e9;
	ll a1 = a / k;
	ll a2 = a % k;
	ll b1 = b / k;
	ll b2 = b % k;

	ll x = a1 * b1;
	ll y = a1 * b2 + a2 * b1;
	x += y / k;
	y %= k;
	y = y * k;
	y = y + a2 * b2;

	x += y / K;
	y %= K;
	return {x, y};
}

BigInt mul(BigInt a, BigInt b) {
	// cout << a.x << " " << a.y << " K" << endl;
	ll x = a.x * b.y + a.y * b.x;
	BigInt y = mul(a.y, b.y);
	return {x + y.x, y.y};
}

struct Fraction {
	ll x, y;

	Fraction(ll x, ll y): x(x), y(y){} 

	Fraction operator - (Fraction a) {
		return {abs(x * a.y - y * a.x), y * a.y};
	}
	bool operator < (Fraction a) {
		BigInt p = mul(BigInt(0, x), BigInt(0, a.y));
		BigInt q = mul(BigInt(0, y), BigInt(0, a.x));
		return p < q;
	}
	bool operator == (Fraction a) {
		BigInt p = mul(BigInt(0, x), BigInt(0, a.y));
		BigInt q = mul(BigInt(0, y), BigInt(0, a.x));
		return p == q;
	}

	void print() {
		cout << x << "/" << y << endl;
	}
};

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int n;
		ld r;
		cin >> n >> r;

		ll a = round(r * 1000000);
		ll b = 1000000;

		ll g = __gcd(a, b);
		a /= g;
		b /= g;

		string s;
		cin >> s;

		vector<II> v;
		v.pb({0, 0});

		x[1] = (s[0] == '1');

		FOR (i, 1, n - 1) {
			x[i + 1] = x[i] + (s[i] == '1');
		}		

		FOR (i, 1, n) {
			v.pb({b * x[i] - a * i, i});
		}

		sort(all(v));

		Fraction minVal = {(ll)1e17, 1};
		int index = -1;

		for (int i = 0; i + 1 < v.size(); i++) {
			int p = v[i].second;
			int q = v[i + 1].second;

			if (p > q) swap(p, q);
			Fraction u = {x[q] - x[p], q - p};
			u = u - Fraction(a, b);

			// cout << p << " " << q << " ";
			// u.print();
			// minVal.print();

			if (u < minVal) {
				minVal = u;
				index = p;
			}
			else if (u == minVal) {
				index = min(index, p);
			}
			// return 0;
		}
		cout << index << endl; 
	}

	return 0;
}