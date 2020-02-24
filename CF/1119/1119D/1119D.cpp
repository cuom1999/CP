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

ll s[100005];
vector<ll> v;
ll preSum[100005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;

    FOR (i, 1, n) {
    	cin >> s[i];
    }
	
	sort(s + 1, s + n + 1);

	ll res = s[n] - s[1];

	FOR (i, 1, n - 1) {
		v.pb(s[i + 1] - s[i]);
	}

	sort(all(v));
	reverse(all(v));
	// for (auto i: v) cout << i << " "; cout << endl;
	if (n > 1) {
		preSum[0] = v[0];

		for (int i = 1; i < v.size(); i++) {
			preSum[i] = preSum[i - 1] + v[i];
		}
	}

	int q;
	cin >> q;

	FOR (z, 1, q) {
		ll l, r;
		cin >> l >> r;
		ll L = r - l + 1;

		ll ans = res + L;

		int lower = -1, upper = n - 2;
		while (lower < upper) {
			int mid = (lower + upper + 1) / 2;
			if (v[mid] <= L) {
				upper = mid - 1;
			}
			else {
				lower = mid;
			}
		}
		// cout << lower << " " << preSum[lower ] << endl;

	
		if (lower >= 0) ans -= preSum[lower] - (lower + 1) * 1ll * L;
		cout << ans << " ";
	}

    return 0;
}