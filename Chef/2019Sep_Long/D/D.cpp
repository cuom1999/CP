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
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		ll n, m;
		cin >> n >> m;

		if (m < n - 1 || m > n * (n - 1) / 2 + n) {
			cout << -1 << "\n";
		}
		else {
			if (n == 1) {
				if (m == 0) cout << "0\n";
				else cout << "1\n";
			}
			else if (n == 2) {
				if (m == 1) cout << "1\n";
				else cout << "2\n";
			}
			else {
				m -= (n - 1);
				if (m == 0) {
					cout << 2 << "\n";
				}
				else {
					if (m <= 2) {
						cout << 2 << "\n";
					}
					else if (m <= n) {
						cout << "3\n";
					}
					else {
						m -= n;
						m += (n - 1);
						cout << (2 * m - 1) / n + 2 << "\n";
					}
				}
			}
		}
	}

	return 0;
}