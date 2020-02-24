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

ll a[200005];
int n, k;

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	FOR (z, 1, t) {
		cin >> n >> k;

		FOR (i, 1, n) cin >> a[i];
		ll res = 1e18;
		ll x = 0;
		FOR (i, 1, n - k) {
			ll x1 = (a[i] + a[k + i]) / 2;
			if (a[k + i] - x1 < res) {
				res = a[k + i] - x1;
				x = x1;
			}
		}
		cout << x << endl;
	}
	return 0;
}