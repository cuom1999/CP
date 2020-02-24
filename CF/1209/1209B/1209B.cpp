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

int a[105][50005], m[50005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int res = 0;
	FOR (i, 1, n) {
		int aa, b;
		cin >> aa >> b;
		a[i][0] = s[i - 1] - '0';
		m[0] += a[i][0];
		FOR (j, 1, 50000) {
			if (j < b) {
				a[i][j] = a[i][0];
			}
			else {
				int u = j - b;
				if ((u / aa) % 2) {
					a[i][j] = a[i][0];
				}
				else {
					a[i][j] = a[i][0] ^ 1;
				}
			}
			m[j] += a[i][j];

		}
	}

	FOR (i, 0, 50000) res = max(res, m[i]);

	cout << res << endl;


	return 0;
}