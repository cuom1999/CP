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

const ll K = 998244353 ;

int a[1005], n, k;
ll d[1005][1005];

ll solve(int x) {
	
	FOR (j, 1, k) {
		int last = 0;
		ll s = 0;
		FOR (i, 1, n) {
			if (j == 1) {
				d[i][j] = 1;
			}
			else {
				d[i][j] = d[i - 1][j];		
				while (last + 1 <= n && a[i] - a[last + 1] >= x) {
					last++;
					d[i][j] = (d[i][j] + d[last][j - 1]) % K;
				}
			}
		}
	}
	ll res = 0;

	FOR (i, 1, n) {
		res = (res + d[i][k]) % K;
	}
	return res;
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;
	FOR (i, 1, n) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	ll res = 0;

	FOR (i, 1, a[n] / (k - 1)) {
		res = (res + solve(i)) % K;
		// cout << solve(i) << " ";
	}

	cout << res << endl;
	return 0;
}