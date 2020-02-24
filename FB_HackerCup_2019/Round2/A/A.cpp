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

int x[3], y[3];

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;


	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";
		int n, m, k;
		cin >> n >> m >> k;

		int a, b;
		cin >> a >> b;

		FOR (i, 1, k) {
			cin >> x[i] >> y[i];
		}

		if (k == 1) {
			cout << "N\n";
		}
		else {
			set<int> s;
			s.insert((a + b) % 2);
			FOR (i, 1, k) s.insert((x[i] + y[i]) % 2);

			if (s.size() == 1) {
				cout << "Y\n";
			}
			else {
				cout << "N\n";
			}
		}

	}

	return 0;
}