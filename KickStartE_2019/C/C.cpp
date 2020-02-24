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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

bool isComp[100005];
int a[100005];

vector<II> v[100005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	isComp[1] = 1;
	FOR (i, 2, 100000) {
		if (!isComp[i]) {
			FOR (j, 2, 100000 / i) {
				isComp[i * j] = 1; 
			}
		}
	}
	int t;
	cin >> t;

	FOR (z, 1, t) {
		int l, r;
		cin >> l >> r;
		FOR (i, l, r) a[i - l] = i;

		FOR (i, 2, 100000) {
			if (!isComp[i]) {
				int u = (l - 1) / i + 1;
				for (int j = u * i; j <= r; j += i) {
					int cnt = 0;
					while(a[j - l] % i == 0) {
						a[j - l] /= i;
						cnt++;
					}
					if (cnt) v[j - l].pb({i, cnt});
				}
			}
		}

		FOR (i, l, r) {
			if (a[i - l] > 1) {
				v[i - l].pb({a[i - l], 1});
			}
		}

		int res = 0;
		FOR (i, l, r) {
			// cout << i << ": ";
			// for (auto j: v[i - l]) {
			// 	cout << "(" << j.first << " " << j.second << ") ";
			// }
			// cout << endl;
			ll oddDiv = 1;
			int pw2 = 0;
			for (auto j: v[i - l]) {
				if (j.first != 2) {
					oddDiv *= (j.second + 1);
				}
				else {
					pw2 = j.second;
				}
			}

			ll evenDiv = oddDiv * pw2;
			if (abs(evenDiv - oddDiv) <= 2) {
				res++;
			}
			v[i - l].clear();
		}
		cout << "Case #" << z << ": " << res << "\n";
	}


	return 0;
}