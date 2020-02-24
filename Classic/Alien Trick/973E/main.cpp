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

typedef pair < int, ld > ID;
typedef pair < ll, ll > pll;

int n, a, b;
ld p[2005], u[2005];
ld d[2005][2005];
int cnt[2005][2005];

// each u[i] is penaltied x
ID solve(ld x) {
	FOR (i, 1, n) {
		FOR (j, 0, a) {
			d[i][j] = d[i - 1][j];
			cnt[i][j] = cnt[i - 1][j];

			if (d[i - 1][j] + u[i] - x > d[i][j]) {
				d[i][j] = d[i - 1][j] + u[i] - x;
				cnt[i][j] = cnt[i - 1][j] + 1;
			}

			if (j && d[i - 1][j - 1] + p[i] >= d[i][j]) {
				d[i][j] = d[i - 1][j - 1] + p[i];
				cnt[i][j] = cnt[i - 1][j - 1];
			}

			if (j && d[i - 1][j - 1] - p[i] * u[i] + p[i] + u[i] - x > d[i][j]) {
				d[i][j] = d[i - 1][j - 1] - p[i] * u[i] + p[i] + u[i] - x;
				cnt[i][j] = cnt[i - 1][j - 1] + 1;
			}
			// cout << i << " " << j << " " << d[i][j] << endl;
		}
	}
	return {cnt[n][a], d[n][a]};
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n >> a >> b;
	FOR (i, 1, n) {
		cin >> p[i];
	}

	FOR (i, 1, n) {
		cin >> u[i];
	}

	ld L = 0, R = 10;

	while (R - L > eps) {
		ld mid = (L + R) / 2.0;
		if (solve(mid).first > b) {
			L = mid;
		}
		else {
			R = mid;
		}
	}

	cout << fixed << setprecision(8) << solve(L).second + L * b << endl;
	return 0;
}