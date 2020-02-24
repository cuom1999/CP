//http://www.usaco.org/index.php?page=viewproblem2&cpid=697
#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-12)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ld > ID;

ll n, k;
ll a[100005];

ll calc(ll c) {
	ll u = (sqrt(1 + 4 * c) - 1) / 2.0;

	FOR (i, max(1LL, u - 2), u + 2) {
		if (i * i + i > c) return max(1LL, i);
	}
	return 1;
}

// each cow costs x 
ID solve(ld x) {
	ll cnt = 0;
	ld res = 0;
	FOR (i, 1, n) {
		ll u = a[i] / x;
		ll c = calc(u);
		cnt += c;
		res += (ld) a[i] / c;
	}

	return {cnt, res};
}

int main()
{//IN;
	freopen("tallbarn.in", "r", stdin);
	freopen("tallbarn.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;
	FOR (i, 1, n) {
		cin >> a[i];
	}

	// for (ld i = 0.1; i <= 2; i += 0.05) {
	// 	cout << solve(i).first << " ";
	// }
	// return 0;
	ld L = 1e-8, R = 1e15;
	while (R - L > eps) {
		ld mid = (L + R) / 2;
		if (solve(mid).first <= k) {
			R = mid;
		}
		else {
			L = mid;
		}
	}

	auto q = solve(L);
	cout << fixed << setprecision(0) << q.second - (k - q.first) * L << endl; 

	return 0;
}