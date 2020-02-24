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

ll d[105][105];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	ll a[100005];

	d[0][0] = 0;
	FOR (i, 1, n) cin >> a[i];
	FOR (i, 1, n) d[i][0] = -1e18;

	FOR (i, 1, n) {
		FOR (j, 1, k) {
			d[i][j] = d[i - 1][j - 1] + a[i] * 1ll * j;
			if (i - 1 >= j) {
				d[i][j] = max(d[i][j], d[i - 1][j] + a[i] * 1ll * j);
			} 
		}
	}

	cout << d[n][k] << endl;

	return 0;
}