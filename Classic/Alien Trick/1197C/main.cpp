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

// add x to every sub array

const int MAXN = 300005;

int n, k;
ll a[MAXN];

II solve(ll x) {
	ll d[MAXN], e[MAXN];
	int cnt[MAXN], smallestIndex[MAXN];

	FOR (i, 0, n) {
		d[i] = 0;
		e[i] = 0;
		cnt[i] = 0;
		smallestIndex[i] = 0;
	}

	e[0] = -a[1];
	smallestIndex[0] = 0;

	FOR (i, 1, n) {
		d[i] = e[i - 1] + a[i] + x;
		cnt[i] = cnt[smallestIndex[i - 1]] + 1;
		if (i < n) {
			if (d[i] - a[i + 1] < e[i - 1]) {
				e[i] = d[i] - a[i + 1];
				smallestIndex[i] = i;
			}
			else {
				e[i] = e[i - 1];
				smallestIndex[i] = smallestIndex[i - 1];
			}
		}		
		// cout << i << " " << d[i] << endl;
	}

	return {cnt[n], d[n]};
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;
	FOR (i, 1, n) cin >> a[i];

	ll lower = 0, upper = 2 * INF;
	while (lower < upper) {
		int mid = (lower + upper) / 2;
		if (solve(mid).first <= k) {
			upper = mid;
		}
		else {
			lower = mid + 1;
		}
	}

	II res = solve(lower);
	cout << res.second - k * lower << endl;
	return 0;
}