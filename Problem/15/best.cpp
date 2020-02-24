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

ll N, s;
ll m[100005], n[100005];

II solve(ll x) {
	ll cnt = 0;
	ll res = 0;
	bool isInf = 0;
	FOR (i, 1, N) {
		if (x >= m[i] + n[i]) {
			ll c;
			if (m[i]) c = (x - m[i] - n[i]) / (2 * m[i]) + 1;
			else {
				isInf = 1;
				continue;
			}
			cnt += c;
			res += c * c * m[i] + n[i] * c - x * c;  
		}
	}
	if (isInf) cnt += 1e17;
	return {cnt, res};
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> s;

	FOR (i, 1, N) {
		ld x, y;
		cin >> x >> y;
		m[i] = round(x * 100);
		n[i] = round(y * 100);
	}
	ll L = 0, R = 1e12;

	while (L < R) {
		ll mid = (L + R) / 2;
		if (solve(mid).first >= s) {
			R = mid;
		}
		else {
			L = mid + 1;
		}
	}

	auto q = solve(L);
	
	ll res = q.second + s * L;
	cout << fixed << setprecision(2) << res / 100.0 << endl; 
	return 0;
}