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

set<II> s;
II a[305];


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";

		s.clear();
		int n;
		cin >> n;

		FOR (i, 1, n) {
			cin >> a[i].first >> a[i].second;
		}

		sort(a + 1, a + n + 1);

		FOR (i, 1, n) {
			FOR (j, i + 1, n) {
				if (a[i].first == a[j].first) continue;
				if (a[i].second <= a[j].second) continue;
				ll u = a[i].second - a[j].second;
				ll v = a[j].first - a[i].first;
				ll g = __gcd(u, v);

				u /= g;
				v /= g;
				s.insert({u, v});
			}
		}

		cout << s.size() + 1 << endl;
	}



	return 0;
}