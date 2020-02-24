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

const ll K = 1e9 + 7;

inline int min(int a, int b) {
	if (a < b) return a;
	return b;
}

// = sum (b^2 / i) from 1 to a
int calc(int b, int a, int c) {
	int x = b * b;
	a = min(a, x);

	int res = 0;

	if (a <= b) {
		FOR (i, 1, a) {
			res = (res + min(x / i, c));
		}
		return res % K;
	}
	FOR (i, 1, b) {
		res += min(x / i, c);
	}

	FORD (i, b - 1, 1) {
		if (x / i < a) {
			res += min(i, c) * (x / i - x / (i + 1));
		}
		else {
			res += min(i, c) * (a - x / (i + 1));
			break;
		}
	}
	return res % K;
}



int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		int a, b, c;
		cin >> a >> b >> c;
		
		a--;
		c--;

		int res = 0;
		FOR (i, 1, b) {
			// cout << i << endl;
			res += a * 1LL * c % K - calc(i, a, c);
			res %= K;
			// cout << i << " " << a * c - calc(i, a, c) << endl;
		}

		cout << (res % K + K) % K << "\n";
	}


	return 0;
}