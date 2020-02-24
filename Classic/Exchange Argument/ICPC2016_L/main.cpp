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

II a[1000005];
int n;
	
bool solve(ll x) {
	FOR (i, 1, n) {
		x -= a[i].first;
		if (x < 0) return 0;
		x += a[i].second;
	}
	return 1;
}

bool isGood(II x) {
	return x.second >= x.first;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	while (cin >> n) {
		FOR (i, 1, n) {
			cin >> a[i].first >> a[i].second;
		}
		sort(a + 1, a + n + 1, [] (II x, II y) {
			if (isGood(x) && !isGood(y)) return true;
			if (!isGood(x) && isGood(y)) return false;

			if (isGood(x) && isGood(y)) {
				return x.first < y.first;
			}
			return x.second > y.second;
		});

		ll L = 0, R = 1e16;
		while (L < R) {
			ll mid = (L + R) / 2;
			if (solve(mid)) {
				R = mid;
			}
			else {
				L = mid + 1;
			}
		}

		cout << L << endl;
	}


	return 0;
}