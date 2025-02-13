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

ll h[2][100005], d[2][100005], m[2][100005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) cin >> h[0][i];
	FOR (i, 1, n) cin >> h[1][i];

	FOR (i, 1, n) {
		FOR (j, 0, 1) {
			d[j][i] = m[j ^ 1][i - 1] + h[j][i];
			m[j][i] = max(m[j][i - 1], d[j][i]);
		}
	}

	cout << max(m[0][n], m[1][n]);

	return 0;
}