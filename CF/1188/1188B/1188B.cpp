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

int a[300005];
unordered_map<int, vector<int>> v;

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, p, k;
	cin >> n >> p >> k;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	int cnt = 0;

	ll res = 0;

	FOR (i, 1, n + 1) {
		if (i == 1 || i == n + 1 || a[i] != a[i - 1]) {
			if (i > 1) {
				ll val = (a[i - 1] * 1ll * a[i - 1]) % p;
				val = val * val % p;
				val = (val - k * 1ll * a[i - 1]) % p;
				val = (val + p) % p;
				v[val].pb(cnt);

				val = 2ll * a[i - 1] % p;
				val = val * (2ll * a[i - 1] * a[i - 1] % p) % p;
				if (val % p == k) {
					res += cnt * 1ll * (cnt - 1) / 2;
				}
			}
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	// cout << res << endl;

	for (auto i: v) {
		for (int j = 0; j < i.second.size(); j++) {
			for (int k = j + 1; k < i.second.size(); k++) {
				res += i.second[j] * 1ll * i.second[k];
			}
		}
	}

	cout << res << endl;


	return 0;
}