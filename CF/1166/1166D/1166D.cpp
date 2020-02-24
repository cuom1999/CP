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



int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int q;
	cin >> q;

	FOR (z, 1, q) {
		ll a, b, m;
		cin >> a >> b >> m;

		if (a == b) {
			cout << 1 << " " << a << endl;
			continue;
		}

		ll L = a + 1, R = a + m;

		bool isGood = 0;

		FOR (k, 2, 52) {
			if (L > b) break;
			if (L <= b && b <= R) {

				ll u = b - L;

				ll r[55];
				r[1] = 0;

				FOR (i, 2, k - 1) {
					r[i] = min(m - 1, u / (1LL << (k - i - 1)));
					u -= r[i] * (1LL << (k - i - 1));
				}
				r[k] = u;

				vector<ll> res;
				res.pb(a);
				ll s = a;

				FOR (i, 2, k) {
					ll cur = s + r[i] + 1;
					res.pb(cur);
					s += cur;
				}

				cout << res.size() << " ";
				for (auto i: res) cout << i << " ";
				cout << endl;
				isGood = 1;
				break;

			}
			L *= 2;
			R *= 2;
		}
		if (!isGood) {
			cout << -1 << endl;
		}
	}

	return 0;
}