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
	string s;
	cin >> s;
	int n = s.length();
	s = '#' + s;
	ll res = 0;
	FOR (l, 1, n) {
		FOR (r, l + 1, n) {
			bool isTrue = 0;
			FOR (x, l, r) {
				FOR (k, 1, (r - x) / 2) {
					if (s[x] == s[x + k] && s[x] == s[x + 2 * k]) {
						isTrue = 1;
						break;
					}
				}
				if (isTrue) break;
			}
			res += isTrue;
			if (isTrue) cout << l << " " << r << endl;
		}
	}

	cout << res << endl;


	return 0;
}