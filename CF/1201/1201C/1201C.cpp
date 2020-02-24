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

ll a[200005];
int n;
ll k;

bool solve(ll x) {
	int mid = (n + 1) / 2;
	ll s = 0;
	FOR (i, mid, n) {
		if (a[i] < x) {
			s += x - a[i];
			if (s > k) return 0;
		}
	}
	return (s <= k);
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);


	cin >> n >> k;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	ll L = 0, R = 1e18;
	while (L < R) {
		ll mid = (L + R + 1) / 2;
		if (solve(mid)) {
			L = mid;
		}
		else {
			R = mid - 1;
		}
	}

	cout << L << endl;



	return 0;
}